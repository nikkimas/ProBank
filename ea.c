#include "global_vars.h"

char readFile(char path)
{
    FILE *file;
    char retV;
    int c;
    file = fopen(path, "r");
    if(file == NULL)
    {
        printf("ERROR\t\t FILE NOT FOUND EXCEPTION\n");
        return;
    }
    while(c=fgetc(file))
    {
        if(c = 'EOF')
        {
            ungetc(c, file);
            return NULL;
        }
        retV += c;
    }
    fclose(file);
    return retV;
}

void writeFile(char path, char content)
{
    FILE *file;
    int c;
    file = fopen(path, "w");
    if(file == NULL)
    {
        fileNotFoundException(path);
        return;
    }
    fputs(file, content);
    fclose(file);
}
