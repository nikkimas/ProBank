#include "global_vars.h"
#include "mysql_bank.h"

char select_mysql(char value)
{
    MYSQL_ROW row;
    int i;
    char *retV;
    if(mysql_query(my, value))
    {
        finish_with_error(my);
    }
    MYSQL_RES *result = mysql_store_result(my);
    if(result == NULL)
    {
        finish_with_error(my);
    }
    while((row = mysql_fetch_row(result)) != NULL)
    {
        for(i = 0; i < mysql_num_fields(result); i++)
        {
            *retV += row[i];
        }
    }
}

void insert_mysql(char value)
{
    mysql_query(my, value);
}

int connect_mysql()
{
    MYSQL *my;
    my = mysql_init(NULL);
    if(my == NULL)
    {
        mysql_exception("init");
    }
    if(mysql_real_connect(my, HOST, USERNAME, PASSWORT, DBNAME, PORT, SOCKET, FLAG) == NULL)
    {
        fprintf(stderr, "Fehler bei der Verbindung mit dem MySQL Datenbank Server: %u (%s)\n", mysql_errno(my), mysql_error(my));
        return 0;
    }
    else
    {
        printf("Verbindung mit MySQL hergestellt\n");
        return 1;
    }
}

void close_mysql()
{
    mysql_close(my);
}
