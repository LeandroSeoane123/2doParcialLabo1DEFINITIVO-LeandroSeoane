#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Libro.h"


/** \brief Reserva un espacio en memoria dinamica para un elemento del tipo eLibro
 *
 * \return eLibro* Retorna un puntero al elemento eLibro creado en memoria
 *
 */
eLibro* libro_nuevo()
{
    eLibro* pLibroLocal;

    pLibroLocal = (eLibro*)malloc(sizeof(eLibro));

    return pLibroLocal;
}

/** \brief Crea mediante la funcion libro_nuevo un elemento del tipo eLibro en memoria dinamica y luego le asigna los datos recibidos por parametro
 *
 * \param idStr char* ID en cadena
 * \param tituloStr char* Titulo en cadena
 * \param autorStr char* Autor en cadena
 * \param precioStr char* Precio en cadena
 * \param editorialStr char* Editorial en cadena
 * \return eLibro* Retorna el puntero al elemento con los datos asignados si todos los setters salieron bien.
                   O retorna (NULL) si algun o mas setters salieron mal
 *
 */
eLibro* libro_nuevoParammetros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
    eLibro* pLibroLocal = NULL;
    int id;
    float precio;
    int editorialId;
    int retornoSet;

    id = atoi(idStr);
    precio = atoi(precioStr);
    editorialId = atoi(editorialIdStr);

    if(atoi(idStr))
    {
        pLibroLocal = libro_nuevo();
        if(pLibroLocal != NULL)
        {
            retornoSet = libro_setId(pLibroLocal, id);
            if(retornoSet == 1)
            {
                retornoSet = libro_setTitulo(pLibroLocal, tituloStr);
                if(retornoSet == 1)
                {
                    retornoSet = libro_setAutor(pLibroLocal, autorStr);
                    if(retornoSet == 1)
                    {
                        retornoSet = libro_setPrecio(pLibroLocal, precio);
                        if(retornoSet == 1)
                        {
                            retornoSet = libro_setEditorialId(pLibroLocal, editorialId);
                        }
                    }
                }
            }
        }
    }

    if(retornoSet != 1)
    {
       pLibroLocal = NULL;
    }

    return pLibroLocal;
}



/*
  Los SETTERS asignaran el dato obtenido por parametro al campo correspondiente del elemento que se le paso tambien por parametro
  Recibe un puntero al elemento del tipo eLibro
  Recibe una variable (int/char/float) que contiene el dato a asignar
  Retorna 1 si el SET salio bien
  Retorna 0 si el SET salio mal
*/

//SETTEOS

int libro_setId(eLibro* this, int id)
{
    int setteo = 0;

    if(this != NULL)
    {
        this->id = id;
        setteo = 1;
    }

    return setteo;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
    int setteo = 0;

    if(this != NULL)
    {
        strcpy(this->titulo, titulo);
        setteo = 1;
    }

    return setteo;
}

int libro_setAutor(eLibro* this, char* autor)
{
    int setteo = 0;

    if(this != NULL)
    {
        strcpy(this->autor, autor);
        setteo = 1;
    }

    return setteo;
}

int libro_setPrecio(eLibro* this, float precio)
{
    int setteo = 0;

    if(this != NULL)
    {
        this->precio = precio;
        setteo = 1;
    }

    return setteo;
}

int libro_setEditorialId(eLibro* this, int editorialId)
{
    int setteo = 0;

    if(this != NULL)
    {
        this->editorialId = editorialId;
        setteo = 1;
    }

    return setteo;
}






//GETTEOS
/*
 Los GETTERS obtendran el dato especificado y lo devolveran mediante punteros
 Reciben un puntero al elemento del tipo eLibro de donde deben recoger el dato y un puntero a una variable (int/char/float) donde se guardara el dato que se recogio
 Retornara 1 si el GET salio bien
 Retornara 0 si el GET salio mal
*/

int libro_getId(eLibro* this, int* id)
{
    int getteo = 0;

    if(this != NULL)
    {
        *id = this->id;
        getteo = 1;
    }

    return getteo;
}

int libro_getTitulo(eLibro* this, char* titulo)
{
    int getteo = 0;

    if(this != NULL)
    {
        strcpy(titulo, this->titulo);
        getteo = 1;
    }

    return getteo;
}

int libro_getAutor(eLibro* this, char* autor)
{
    int getteo = 0;

    if(this != NULL)
    {
        strcpy(autor, this->autor);
        getteo = 1;
    }

    return getteo;
}

int libro_getPrecio(eLibro* this, float* precio)
{
    int getteo = 0;

    if(this != NULL)
    {
        *precio = this->precio;
        getteo = 1;
    }

    return getteo;
}

int libro_getEditorialId(eLibro* this, int* editorialId)
{
    int getteo = 0;

    if(this != NULL)
    {
        *editorialId = this->editorialId;
        getteo = 1;
    }

    return getteo;
}

/** \brief Muestra todos los campos del elemento del tipo eLibro que se recibio por parametro
 *
 * \param miLibro eLibro* Recibe un puntero a un elemento de tipo eLibro
 * \return int Retorna 1 si se pudo mostrar con exito
               Retorna 0 si no se pudo mostrar con exito
 *
 */
int mostrarUnLibro(int id, char* titulo, char* autor, float precio, char* descEdit)
{
    int retorno = 0;

    printf("%4d %55s %16s %12.2f %20s\n", id, titulo, autor, precio, descEdit);
    retorno = 1;

    return retorno;
}
