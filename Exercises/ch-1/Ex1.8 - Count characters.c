#include <stdio.h>
#include <string.h>

const int TRUE = 1;
const int FALSE = 0;

//  if you modify characters here, be sure to update 
//      spchar_enum
//  &   the switch in get_stats
char spchar_array[] = { '\0', ' ', '\t', '\n' };

enum spchar_enum {
    EOL,
    SPACE_CHAR,
    TAB,
    NEWLINE
} special_chars;

int find_spIndex (char input) {
    int spchar_total   =   *(&spchar_array + 1) - spchar_array;
    int found           =   FALSE;
    for (int index = 0; 
            index <= spchar_total; 
            index++) {
        if (spchar_array[index] == input) {
            found = TRUE;
            return index;
        }
    }
    return -1;
}

struct word_stats {
    int chars;
    int spaces;
    int tabs;
    int newlines;
} stats;

void get_stats (char* string) {
    int char_count  =   0;
    int space_count =   0;
    int tab_count   =   0;
    int line_count  =   0;

    //  loop until end of line '\0'
    for (int index = 0; string[index] != spchar_array[EOL]; index++) {
        int sp_index = find_spIndex(string[index]);

        if ( sp_index > -1 && spchar_array[sp_index] == string[index] ) {
            switch (sp_index)
            {
            case SPACE_CHAR:
                space_count++;
                char_count++;
                break;
            
            case TAB:
                tab_count++;
                char_count++;
                break;

            case NEWLINE:
                line_count++;
                char_count++;
                break;
            }            
        } else {
            char_count++;
        } 
    }

    //  save the values to stats
    stats.chars     =   char_count;
    stats.spaces    =   space_count;
    stats.tabs      =   tab_count;
    stats.newlines    =   line_count;
}

int main(int argc, char *argv[] ) {
    char   user_input[100]   =   " ";

    //  concat all 
    int     concat_index    =   1;
    do
    {
        strcat_s(user_input, 150, argv[concat_index]);
    } while (concat_index++ < (argc - 1));  // if the index is less than the arg count
    
    get_stats(user_input);

    //Debug
    //printf("DEBUG LINE: %s is %d characters long with %d spaces, %d tabs and %d lines.\n", user_input, stats.chars, 
    //                                                                stats.spaces, stats.tabs, stats.newlines);
    
    //result
    printf("%s,%d,%d,%d,%d", user_input, stats.chars, stats.spaces, stats.tabs, stats.newlines);

    //ALWAYS RETURN
    return 0;
}