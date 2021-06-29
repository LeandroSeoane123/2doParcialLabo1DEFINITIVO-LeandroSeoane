typedef struct{

    int id;
    char titulo[125];
    char autor[125];
    float precio;
    char editorial[125];

}eLibro;

eLibro* libro_nuevo();
eLibro* libro_nuevoParammetros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr);

int libro_setId(eLibro* this, int id);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, float precio);
int libro_setEditorial(eLibro* this, char* editorial);

int libro_getId(eLibro* this, int* id);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_getAutor(eLibro* this, char* autor);
int libro_getPrecio(eLibro* this, float* precio);
int libro_getEditorial(eLibro* this, char* editorial);

int libro_compararPorAutor(void* l1, void* l2);
int libro_validarDescuento(void* l1);
int mostrarUnLibro(eLibro* miLibro);
