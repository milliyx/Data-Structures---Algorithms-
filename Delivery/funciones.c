#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"funciones.h"
#include"elemento.h"

Lista2 *nuevaLista2(void) {
    Lista2 *p;
    p = malloc(sizeof(Lista2));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}
Lista *nuevaLista(void)
{
    Lista *p;
    p = malloc(sizeof(Lista));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}
Lista_rep *nuevaLista_movimiento(void) {
    Lista_rep *p;
    p = malloc(sizeof(Lista_rep));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}
void listaalamcen(Lista2 *lista) {
    char opc;

    Elemento2 *p;
    if (vacia2(lista)) {
        printf("No hay articulos disponibles \n");
        return;
    }

    p = lista->inicio;

    while (opc!='q') {
        if (p->sig==NULL)
            p->sig=lista->inicio;
        if (p->ant==NULL)
            p->ant=lista->fin;
        printf("\n\n\t\t\t-----%s\n",p->nombre);
        printf("\t\t\t%d$\n ",p->info);
        printf("\t\t\tdisponibles: %d\n\n ",p->cantidad);
        printf("\t j = siguiente   s = anterior  q = salir \n");
        fflush(stdin);
        scanf("%c",&opc);
        if(opc=='j')
            p = p->sig;
        if(opc=='s')
            p= p->ant;
    }
    printf("\n");
    return;
}
void menuagregarproductos(Lista2 *listaA){
    int opc;
    int productos,cantidad;
    char nuevo_producto[30];
    int nuevo_precio, nueva_cantidad;

    do{
        printf("Deseas agregar mas productos?\n");
        printf("1=si  2=no \n");
        scanf("%d",&opc);

        while(opc!=1 && opc!=2)
            printf("Error vuelve a intentar\n");
        if (opc==2)
            return;

        printf("Escoge el producto que desees agregar a la lista: \n\n");
        printf("1=Pozole\n2=Cochinita Pibil\n3=Chiles en Nogada\n4=Barbacoa\n");
        printf("5=Carnitas\n6=Pescado a la Veracruzana\n");
        printf("7=Pescado a la talla\n8=orden de tacos\n9=chilaquiles\n10=agregar nuevo producto \n\n\n");
        scanf("%d",&productos);
        if(productos!=10){
        printf("que cantidad desea agregar?\n");
        scanf("%d",&cantidad);}
        if(productos==1)
            agregaDatoespecial(listaA,100,"Pozole",cantidad);
        if(productos==2)
            agregaDatoespecial(listaA,125,"Cochinita Pibil",cantidad);
        if(productos==3)
            agregaDatoespecial(listaA,70,"Chiles en Nogada",cantidad);
        if(productos==4)
            agregaDatoespecial(listaA,120,"Barbacoa",cantidad);
        if(productos==5)
            agregaDatoespecial(listaA,80,"Carnitas",cantidad);
        if(productos==6)
            agregaDatoespecial(listaA,130,"Pescado a la Veracruzana",cantidad);
        if(productos==7)
            agregaDatoespecial(listaA,135,"Pescado a la talla",cantidad);
        if(productos==8)
            agregaDatoespecial(listaA,60,"orden de tacos",cantidad);
        if(productos==9)
            agregaDatoespecial(listaA,50,"chilaquiles",cantidad);
        if(productos==10)
        {
            printf("Ingresa el nombre del producto: \n");
            fflush(stdin);
            gets(nuevo_producto);
            printf("su precio: \n");
            scanf("%d",&nuevo_precio);
            printf("Cantidad: \n");
            scanf("%d",&nueva_cantidad);
            agregaDatoFinal(listaA,nuevo_precio,nuevo_producto,nueva_cantidad);

        }

    }while(opc!=2);
    return;
}
void agregaDatoespecial(Lista2 *lista,int dato, char *texto,int cantidad)
{
    Elemento2 *aux;
    aux=lista->inicio;

    while(aux!=NULL && aux->info!=dato)
        aux=aux->sig;

    if(aux==NULL){

        Elemento2 *p = crear(dato,texto,cantidad);
        //Elemento2 *rueditas;
        if (vacia2(lista)) {
            lista->inicio = lista->fin = p;
            return;
        }
        p->ant = lista->fin;
        lista->fin->sig = p;
        lista->fin = p;
        lista->n += 1;
        return;
    }else{
    aux->cantidad+=cantidad;
    return;
    }
}

void listaproductos(Lista2 *lista,Lista2 *carrito, int conta) {
    char opc='p';
    int cantidad;

    Elemento2 *p;
    if (vacia2(lista)) {
        printf("Lo siento no hay articulos en este momento.....\n");
        return;
    }

    p = lista->inicio;

    while (opc!='q') {

        if(conta==0){
        system("pause");
        system("cls");}

        if (p->sig==NULL)
            p->sig=lista->inicio;

        if (p->ant==NULL)
            p->ant=lista->fin;

        printf("\n\n\t\t\t----------%s---------\n",p->nombre);
        printf("\t\t\t----------Precio:  $%d--------------\n ",p->info);
        printf("\t\t\t----------Disponibles: %d------------\n\n ",p->cantidad);
        printf("\t j = siguiente comida  s = comida anterior q = salir  r = seleccionar producto\n  ");
        fflush(stdin);
        scanf("%c",&opc);
        if(opc=='j')
            p=p->sig;
        if(opc=='s')
            p=p->ant;
        if (opc=='r'){
            printf("cantidad:\n");
            scanf("%d",&cantidad);
            while(p->cantidad-cantidad<0){
                printf("No hay articulos suficientes vuelve a intentar:\n");
                printf("La cantidad que puedes escoger es: %d\n",p->cantidad);
                scanf("%d",&cantidad);
            }
            agregaDatoFinal(carrito,p->info,p->nombre,cantidad);
            p->cantidad-=cantidad;
        }
    }
    printf("\n");
    return;
}
void imprimecarrito(Lista2 *carrito, Lista2 *Listap) {
    Elemento2 *p;
    Elemento2 *aux;
    char opc;
    int cantidad;
    if (vacia2(carrito)) {
        printf("A un no ha seleccionado ningun producto\n\n");
        return;
    }
    p = carrito->inicio;
    while (opc != 'q') {

        if (p->sig==NULL)
            p->sig=carrito->inicio;
        if (p->ant==NULL)
            p->ant=carrito->fin;
        printf("\n\n\t\t\t-----%s-----\n",p->nombre);
        printf("\t\t\t%d$\n ",p->info);
        printf("\t\t\tcantidad: %d\n\n ",p->cantidad);
        printf("s = anterior   j = siguiente  w = quitar producto  r = salir   \n");
        fflush(stdin);
        scanf("%c",&opc);
        if (opc == 's')
            p = p->ant;
        if (opc =='j')
            p = p->sig;
        if (opc == 'r')
        {
            printf("cuantos productos desea borrar\n");
            scanf("%d",&cantidad);
            if(p->cantidad==cantidad){
                p=borrar2(carrito,p->info);
            }
            if(p->cantidad-cantidad>0){
                p->cantidad-=cantidad;
                aux=Listap->inicio;
                while(aux->info!=p->info)
                    aux=aux->sig;

                aux->cantidad+=cantidad;
            }
            if(p->cantidad-cantidad<0)
                printf("Error\n");
        }
    }
    printf("\n");
    return;
}

int vacia2(Lista2 *lista) {
    return lista->inicio == NULL;
}
int vacia(Lista *lista) {
    return lista->inicio == NULL;
}

void agregaDatoFinal(Lista2 *lista, int dato,char *texto, int cantidad) {
    Elemento2 *p = crear(dato,texto,cantidad);

    if (vacia2(lista)) {
        lista->inicio = lista->fin = p;
        return;
    }
    p->ant = lista->fin;
    lista->fin->sig = p;
    lista->fin = p;
    lista->n += 1;
    return;
}
Elemento2 *borrar2(Lista2 *lista, int dato) {
    Elemento2 *p,*a, *z;
    if (vacia2(lista))
        return NULL;
    if (lista->inicio == lista->fin) {
        if (lista->inicio->info == dato) {
            p = lista->inicio;
            lista->inicio = lista->fin = NULL;
            lista->n = 0;
            return p;
        }
        return NULL;
    }
    p = lista->inicio;
    while (p!=NULL && p->info != dato) {
        p = p->sig;
    }
    if (p==NULL) {
        return NULL;
    }
    if (p == lista->inicio) {
        lista->inicio = lista->inicio->sig;
        lista->inicio->ant = NULL;
        p->sig = NULL;
        return p;

    }
    if (p==lista->fin) {
        lista->fin = lista->fin->ant;
        lista->fin->sig = NULL;
        p->ant = NULL;
        return p;
    }
a = p->ant;
z = p->sig;
a->sig = z;
z->ant = a;
p->ant = NULL;
p->sig = NULL;

return p;
}
void realizarpedido(Lista2 *carrito,cola *colapedidos,Lista_rep *lista_movimiento,colarep *cola_repartidores)
{
    Elemento2 *b;
    Elemento2 *rompedor;

    char nombre[30];
    int telefono;
    char direccion[50];
    int precio=0;

    if (vacia2(carrito)){
        printf("Aun no tienes pedidos\n\n");
        return ;}
    printf("Para realizar su pediodo porfavor ingrese los siguientes datos \n");
    printf("Nombre: \n");
    fflush(stdin);
    fgets(nombre,30,stdin);
    printf("Direccion: \n");
    fflush(stdin);
    fgets(direccion,50,stdin);
    printf("Telefono: \n");
    scanf("%d",&telefono);

    b=carrito->inicio;
    rompedor->info=b->info;

    do
    {
        precio=(b->info*b->cantidad)+precio;
        b=b->sig;

    }while(b!=NULL && rompedor->info!=b->info);

    printf("El total a pagar es %d \n\n",precio);
    agregaDatoFinalcola(colapedidos,direccion,nombre,telefono,carrito);
    limpiar_lista(carrito);
    printf("\t\t ¡¡¡¡¡¡Tu pedido se ha completado!!!!!! \n\n");
}
void limpiar_lista(Lista2 *carrito)
{
    carrito->inicio=carrito->fin=NULL;
    return;
}
void imprimeLista_movimiento(Lista_rep *lista) {
    Elemento_movimiento *p;
    if (vacia_movimiento(lista)) {
        printf("La lista esta vacia\n");
        return;
    }
    p = lista->inicio;
    while (p!=NULL) {
        printf("\nnumero: %d \n",p->info);
        printf("matricula: %d\n",p->matricula);
        printf("Direccion: %s\n",p->direccion);
        printf("Usuario: %s\n",p->nombre);
        printf("Repartidor: %s\n",p->nombre_reparidor);
        p = p->sig;
    }
    printf("\n");
    return;
}
int vacia_movimiento(Lista_rep *lista) {
    return lista->inicio == NULL;
}
void agregaDatoFinal_lista(Lista_rep *lista,char *name,char *dir,char *rep,int num, int matri) {

    Elemento_movimiento *p = crearnodo_movimiento(name,dir,rep,num,matri);
    Elemento_movimiento *rueditas;
    if (vacia_movimiento(lista)) {
        lista->inicio = lista->fin = p;
        return;
    }
    p->ant = lista->fin;

    rueditas = lista->fin;
    rueditas->sig = p;

    lista->fin = p;
    lista->n += 1;
    return;
}

Elemento_movimiento *borrar_movimiento(Lista_rep *lista, int dato) {
    Elemento_movimiento *p,*a, *z;
    if (vacia_movimiento(lista))
        return NULL;
    if (lista->inicio == lista->fin) {
        if (lista->inicio->matricula == dato) {
            p = lista->inicio;
            lista->inicio = lista->fin = NULL;
            lista->n = 0;
            return p;
        }
        return NULL;
    }
    p = lista->inicio;
    while (p!=NULL && p->matricula != dato) {
        p = p->sig;
    }
    if (p==NULL) {
        return NULL;
    }
    if (p == lista->inicio) {
        lista->inicio = lista->inicio->sig;
        lista->inicio->ant = NULL;
        p->sig = NULL;
        return p;

    }
    if (p==lista->fin) {
        lista->fin = lista->fin->ant;
        lista->fin->sig = NULL;
        p->ant = NULL;
        return p;
    }
a = p->ant;
z = p->sig;
a->sig = z;
z->ant = a;
p->ant = NULL;
p->sig = NULL;

return p;
}
cola *nuevacola(void) {
    cola *p;
    p = malloc(sizeof(cola));
    p->inicio=p->fin= NULL;
    p->n = 0;
    return p;
}
colarep *nuevacolarep(void) {
    colarep *p;
    p = malloc(sizeof(colarep));
    p->inicio=p->fin= NULL;
    p->n = 0;
    return p;
}
int vaciacola(cola *cola) {
    return cola->inicio == NULL;
}
int vaciacolarep(colarep *cola) {
    return cola->inicio == NULL;
}
void agregaDatoFinalcola(cola *cola, char *direccion, char *nombre,int telefono,Lista2 *lisa_productos) {

    Elementocola *p = crearnodocola(direccion,nombre,telefono,lisa_productos);

    if (vaciacola(cola)) {
        cola->inicio =cola->fin = p;

        return;
    }
    cola->fin->sig = p;
    cola->fin=p;

    cola->n+=1;

    return;
}
void imprimecola(cola *cola) {
    Elementocola *p;
    Elemento2 *ayuda;
    char opc_lista;
    int entrar_lista;

    if (vaciacola(cola)) {
        printf("No hay ningun pedido\n\n");
        return;
    }

    p = cola->inicio;

    while (p != NULL) {


        printf("\n\n\t\t\t Nombre: %s\n",p->nombre);
        printf("\t\t\t Direccion: %s \n ",p->direccion);
        printf("\t\t\t Telefono: %d\n\n ",p->telefono);
        printf("Deseas ver la lista de productos de es usuario 1=si 2= no\n");
        scanf("%d",&entrar_lista);
        if(entrar_lista==1)
        {
            ayuda=p->aux->inicio;
            while (opc_lista != 'q') {
            printf("bien\n");
            if (ayuda->sig==NULL)
                ayuda->sig=p->aux->inicio;
            if (ayuda->ant==NULL)
                ayuda->ant=p->aux->fin;
            printf("\n\n\t\t\t-----%s-----\n",ayuda->nombre);
            printf("\t\t\tprecio: %d\n ",ayuda->info);
            printf("\t\t\tcantidad: %d\n\n ",ayuda->cantidad);
            printf("j = siguiente s = anterior  q = salir");
            fflush(stdin);
            scanf("%c",&opc_lista);
            if (opc_lista == 's')
                ayuda = ayuda->ant;
            if (opc_lista =='j')
                ayuda = ayuda->sig;
            }
        }
        p = p->sig;
    }
    return;
}
int borrarprimero(cola *cola)
{
    if (cola->inicio == NULL){
        printf("No hay nada para borrar\n");
        return ;
    }
    Elementocola *borrar;
    borrar=cola->inicio;

    cola->inicio=borrar->sig;
    if(cola->inicio==NULL)
        cola->fin=NULL;
}
void agregar_repartidor(colarep *cola_repartidores,char *nombre,int unidad)
{
     Elementocolarepartidor *p = nodo_repartidor(nombre,unidad);

    if (vaciacolarep(cola_repartidores)) {
        cola_repartidores->inicio =cola_repartidores->fin = p;
        return;
    }
    cola_repartidores->fin->sig = p;
    cola_repartidores->fin=p;

    cola_repartidores->n+=1;
    return;
}
void imprimircola_repartidores(colarep *cola_repartidores)
{
    Elementocolarepartidor *p;

    if (vaciacolarep(cola_repartidores)) {
        printf("No has seleccionado ningun producto\n");
        return;
    }
    p = cola_repartidores->inicio;
    while (p != NULL) {
        printf("\n\n\t\t\t Repartidor: %s\n",p->nombre);
        printf("\t\t\t Unidad: %d \n ",p->unidad);
            p = p->sig;
    }
    printf("\n");
    return;
}
void pedido_realizado(Lista_rep *lista_movimiento,int matricula)
{
    Elemento_movimiento *p;
    int m;

    p=lista_movimiento->inicio;

    while(p!=NULL && p->matricula!=matricula)
        p=p->sig;


    if(p==NULL)
    {
        printf("No tienes pedidos en este momento\n");
        return;
    }
    printf("Tu pedido ha sido entregado\n");
    m=matricula;
    borrar_movimiento(lista_movimiento,m);

}
void buscar_pedido(Lista_rep *lista_movimiento, int matricula)
{
    Elemento_movimiento *p;
    p=lista_movimiento->inicio;

    while(p!=NULL && p->matricula!=matricula)
        p=p->sig;

    if (p==NULL){
        printf("No tienes pedidos asinados\n");
        return;
    }

    printf("Direccion: %s",p->direccion);
    printf("Persona: %s",p->nombre);
    printf("Telefono: %d \n",p->telefono);
}











