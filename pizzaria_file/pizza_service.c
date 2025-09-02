#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza_repo.h"
#include "pizza_service.h"

extern T_PIZZA *listapizza;
extern int size_listapizza;

void loadPizzaFile(char * filename){
    T_PIZZA pTmp;
    FILE* pFile;
    char buffer[1023];
    // abre o arquivo para leitura e processamento 
    // caso pFile = null entao retorna falha
	if (!(pFile = fopen(filename,"r")))
	{
        return;
    }
    int iRegistros = 0;

	// processamento dos registros do arquivo
	while (fgets(buffer, sizeof(buffer), pFile))
	{
		if(buffer[0] == 'D' || buffer[0] == '\0' || buffer[0] == '\n' || buffer[0] == '\r'){
			continue;
		}
		printf("Lendo pizza %d : %s \n",iRegistros,buffer);
        stringToPizza(buffer, &pTmp);
		printf("Pizza carregada\n");
		addPizza(pTmp);
		
        iRegistros++;
    }
	printf("Foram carregados %d registros",iRegistros);
	// fecha o arquivo de entrada
	if (pFile != NULL)
	{
		fclose(pFile);
	}

    return;
};

void savePizzaFile(char * filename){
	FILE* pFile = NULL;
    char buffer[255];
    // abre o arquivo para leitura e processamento 
    // caso pFile = null entao retorna falha
	if (!(pFile = fopen(filename,"w")))
	{
        return;
    }
    int iRegistros = 0;

	for(int i=0; i <size_listapizza; i++ ){
		char exemplo[255] = "";
        pizzaToString(&listapizza[i],exemplo);
		fprintf(pFile, "%s\n",exemplo);
		iRegistros++;
    }
	printf("Foram salvados %d registros\n",iRegistros);
	if (pFile != NULL)
	{
		fclose(pFile);
	}
    return;
};