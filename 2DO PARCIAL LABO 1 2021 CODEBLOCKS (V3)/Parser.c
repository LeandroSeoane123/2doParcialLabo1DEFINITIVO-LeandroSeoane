#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Libro.h"
#include "Editorial.h"
#include "LinkedList.h"

/** \brief Cargara los datos del archivo recibido por parametro, creando un nuevo libro en la lista por cada libro que haya adentro del archivo,
 *         con los datos obtenidos del mismo archivo, los mismo hara con las editoriales
 * \param pFile FILE*  Recibe un puntero al archivo abierto con el que debera trabajar
 * \param pLista LinkedList* Recibe un puntero a la lista de libros
  * \param pLista LinkedList* Recibe un puntero a la lista de editoriales
 * \return int Retorna 1 si la carga de datos salio bien
 *             Retorna 0 si la carga de datos salio mal
 */
int parsear_librosDesdeTexto(FILE* pFile , LinkedList* pListaLibros, LinkedList* pListaEdit)
{
    int retorno = 0;
    eLibro* pLibroLocal;
    eEditorial* pEditLocal;
    char id[20];
    char titulo[125];
    char autor[125];
    char precio[20];
    char editorialId[125]; //ID DE EDITORIAL DEL LIBRO
    char descEdit[125];
    char idEditorial[125]; // ID DE EDITORIAL PARA LA LISTA DE EDITORIALES

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, descEdit);
        asignarIdEditorial(descEdit, editorialId);
        asignarIdEditorial(descEdit, idEditorial);
        pLibroLocal = libro_nuevoParammetros(id, titulo, autor, precio, editorialId);
        pEditLocal = edit_nuevaParam(idEditorial, descEdit);
        if(pLibroLocal != NULL && pEditLocal != NULL)
        {
            ll_add(pListaLibros, pLibroLocal);
            ll_add(pListaEdit, pEditLocal);
            retorno = 1;
        }
    }

    fclose(pFile);

    return retorno;
}

