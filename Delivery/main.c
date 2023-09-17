#include <stdio.h>
#include <stdlib.h>

#include"general.h"
#include"elemento.h"
#include"funciones.h"

int main()
{
    Lista2 *lista_general = nuevaLista2();
    Lista2 *carrito=nuevaLista2();
    Lista_rep *lista_movimiento = nuevaLista_movimiento();
    cola *colapedidos = nuevacola();
    colarep *colarep=nuevacolarep();

    agregar_repartidor(colarep,"Josue Pineda",4567);
    agregar_repartidor(colarep,"Yhair Guzman",4568);
    agregar_repartidor(colarep,"Alan Daniel Perez",4569);
    agregar_repartidor(colarep,"Rafael Arteaga",4570);

    agregaDatoFinal(lista_general,200,"PECHUGA EMPANIZADA",12);
    agregaDatoFinal(lista_general,190,"POLLO ENCHILADO",11);
    agregaDatoFinal(lista_general,180,"MOLE CON CARNE DE PUERCO",10);
    agregaDatoFinal(lista_general,120,"TACOS",19);
    agregaDatoFinal(lista_general,150,"BIRRIA",9);
    agregaDatoFinal(lista_general,210,"CAMARONES",12);
    agregaDatoFinal(lista_general,230,"PULPO A LA NARANJA",13);
    agregaDatoFinal(lista_general,160,"PICADILLO",14);
    agregaDatoFinal(lista_general,100,"CARNE DE RES",12);

    int opcion;
    int segunda_opc;
    int *matricula;
    int contador=0;
    char nombre[30];

    menu_general();

    do{
        menu(&opcion);

        switch(opcion)
        {
            case 1:
                do{
                    menu_compra(&segunda_opc);

                    if (segunda_opc==1){
                        listaproductos(lista_general,carrito,contador);
                        contador++;
                        }
                    if (segunda_opc==2)
                        imprimecarrito(carrito,lista_general);
                    if (segunda_opc==3){
                        realizarpedido(carrito,colapedidos,lista_movimiento,colarep);
                        Elementocolarepartidor *rep;
                        Elementocola *cola;
                        rep=colarep->inicio;
                        cola=colapedidos->inicio;
                        agregaDatoFinal_lista(lista_movimiento,cola->nombre,cola->direccion,rep->nombre,cola->telefono,rep->unidad);
                        borrarprimero(colarep);
                        borrarprimero(colapedidos);
                    }

                }while(segunda_opc!=4);
                break;
            case 2:
                do{
                menu_almacenista(&segunda_opc);
                if (segunda_opc==1)
                    listaalamcen(lista_general);
                if (segunda_opc==2){
                    menuagregarproductos(lista_general);
                    }
                }while(segunda_opc!=3);
                break;
            case 3:
                do{
                menu_gerente(&segunda_opc);
                if(segunda_opc==1)
                    imprimecola(colapedidos);
                if(segunda_opc==2)
                    imprimircola_repartidores(colarep);
                if(segunda_opc==3)
                     imprimeLista_movimiento(lista_movimiento);

                }while(segunda_opc!=5);
                break;
            case 4:
                do{
                int b;
                menu_repartidor(&segunda_opc,&matricula);
                b=matricula;

                if(segunda_opc==1){

                    buscar_pedido(lista_movimiento,b);
                }

                if(segunda_opc==2){
                   printf("Dame tu nombre:\n");
                   fflush(stdin);
                   gets(nombre);
                   agregar_repartidor(colarep,nombre,b);
                   pedido_realizado(lista_movimiento,b);
                    }

                }while(segunda_opc!=3);
                break;
            case 5:
                printf("Gracias por su compra hasta luego");
                break;
            default:
                printf("Valores incorrectos\n");
        }
   }while(opcion!=5);
    return 0;
}
