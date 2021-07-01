#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Editorial.h"

/** \brief Reserva un espacio en memoria dinamica para un elemento del tipo eEditorial
 *
 * \return eEditorial* Retorna un puntero al elemento creado en memoria dinamica
 *
 */
eEditorial* edit_nueva()
{
    eEditorial* pEditLocal;

    pEditLocal = (eEditorial*)malloc(sizeof(eEditorial));

    return pEditLocal;
}

/** \brief Crea mediante la funcion edit_nueva un elemento del tipo eEditorial en memoria dinamica y luego le asigna los datos recibidos por parametro
 *
 * \param idStr char* Recibe ID en cadena
 * \param descripcionStr char* Recibe descripcion de la editorial en cadena
 * \return eEditorial* Retorna un puntero al elemento con los datos asignados
 *
 */
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

/** \brief Asigna el id mediante parametro en base a lo que reciba por descripcion de la editorial
 *
 * \param desc char* Recibe la descripcion de la editorial
 * \param idStr char* Recibe ID en cadena
 * \return int
 *
 */
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

//GETTEOS
/*
 Los GETTERS obtendran el dato especificado y lo devolveran mediante punteros
 Reciben un puntero al elemento del tipo eLibro de donde deben recoger el dato y un puntero a una variable (int/char/float) donde se guardara el dato que se recogio
 Retornara 1 si el GET salio bien
 Retornara 0 si el GET salio mal
*/

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

//SETTEOS
/*
  Los SETTERS asignaran el dato obtenido por parametro al campo correspondiente del elemento que se le paso tambien por parametro
  Recibe un puntero al elemento del tipo eLibro
  Recibe una variable (int/char/float) que contiene el dato a asignar
  Retorna 1 si el SET salio bien
  Retorna 0 si el SET salio mal
*/

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
