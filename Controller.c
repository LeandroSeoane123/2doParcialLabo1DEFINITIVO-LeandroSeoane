#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seoane.h"
#include "parser.h"
#include "Libro.h"
#include "Editorial.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief Cargara los datos del archivo que se especifique por linea de comandos
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 0 si la carga salio mal
 *             Retorna 1 si la carga salio bien
 */
int controller_cargarDatosDesdeTexto(LinkedList* pListaLibros, LinkedList* pListaEdit)
{
    FILE* pFile;
    int retornoParser;
    char path[125];

    getString("\nIngrese el nombre del archivo que contiene los datos a cargar junto con su extension."
              "\n(EJEMPLO: ejemplo.csv/ejemplo.txt/ejemplo.bin): ",path);

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        ll_clear(pListaLibros);
        ll_clear(pListaEdit);
        retornoParser = parsear_librosDesdeTexto(pFile, pListaLibros, pListaEdit);

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
 * \param pListaLibros LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si el ordenamiento salio bien
 *             Retorna 0 si el ordenamiento salio mal
 */
int controller_ordenarLibrosPorAutor(LinkedList* pListaLibros)
{
    int len;
    int retornoSort;
    int retorno = 0;

    len = ll_len(pListaLibros);

    if(len > 1)
    {
        puts("\nSe esta ordenando la lista, esto puede tardar unos minutos...");
        retornoSort = ll_sort(pListaLibros, libro_compararPorAutor, 1);
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
 * \param pListaLibros LinkedList* Recibe un puntero a la lista de libros
  * \param pListaEdit LinkedList* Recibe un puntero a la lista de editoriales
 * \return int Retorna 1 si se aplicaron descuentos correctamente
 *             Retorna 0 si no se aplicaron descuentos
 */
int controller_aplicarDescuentos(LinkedList* pListaLibros, LinkedList* pListaEdit)
{
    int retorno;
    int lenL;
    int lenE;

    lenL = ll_len(pListaLibros);
    lenE = ll_len(pListaEdit);

    if(lenL > 0 && lenE > 0)
    {
        puts("\nAplicando descuentos, esto puede tardar unos minutos...");

        retorno = ll_map(pListaLibros, pListaEdit, controller_validarDescuento);

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
 * \param pListaEdit LinkedList* Recibe un puntero a la lista de editoriales
 * \param l1 void* Recibe un puntero a un elemento del tipo VOID
 * \return int Retorna 1 si se le debe aplicar un descuento de los que se le aplican a la editorial Planeta
               Retorna -1 si se le debe aplicar un descuento de los que se le aplican a la editorial SIGLO XXI EDITORES
 *             Retorna 0 si no se debe aplicar ningun descuento
 */
int controller_validarDescuento(LinkedList* pListaEdit, void* l1)
{
    int retorno = 0;
    int retornoCmp;
    eLibro* aux;
    char descEdit[125];
    float precio;

    aux = (eLibro*) l1;

    controller_obtenerEditorial(l1, pListaEdit, descEdit);
    libro_getPrecio(aux, &precio);

    retornoCmp = strcmp(descEdit, "Planeta");

    if(retornoCmp == 0)
    {
        if(precio >= 300)
        {
            retorno = 1;
        }
    }

    retornoCmp = strcmp(descEdit, "SIGLO XXI EDITORES");

    if(retornoCmp == 0)
    {

        if(precio <= 200)
        {
            retorno = -1;
        }
    }

    return retorno;
}

/** \brief Guarda todos los campos de cada elemento de la lista en el archivo mapeado.csv
 *
 * \param path char* Recibe el nombre del archivo donde debe guardar los datos
 * \param pListaLibros LinkedList* Recibe el puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si el guardado salio bien
 *             Retorna 0 si el guardado slaio mal
 */
int controller_guardarMapeado(char* path, LinkedList* pListaLibros, LinkedList* pListaEdit)
{
    FILE* pFile;
    int retorno = 0;
    int lenL;
    int lenE;
    int i;
    int id;
    char titulo[125];
    char autor[125];
    float precio;
    char descEdit[125];
    eLibro* aux;

    pFile = fopen(path, "w");

    lenL = ll_len(pListaLibros);
    lenE = ll_len(pListaEdit);

    if(lenL > 0 && lenE > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<lenL; i++)
            {
                aux = (eLibro*) ll_get(pListaLibros, i);
                if(aux != NULL)
                {
                    libro_getId(aux, &id);
                    libro_getTitulo(aux, titulo);
                    libro_getAutor(aux, autor);
                    libro_getPrecio(aux, &precio);
                    controller_obtenerEditorial(aux, pListaEdit, descEdit);
                    fprintf(pFile, "%d,%s,%s,%.2f,%s\n",id, titulo, autor, precio, descEdit);
                    retorno = 1;
                }
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

/** \brief Obtiene la editorial del libro que se le paso por parametro y la devuelve por parametro
 *
 * \param miLibro eLibro* Recibe un puntero a un elemento del tito eLibro
 * \param pListaEdit LinkedList* Recibe un puntero a la lista de editoriales
 * \param descEdit char* Recibe un puntero a una cadena
 * \return int Retorna 0 si no obtuvo la editorial
 *             Retorna 1 si obtuvo la editorial
 */
int controller_obtenerEditorial(eLibro* miLibro, LinkedList* pListaEdit, char* descEdit)
{
    int retorno = 0;
    int i;
    int lenE;
    int idEL; //ID DE EDITORIAL DEL LIBRO
    int idE; // ID DE EDITORIAL PARA LA LISTA DE EDITORIALES
    eEditorial* auxE;

    lenE = ll_len(pListaEdit);

    if(miLibro != NULL && pListaEdit != NULL)
    {

        libro_getEditorialId(miLibro, &idEL);
        for(i=0; i<lenE; i++)
        {
            auxE = ll_get(pListaEdit, i);
            edit_getId(auxE, &idE);
            if(idEL == idE)
            {
                edit_getDesc(auxE, descEdit);
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief Mostrara todos los libros que contenga la lista que recibe por parametro
 *
 * \param pLista LinkedList* Recibe un puntero a la lista con la que se esta trabajando
 * \return int Retorna 1 si se pudo mostrar los libros con exito
 *             Retorna 0 si no se pudo mostrar los libros con exito.
 */
int controller_mostrarLibros(LinkedList* pListaLibros, LinkedList* pListaEdit)
{
    int retorno = 0;
    int len;
    int i;
    int id;
    char titulo[125];
    char autor[125];
    float precio;
    char descEdit[125];
    eLibro* aux = NULL;

    if(pListaLibros != NULL && pListaEdit != NULL)
    {
        len = ll_len(pListaLibros);
        if(len > 0)
        {
            puts("\n***** LISTANDO LIBROS *****\n");
            puts("\n--ID -------------------------------------------------TITULO ---------- AUTOR ----- PRECIO ---------- EDITORIAL");
            for(i=0; i<len; i++)
            {
                aux = ll_get(pListaLibros, i);
                libro_getId(aux, &id);
                libro_getTitulo(aux, titulo);
                libro_getAutor(aux, autor);
                libro_getPrecio(aux, &precio);
                controller_obtenerEditorial(aux, pListaEdit, descEdit);
                mostrarUnLibro(id, titulo, autor, precio, descEdit);
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

