#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Seoane.h"

int main()
{
    int opcion;
    LinkedList* miListaLibros;
    LinkedList* miListaEdit;

    miListaLibros = ll_newLinkedList();
    miListaEdit = ll_newLinkedList();

    do{
    getInt("***** MENU DE OPCIONES *****"
           "\n1. Cargar datos de libros."
           "\n2. Ordenar la lista por autor (ascendentemente)."
           "\n3. Imprimir datos de libros."
           "\n4. Aplicar descuentos disponibles."
           "\n5. Guardar datos de libros (mapeado.csv)."
           "\n6. Salir."
           "\nIngrese la opcion que desea realizar: ", &opcion);

    switch(opcion)
    {
    case 1:
        controller_cargarDatosDesdeTexto(miListaLibros, miListaEdit);
        break;
    case 2:
        controller_ordenarLibrosPorAutor(miListaLibros);
        break;
    case 3:
        controller_mostrarLibros(miListaLibros, miListaEdit);
        break;
    case 4:
         controller_aplicarDescuentos(miListaLibros, miListaEdit);
        break;
    case 5:
        controller_guardarMapeado("mapeado.csv", miListaLibros, miListaEdit);
        break;
    case 6:
        opcion = validarSalir();
        break;
    }

    validarMenu(opcion, 1, 6);
    limpiarPantalla();

    }while(opcion != 6);

    return 0;
}
