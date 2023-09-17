#include<stdio.h>
#include<stdlib.h>

void menu(int *opcion){
    printf("\t\t 1.- Comprador \n");
    printf("\t\t 2.- Almacenista\n");
    printf("\t\t 3.- Gerente \n");
    printf("\t\t 4.- Repartidor\n");
    printf("\t\t 5.- salir\n");
    printf("\n\t\t Selecciona una opcion por favor\n");
    scanf("%d",opcion);
}
void menu_compra(int *segunda_opc){
    printf("1.- Seleccionar productos\n");
    printf("2.- Revisar carrito de compras\n");
    printf("3.- Realizar pedido\n");
    printf("4.- salir\n");
    printf("Selecciona una opcion\n");
    scanf("%d",segunda_opc);
}
void menu_almacenista(int *segunda_opc){
    printf("1.- Mostrar la lista de productos\n");
    printf("2.- Registrar la llegada de un producto al almacen\n");
    printf("3.- alir\n");
    printf("Selecciona una opcion\n");
    scanf("%d",segunda_opc);
}
void menu_gerente(int *segunda_opc){
    printf("1.- Cola de pedidos\n");
    printf("2.- Cola de repartidores en espera\n");
    printf("3.- Lista de repartidores en tránsito\n");
    printf("4.- Asignar pedido\n");
    printf("5.- salir\n");
    printf("Selecciona una opcion\n");
    scanf("%d",segunda_opc);
}
void menu_repartidor(int *segunda_opc, int *matricula){
    printf("Porfavor ingresa tu matricula:\n");
    scanf("%d",matricula);
    printf("1.- Pedido asignado\n");
    printf("2.- Notificar entrega de pedido\n");
    printf("3.- salir\n");
    printf("Selecciona una opcion\n");
    scanf("%d",segunda_opc);
}
void menu_general(void){
    printf("pon tu menu aqui \n\n");
}















