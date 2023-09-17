#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

struct Elemento2 {
    struct Elemento2 *sig, *ant;
    int info;
    char nombre[30];
    int cantidad;
};
typedef struct Elemento2 Elemento2;


struct Lista2 {
    Elemento2 *inicio, *fin;
    int n;
};
typedef struct Lista2 Lista2;



struct Elemento_repartidores{
    struct Elemento_repartidores *sig, *ant;
    //char direccion[50];
    //char nombre[30];
    //int telefono;
    char nombre_repartidor[30];
    int matricula;
};
typedef struct Elemento_repartidores Elemento_repartidores;


struct Lista {
    Elemento_repartidores *inicio, *fin;
    int n;
};
typedef struct Lista Lista;



Elemento2 *crear(int x, char *texto, int cantidad);


struct Elementocola {
    struct Elementocola *sig;
    char direccion[60];
    char nombre[30];
    int telefono;
    Lista2 *aux;
};
typedef struct Elementocola Elementocola;



struct Elementocolarepartidor {
    struct Elementocolarepartidor *sig;
    char nombre[30];
    int unidad;
};
typedef struct Elementocolarepartidor Elementocolarepartidor;



struct cola {
    Elementocola *inicio,*fin;
    int n;
};
typedef struct cola cola;

struct colarep {
    Elementocolarepartidor *inicio,*fin;
    int n;
};
typedef struct colarep colarep;

struct Elemento_movimiento {
    struct Elemento_movimiento *sig, *ant;
    int info;
    char nombre[30];
    char direccion[60];
    int telefono;
    int matricula;
    int nombre_reparidor[40];
};

typedef struct Elemento_movimiento Elemento_movimiento;

struct Lista_rep {
    Elemento_movimiento *inicio, *fin;
    int n;
};

typedef struct Lista_rep Lista_rep;


Elemento_movimiento *crearnodo_movimiento(char *name,char *dir, char *rep, int num,int matri);
Elementocola *crearnodocola(char *direccion, char *texto, int telefono,Lista2 *lista);
Elementocolarepartidor *nodo_repartidor(char *nombre,int unidad);

#endif // ELEMENTO_H_INCLUDED
