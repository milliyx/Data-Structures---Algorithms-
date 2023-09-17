#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"elemento.h"
#include"funciones.h"

Elemento2 *crear(int x,char *texto,int cantidad) {

    Elemento2 *p;
    p = malloc(sizeof(Elemento2));
    p->ant = NULL;
    p->sig = NULL;
    p->info = x;
    strcpy(p->nombre,texto);
    p->cantidad=cantidad;

    return p;
}

Elementocola *crearnodocola(char *direccion,char *texto,int telefono,Lista2 *lista) {

    Elementocola *p;

    p = malloc(sizeof(Elementocola));
    p->sig = NULL;
    strcpy(p->direccion,direccion);
    strcpy(p->nombre,texto);
    p->telefono=telefono;
    p->aux->inicio=lista->inicio;
    p->aux->fin=lista->fin;

    return p;
}
Elementocolarepartidor *nodo_repartidor(char *nombre,int unidad)
{
    Elementocolarepartidor *b;
    b = malloc(sizeof(Elementocolarepartidor));
    b->sig = NULL;
    strcpy(b->nombre,nombre);
    b->unidad=unidad;

    return b;
}
Elemento_movimiento *crearnodo_movimiento(char *name,char *dir, char *rep, int num,int matri) {
    Elemento_movimiento *p;

    p = malloc(sizeof(Elemento_movimiento));
    p->ant = NULL;
    p->sig = NULL;
    p->info = num;
    strcpy(p->direccion,dir);
    strcpy(p->nombre,name);
    strcpy(p->nombre_reparidor,rep);
    p->matricula=matri;
    return p;
}

