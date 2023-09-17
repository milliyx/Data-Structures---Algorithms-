#include <stdio.h>
#include <stdlib.h>
#include "Entrada_Salida.h"
#include "funciones.h"

void Reglas_Ayuda(){
    system("cls");
    printf("Estas son las reglas:\n");
    printf("1. Puedes tener los turnos que quieras\n");
    printf("2. Tienes 3 intentos por turno\n");
    printf("3. En cada turno sumaras puntos o no\n");
    printf("4. Cada que aciertas al numero secreto sumas 3 puntos\n");
    printf("5. Cada que te aproximes al numero (una unidad encima o por debajo del numero secreto) sumas 1 punto\n");
    printf("6. Cada que falles al numero, no sumaras puntos\n");
    printf("7. Es tu responsabilidad si apuestas numeros dentro o fuera del rango de intervalo del numero secreto JEJE\n");
    printf("8. Puedes terminar el juego cuando lo desees\n");
    printf("9. Al final del juego se mostrara tus puntos totales, al igual que las veces que acertaste, aproximaste, fallaste y los turnos que hiciste\n");
    printf("TE DESEO MUCHA SUERTE!!!\n");
    system("pause");
    system("cls");
}


void menu(int* valor){
    do{
    printf("Buenvenido al programa!!\n");
    printf("Que desea realizar?\n");
    printf("[1] Reglas y ayuda\n");
    printf("[2] Empezar a jugar\n");
    printf("[3] ver estadisticas del ultimo juego\n");
    printf("[4] Ver estadisticas totales\n");
    printf("[5] Ver la tabla de turnos y sus estadisticas\n");
    printf("[0] salir\n\n");
    printf("Elige una opcion aqui --> ");
    scanf("%d", valor);
    system("cls");
    if(*valor<0 || *valor>5)
        printf("Opcion no valida\n\n");

    }while(*valor<0 || *valor>5);
}

void Jugar(int* turno, int* puntos, int* acertadas, int*aproximadas, int* falladas){

    int numero_secreto, apuesta;
    int confirmacion;

    *turno +=1;

    printf("Hola, mis capos, vamos a empezar a jugar!!\n");
    do{
    Prejuego();
    leer(&confirmacion);
    confirmacion==2? Reglas_Ayuda() : 0;
    }while(confirmacion!=1 && confirmacion!=2);

    system("cls");

    printf("Vamos a continuar entonces!!\n");
    numero_secreto=GenerarNumero();
    for (int k=3; k>0; k--){
        printf("----------Intento %d----------\n", k);
        printf("Dame tu apuesta ---> ");
        leer(&apuesta);
        Evaluar(puntos, acertadas, aproximadas, falladas, apuesta, &numero_secreto);

    }
    system("pause");
    system("cls");
    printf("Fin del turno: %d\n", *turno);
    system("pause");
    system("cls");
}

void leer(int* valor){
    scanf("%d", valor);
}

void Prejuego(){
    printf("Antes de continuar, espero que ya hayas visto las reglas\n");
    printf("Ya las viste?\n");
    printf("[1] Ene fecto, pa, ya empieza el juego!!\n");
    printf("[2] Para nada, mi master, enseñame las reglas\n");
}


void EstadisticasActuales(int puntos, int acertadas, int aproximadas, int falladas, int turno){
    printf("ESTAS SON LAS ESTADISTICAS ACTUALES, PA\n");
    printf("Turno: %d\n", turno);
    printf("Puntos: %d\n", puntos);
    printf("Acertadas: %d\n", acertadas);
    printf("Aproximadas: %d\n", aproximadas);
    printf("Falladas: %d\n\n", falladas);
    system("pause");
    system("cls");
}

void Tabla(){
    FILE* ap;
    ap=fopen("Tabla.txt", "r");

    while(feof(ap)==0){
        printf("%c", fgetc(ap));
    }
    fclose(ap);

}
