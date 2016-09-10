/*
    Hier werden alle möglichen Auftretenen Fehler abgefangen und mit einem einfach printf gehandhabt
*/

void mysql_exception(char type)
{
    printf(type);
}

void fileNotFoundException(char file)
{
    printf("ERROR\t\tFILE NOT FOUND EXCEPTION AT FILE %s", file);
}
