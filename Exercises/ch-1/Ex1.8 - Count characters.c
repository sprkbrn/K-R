#include <stdio.h>
#include <string.h>

const char EOL = '\0';

struct word_stats {
    int chars;
    int spaces;
} stats;

void check_word (char* word) {
    int char_count  =   0;
    int space_count =   0;
    
    //  loop until end of line '\0'
    for (int index = 0; word[index] != EOL; index++) {
        
        //  count spaces
        if(word[index] == ' ') {
            space_count++;
        }

        //  count chars
        char_count++;
    }

    //  save the values to stats
    stats.chars = char_count;
    stats.spaces = space_count;
}

int main(int argc, char *argv[] ) {
    char   user_input[50]   =   "";

    //  concat all 
    int     concat_index    =   1;
    do
    {
        strcat_s(user_input, 50, argv[concat_index]);
    } while (concat_index++ < (argc - 1));  // if the index is less than the arg count
    
    check_word(user_input);

    //Debug
    printf("DEBUG LINE: %s is %d characters long with %d spaces.", user_input, stats.chars, stats.spaces);
    
    //result
    printf("%d", stats.chars);

    //ALWAYS RETURN
    return 0;
}