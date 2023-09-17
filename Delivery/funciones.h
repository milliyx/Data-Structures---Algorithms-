#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include"elemento.h"

Lista2 *nuevaLista2(void);
Lista *nuevaLista(void);
Lista_rep *nuevaLista_movimiento(void);
void listaproductos(Lista2 *lista,Lista2 *carrito,int conta);
void listaalamcen(Lista2 *lista);
void agregaDatoespecial(Lista2 *listaA,int dato, char *texto,int cantidad);
void menuagregarproductos(Lista2 *listaA);
void imprimecarrito(Lista2 *carrito,Lista2 *Listap);
int vacia2(Lista2 *lista);
int vacia(Lista *lista);
void agregaDatoFinal(Lista2 *lista, int dato, char *texto,int cantidad);
Elemento2 *borrar2(Lista2 *lista, int dato);
void realizarpedido(Lista2 *carrito,cola *colapedidos,Lista_rep *lista_movimiento,colarep *cola_repartidores);
void limpiar_lista(Lista2 *carrito);
void imprimeLista_movimiento(Lista_rep *lista);
int vacia_movimiento(Lista_rep *lista);
void agregaDatoFinal_lista(Lista_rep *lista,char *name,char *dir,char *rep,int num, int matri);
Elemento_movimiento *borrar_movimiento(Lista_rep *lista, int dato);
void pedido_realizado(Lista_rep *lista_movimiento,int matricula);
void buscar_pedido(Lista_rep *lista_movimiento, int matricula);


///////////////////////////////////////////////////////
//cola



cola *nuevacola(void);
colarep *nuevacolarep(void);
void imprimecola(cola *cola);
int vaciacola(cola *cola);
int vaciacolarep(colarep *cola);
void agregaDatoFinalcola(cola *cola, char *direccion, char *nombre,int telefono,Lista2 *lisa_productos);
int borrarprimero(cola *cola);
void agregar_repartidor(colarep *cola_repartidores,char *nombre,int unidad);
void imprimircola_repartidores(colarep *cola_repartidores);




#endif // FUNCIONES_H_INCLUDED
