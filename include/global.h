#ifndef GLOBAL_H
#define GLOBAL_H

extern sqlite3 *db;
extern int rc;
extern const char *sql;
extern char *zErr;
extern int user_mywallet;
extern char lastwallet[20];
extern int reset_flag;
#endif
