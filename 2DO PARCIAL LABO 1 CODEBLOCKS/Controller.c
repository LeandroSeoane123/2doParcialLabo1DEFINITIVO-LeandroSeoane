#include <stdio.h>
#include <stdlib.h>
#include "Seoane.h"
#include "parser.h"
#include "Libro.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief Cargara los datos del archivo que se especifique por linea de comandos
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 0 si la carga salio mal
 *             Retorna 1 si la carga salio bien
 */
int controller_cargarDatosDesdeTexto(LinkedList* pLista)
{
    FILE* pFile;
    int retornoParser;
    char path[125];

    getString("\nIngrese el nombre del archivo que contiene los datos a cargar junto con su extension."
              "\n(EJEMPLO: ejemplo.csv/ejemplo.txt/ejemplo.bin): ",path);

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        ll_clear(pLista);
        retornoParser = parsear_librosDesdeTexto(pFile, pLista);

        if(retornoParser == 1)
        {
            puts("\nDatos cargados con exito.");
        }
        else
        {
            puts("\nHubo un error al cargar los datos.");
        }
    }
    else
    {
        printf("\nNo se encontro el archivo '%s'."
               "\nPor favor vuelva a intentarlo e ingrese un nombre de archivo y extension validas.", path);
        retornoParser = 0;
    }

    return retornoParser;
}

/** \brief Ordenara la lista de libros por el criterio ascendente de autor
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si el ordenamiento salio bien
 *             Retorna 0 si el ordenamiento salio mal
 */
int controller_ordenarLibrosPorAutor(LinkedList* pLista)
{
    int len;
    int retornoSort;
    int retorno = 0;

    len = ll_len(pLista);

    if(len > 1)
    {
        puts("\nSe esta ordenando la lista, esto puede tardar unos minutos...");
        retornoSort = ll_sort(pLista, libro_compararPorAutor, 1);
        if(retornoSort == 0)
        {
            puts("\nLista ordenada con exito.");
            retorno = 1;
        }
        else
        {
            puts("\nHubo un error al tratar de ordenar la lista.");
        }
    }
    else
    {
        puts("\nNo hay libros suficientes en la lista para efectuar el ordenamiento.");
    }

    return retorno;
}

/** \brief Se encargara de llamar a la funcion ll_map para aplicar los descuentos correspondientes
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si se aplicaron descuentos correctamente
 *             Retorna 0 si no se aplicaron descuentos
 */
int controller_aplicarDescuentos(LinkedList* pLista)
{
    int retorno;
    int len;

    len = ll_len(pLista);

    if(len > 0)
    {
        puts("\nAplicando descuentos, esto puede tardar unos minutos...");

        retorno = ll_map(pLista, libro_validarDescuento);

        if(retorno == 1)
        {
            puts("\nLos descuentos fueron aplicados con exito.");
        }
        else
        {
            puts("\nNo se pudo aplicar ningun descuento.");
        }
    }
    else
    {
        puts("\nError, no hay libros cargados en la lista para aplicar descuentos.");
    }



    return retorno;
}

/** \brief Guarda todos los campos de cada elemento de la lista en el archivo mapeado.csv
 *
 * \param path char* Recibe el nombre del archivo donde debe guardar los datos
 * \param pLista LinkedList* Recibe el puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si el guardado salio bien
 *             Retorna 0 si el guardado slaio mal
 */
int controller_guardarMapeado(char* path, LinkedList* pLista)
{
    FILE* pFile;
    int retorno = 0;
    int len;
    int i;
    int id;
    char titulo[125];
    char autor[125];
    float precio;
    char editorial[125];
    eLibro* aux;

    pFile = fopen(path, "w");

    len = ll_len(pLista);

    if(len > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                aux = (eLibro*) ll_get(pLista, i);
                libro_getId(aux, &id);
                libro_getTitulo(aux, titulo);
                libro_getAutor(aux, autor);
                libro_getPrecio(aux, &precio);
                libro_getEditorial(aux, editorial);
                fprintf(pFile, "%d,%s,%s,%.2f,%s\n",id, titulo, autor, precio, editorial);
                retorno = 1;
            }

            puts("\nDatos guardados correctamente en el archivo 'mapeado.csv'");
        }
        else
        {
            puts("\nNo se encontro el archivo 'mapeado.csv'.");
        }
    }
    else
    {
        puts("\nNo hay libros cargados para guardar.");
    }

    return retorno;
}

/** \brief Mostrara todos los libros que contenga la lista que recibe por parametro
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si se pudo mostrar los libros con exito
 *             Retorna 0 si no se pudo mostrar los libros con exito.
 */
int controller_mostrarLibros(LinkedList* pLista)
{
    int retorno = 0;
    int len;
    int i;
    eLibro* aux = NULL;

    if(pLista != NULL)
    {
        len = ll_len(pLista);
        if(len > 0)
        {
            puts("\n***** LISTANDO LIBROS *****\n");
            puts("\n--ID -------------------------------------------------TITULO ---------- AUTOR ----- PRECIO ---------- EDITORIAL");
            for(i=0; i<len; i++)
            {
                aux = ll_get(pLista, i);
                mostrarUnLibro(aux);
            }
            retorno = 1;
        }
        else
        {
            puts("\nError, no hay libros cargados para mostrar.");
        }

    }
    else
    {
        puts("\nError, la lista no existe.");
    }

    return retorno;
}
