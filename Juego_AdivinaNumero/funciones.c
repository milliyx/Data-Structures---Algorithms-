#include "funciones.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int GenerarNumero(){
    int n;
    srand(time(NULL));
    n=rand()%5+0;

    return n;
}


void SumaTotal(int* PuntosTotal, int* AcertadasTotal, int* AproximadasTotal, int*FalladasTotal, int* TurnosTotal, int puntos, int acertadas, int aproximadas, int falladas, int turno){
*PuntosTotal+=puntos;
*AcertadasTotal+=acertadas;
*AproximadasTotal+=aproximadas;
*FalladasTotal+=falladas;
*TurnosTotal+=(turno/turno);
}

void LlenarTabla(int puntos, int acertadas, int aproximadas, int falladas, int turno){
    FILE *ap;
    ap=fopen("Tabla.txt", "a");
    fprintf(ap, "  %d          %d         %d               %d             %d\n", turno, puntos, acertadas, aproximadas, falladas);
    fclose(ap);
}


void Evaluar(int* puntos, int* acertadas, int* aproximadas, int* falladas, int apuesta, int* numero_secreto){
    if(apuesta== *numero_secreto){
            printf("Le atinaste al numero %d!!\n", *numero_secreto);
            printf("Sumas 3 puntos\n");
            *numero_secreto=GenerarNumero();
            *puntos+=3;
            *acertadas+=1;
        }else if(apuesta==*numero_secreto-1 || apuesta==*numero_secreto+1){
            printf("Estuviste muy cerca!!\n");
            printf("Sumas 1 punto\n");
            *puntos+=1;
            *aproximadas+=1;
        }else{
            printf("Fallaste pa\n");
            *falladas+=1;
        }
}


void Igualar_a_Cero(int* puntos, int* acertadas, int* aproximadas, int* falladas){
    *puntos = *acertadas = *aproximadas= *falladas= 0;
}
