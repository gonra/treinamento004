#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include "pizza_repo.h"

T_PIZZA * listapizza;

int size_listapizza=0;

sqlite3 *db;

// Callback function for SELECT queries
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return(0);
}


void addPizza(T_PIZZA p){
   listapizza[size_listapizza].id = p.id;
   listapizza[size_listapizza].preco = p.preco;
   strcpy(listapizza[size_listapizza].nome, p.nome);
   size_listapizza++;
   return;
}

void getPizza(T_PIZZA *p, int id){
    if (id < size_listapizza) {
        (*p).id = listapizza[id].id;
        (*p).preco = listapizza[id].preco;
        strcpy((*p).nome , listapizza[id].nome);
    }
    return;
}

void cleanPizza(){
    for(int i=0; i <size_listapizza; i++ ){
        destroyPizza(&listapizza[i]);
    }
    size_listapizza = 0;
    return;
}

int initPizzaDB(){
    char *zErrMsg = 0;
    int rc;
    char *sql;
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    // Create SQL statement for creating a table
    sql = "CREATE TABLE IF NOT EXISTS PIZZA(" \
          "ID INT PRIMARY KEY NOT NULL," \
          "NOME CHAR(50)," \
          "PRECO INT );";

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    return(0);
}

int closePizzaDB(){
    sqlite3_close(db);
    return(0);
}

int insertPizzaDB(T_PIZZA *p){
    char retorno[256];
    char *zErrMsg = 0;
    int rc;
    char *sql;

    sprintf(retorno,"INSERT INTO PIZZA (ID, NOME, PRECO) VALUES ( %d, '%s', %d );\0",
        p->id, p->nome, p->preco);
    strcpy(sql,retorno);
    printf("executando : (%s)\n", sql);

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }
    return(0);
}

int loadPizzaById(T_PIZZA *p, int id){
    return 0;
}
