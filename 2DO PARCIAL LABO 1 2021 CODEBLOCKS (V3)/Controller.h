#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

int controller_cargarDatosDesdeTexto(LinkedList* pListaLibros, LinkedList* pListaEdit);
int controller_ordenarLibrosPorAutor(LinkedList* pListaLibros);
int controller_validarDescuento(LinkedList* pListaEdit, void* l1);
int controller_aplicarDescuentos(LinkedList* pListaLibros, LinkedList* pListaEdit);
int controller_guardarMapeado(char* path, LinkedList* pListaLibros, LinkedList* pListaEdit);
int controller_obtenerEditorial(eLibro* miLibro, LinkedList* pListaEdit, char* descEdit);
int controller_mostrarLibros(LinkedList* pListaLibros, LinkedList* pListaEdit);
