#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[256];
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        while (fgets(line, sizeof(line), fp)) {
            char c = 0;
            int i_oldStr = 0;
            int i_newStr = 0;
            char newStr[256];
            do {
                c = line[i_oldStr];
                if (c == '\\' 
                        && line[i_oldStr + 1] == '0' 
                        && line[i_oldStr + 2] == '3' 
                        && line[i_oldStr + 3] == '3') {
                    newStr[i_newStr] = '\033';
                    i_oldStr += 3;
                } else {
                    newStr[i_newStr] = c;
                }
                i_newStr++;
                i_oldStr++;
            } while ( c != 0 );
            printf("%s", newStr);
        }
        fclose(fp);
    } else {
        printf("You goofed\n");
    }
    return 0;
}
