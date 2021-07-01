#ifndef libro_H_INCLUDED
#define libro_H_INCLUDED

typedef struct
{
    int id;
    char titulo[125];
    char autor[125];
    float precio;
    int editorialId;

}eLibro;

eLibro* libro_nuevo();
eLibro* libro_nuevoParammetros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr);

int libro_setId(eLibro* this, int id);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, float precio);
int libro_setEditorialId(eLibro* this, int editorialId);

int libro_getId(eLibro* this, int* id);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_getAutor(eLibro* this, char* autor);
int libro_getPrecio(eLibro* this, float* precio);
int libro_getEditorialId(eLibro* this, int* editorialId);

int libro_compararPorAutor(void* l1, void* l2);
int mostrarUnLibro(int id, char* titulo, char* autor, float precio, char* descEdit);

#endif // libro_H_INCLUDED
