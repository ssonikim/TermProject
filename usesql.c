
#include <stdlib.h>
#include <stdio.h>
#include "/usr/include/mysql/mysql.h"

int main(int argc, char* agrv[])
{
    MYSQL conn_ptr;        //connect DB
    MYSQL_RES* res;        //result
    MYSQL_ROW row;        
    int fields;
    int cnt;            

    mysql_init(&conn_ptr);    //mssql initialize    
    
    //sql object, host, user, passwd, db, port, socket, flag
    //connect to server
    //return pointer at success, return NULL at failed
    if(!mysql_real_connect(&conn_ptr, "%", "do", "ywa12369", "kwando", 0, NULL, 0))
    {
        printf("%s\n", mysql_error(&conn_ptr));
        exit(1);
    }

    //return 0 al success
    if(mysql_query(&conn_ptr, "select * from something")) //table name
    {
        printf("%s\n", mysql_error(&conn_ptr));
        exit(1);
    }
        
        //receive result value at once
        res = mysql_store_result(&conn_ptr);

        //get fields numbers
        fields = mysql_num_fields(res);
        
        //get 1 ROW in result, field is array type
        while((row = mysql_fetch_row(res)))
        {
            for(cnt = 0; cnt<fields; ++cnt)
                printf("%s  ", row[cnt]);

            printf("\n");
        }

        mysql_free_result(res);
        mysql_close(&conn_ptr);    //close server, memory free

    return 0;
}
