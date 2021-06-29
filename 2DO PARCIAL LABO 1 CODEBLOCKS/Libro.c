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
eLibro* libro_nuevoParammetros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr)
{
    eLibro* pLibroLocal = NULL;
    int id;
    float precio;
    int retornoSetId;
    int retornoSetTitulo;
    int retornoSetAutor;
    int retornoSetPrecio;
    int retornoSetEditorial;

    id = atoi(idStr);
    precio = atoi(precioStr);

    if(atoi(idStr))
    {
        pLibroLocal = libro_nuevo();
        if(pLibroLocal != NULL)
        {
            retornoSetId = libro_setId(pLibroLocal, id);
            if(retornoSetId == 1)
            {
                retornoSetTitulo = libro_setTitulo(pLibroLocal, tituloStr);
                if(retornoSetTitulo == 1)
                {
                    retornoSetAutor = libro_setAutor(pLibroLocal, autorStr);
                    if(retornoSetAutor == 1)
                    {
                        retornoSetPrecio = libro_setPrecio(pLibroLocal, precio);
                        if(retornoSetPrecio == 1)
                        {
                            retornoSetEditorial = libro_setEditorial(pLibroLocal, editorialStr);
                        }
                    }
                }
            }
        }
    }

    if(retornoSetId != 1 || retornoSetTitulo != 1  || retornoSetAutor != 1 || retornoSetPrecio != 1 || retornoSetEditorial != 1)
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

int libro_setEditorial(eLibro* this, char* editorial)
{
    int setteo = 0;

    if(this != NULL)
    {
        strcpy(this->editorial, editorial);
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

int libro_getEditorial(eLibro* this, char* editorial)
{
    int getteo = 0;

    if(this != NULL)
    {
        strcpy(editorial, this->editorial);
        getteo = 1;
    }

    return getteo;
}

/** \brief La funciona se encargara de comparar los autores de los elementos que se le paso por parametro y retornara un entero en base a la comparacion.
           Si los autores son iguales, comparara el precio y retornara un entero en base a la comparacion del precio.
 *
 * \param l1 void* Puntero al elemento 1
 * \param l2 void* Puntero al elemento 2
 * \return int Retornara 1 si el autor de elemento 1 es mayor que el autor del elemento 2
 *             Retornara -1 si el autor del elemento 1 es menor que el autor del elemento 2
               Si los autores son iguales, retornara -1 si el precio del elemento 1 es menor que el del elemento 2.
 */
int libro_compararPorAutor(void* l1, void* l2)
{
    int retorno;
    char autor1[125];
    char autor2[125];
    float precio1;
    float precio2;
    int retornoCmp;
    eLibro* aux1;
    eLibro* aux2;

    aux1 = (eLibro*) l1;
    aux2 = (eLibro*) l2;

    libro_getAutor(aux1, autor1);
    libro_getAutor(aux2, autor2);
    libro_getPrecio(aux1, &precio1);
    libro_getPrecio(aux2, &precio2);

    retornoCmp = strcmp(autor1, autor2);

    if(retornoCmp == 1)
    {
        retorno = 1;
    }
    else
    {
        if(retornoCmp == -1)
        {
            retorno = -1;
        }
        else
        {
            if(precio2>precio1)
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

/** \brief Compara la editorial del elemento recibido por parametro con las editoriales que reciben descuentos, para informar si se le debe aplicar un descuento al precio
 *         dependiendo de la condicion que deba cumplir el precio para que se le aplique dicho descuento
 * \param l1 void* Recibe un puntero a un elemento del tipo VOID
 * \return int Retorna 1 si se le debe aplicar un descuento de los que se le aplican a la editorial Planeta
               Retorna -1 si se le debe aplicar un descuento de los que se le aplican a la editorial SIGLO XXI EDITORES
 *             Retorna 0 si no se debe aplicar ningun descuento
 */
int libro_validarDescuento(void* l1)
{
    int retorno = 0;
    int retornoCmp;
    eLibro* aux;
    char editorial[125];
    float precio;

    aux = (eLibro*) l1;

    libro_getEditorial(aux, editorial);
    libro_getPrecio(aux, &precio);

    retornoCmp = strcmp(editorial, "Planeta");

    if(retornoCmp == 0)
    {
        if(precio >= 300)
        {
            retorno = 1;
        }
    }

    retornoCmp = strcmp(editorial, "SIGLO XXI EDITORES");

    if(retornoCmp == 0)
    {

        if(precio <= 200)
        {
            retorno = -1;
        }
    }

    return retorno;
}

/** \brief Muestra todos los campos del elemento del tipo eLibro que se recibio por parametro
 *
 * \param miLibro eLibro* Recibe un puntero a un elemento de tipo eLibro
 * \return int Retorna 1 si se pudo mostrar con exito
               Retorna 0 si no se pudo mostrar con exito
 *
 */
int mostrarUnLibro(eLibro* miLibro)
{
   int retorno = 0;
   int id;
   char titulo[125];
   char autor[125];
   float precio;
   char editorial[125];

   if(miLibro != NULL)
   {
       libro_getId(miLibro, &id);
       libro_getTitulo(miLibro, titulo);
       libro_getAutor(miLibro, autor);
       libro_getPrecio(miLibro, &precio);
       libro_getEditorial(miLibro, editorial);

       printf("%4d %55s %16s %12.2f %20s\n", id, titulo, autor, precio, editorial);
       retorno = 1;
   }

   return retorno;
}
