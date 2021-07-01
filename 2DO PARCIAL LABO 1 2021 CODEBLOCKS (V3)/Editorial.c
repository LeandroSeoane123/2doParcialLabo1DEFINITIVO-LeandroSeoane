#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Editorial.h"

eEditorial* edit_nueva()
{
    eEditorial* pEditLocal;

    pEditLocal = (eEditorial*)malloc(sizeof(eEditorial));

    return pEditLocal;
}

eEditorial* edit_nuevaParam(char* idStr, char* descripcionStr)
{
    eEditorial* pEditLocal = NULL;
    int id;
    int retornoSet;

    id = atoi(idStr);

    if(atoi(idStr))
    {
        pEditLocal = edit_nueva();

        if(pEditLocal != NULL)
        {
            retornoSet = edit_setId(pEditLocal, id);
            if(retornoSet == 1)
            {
                retornoSet = edit_setDesc(pEditLocal, descripcionStr);
            }
        }
    }

    if(retornoSet != 1)
    {
        pEditLocal = NULL;
    }

    return pEditLocal;
}

int asignarIdEditorial(char* desc, char* idStr)
{
    int retorno = 0;
    int id;
    int retornoCmp;

    retornoCmp = strcmp(desc, "Planeta");
    if(retornoCmp == 0)
    {
        id = 1;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    retornoCmp = strcmp(desc, "SIGLO XXI EDITORES");
    if(retornoCmp == 0)
    {
        id = 2;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    retornoCmp = strcmp(desc, "Pearson");
    if(retornoCmp == 0)
    {
        id = 3;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    retornoCmp = strcmp(desc, "Minotauro");
    if(retornoCmp == 0)
    {
        id = 4;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    retornoCmp = strcmp(desc, "SALAMANDRA");
    if(retornoCmp == 0)
    {
        id = 5;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    retornoCmp = strcmp(desc, "PENGUIN BOOKS");
    if(retornoCmp == 0)
    {
        id = 6;
        sprintf(idStr, "%d", id);
        retorno = 1;
    }

    return retorno;
}

int edit_getId(eEditorial* this, int* id)
{
    int getteo = 0;

    if(this != NULL)
    {
        *id = this->id;
        getteo = 1;
    }

    return getteo;
}

int edit_getDesc(eEditorial* this, char* desc)
{
    int getteo = 0;

    if(this != NULL)
    {
        strcpy(desc, this->descripcion);
        getteo = 1;
    }

    return getteo;
}

int edit_setId(eEditorial* this, int id)
{
    int setteo = 0;

    if(this != NULL)
    {
        this->id = id;
        setteo = 1;
    }

    return setteo;
}

int edit_setDesc(eEditorial* this, char* desc)
{
    int setteo = 0;

    if(this != NULL)
    {
        strcpy(this->descripcion, desc);
        setteo = 1;
    }

    return setteo;
}
