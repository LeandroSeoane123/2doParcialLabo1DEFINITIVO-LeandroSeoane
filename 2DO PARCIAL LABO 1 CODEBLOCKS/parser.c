#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Libro.h"
#include "LinkedList.h"

/** \brief Cargara los datos del archivo recibido por parametro, creando un nuevo libro en la lista por cada libro que haya adentro del archivo,
 *         con los datos obtenidos del mismo archivo
 * \param pFile FILE*  Recibe un puntero al archivo abierto con el que debera trabajar
 * \param pLista LinkedList*
 * \return int Retorna 1 si la carga de datos salio bien
 *             Retorna 0 si la carga de datos salio mal
 */
int parsear_librosDesdeTexto(FILE* pFile , LinkedList* pLista)
{
    int retorno = 0;
    eLibro* pLibroLocal;
    char id[20];
    char titulo[125];
    char autor[125];
    char precio[20];
    char editorial[125];

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, editorial);
        pLibroLocal = libro_nuevoParammetros(id, titulo, autor, precio, editorial);
        if(pLibroLocal != NULL)
        {
            ll_add(pLista, pLibroLocal);
            retorno = 1;
        }
    }

    fclose(pFile);

    return retorno;
}
