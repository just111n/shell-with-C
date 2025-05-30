#include "system_program.h"

/**
   Print the contents of the file to stdout
 */
int shellDisplayFile_code(char **args)
{
    FILE *fp;
    char buf[1000];

    if (args[1] != NULL)
    {
        fp = fopen(args[1], "r");
    }
    else
    {
        printf("Please supply a file name\n");
        return 1;
    }

    if (!fp)
    {
        printf("CShell: File doesn't exist.\n");
        return 1;
    }

    while (fgets(buf, 1000, fp) != NULL)
        printf("%s", buf);

    printf("\n");

    fclose(fp);
    return 1;
}

int main(int argc, char **args)
{
    return shellDisplayFile_code(args);
}