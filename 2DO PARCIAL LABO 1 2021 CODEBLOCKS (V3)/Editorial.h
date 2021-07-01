#ifndef editorial_H_INCLUDED
#define editorial_H_INCLUDED


typedef struct
{

    int id;
    char descripcion[125];

}eEditorial;

eEditorial* edit_nueva();
eEditorial* edit_nuevaParam(char* idStr, char* descripcionStr);
int asignarIdEditorial(char* desc, char* idStr);

int edit_getId(eEditorial* this, int* id);
int edit_getDesc(eEditorial* this, char* desc);

int edit_setId(eEditorial* this, int id);
int edit_setDesc(eEditorial* this, char* desc);

#endif // libro_H_INCLUDED
