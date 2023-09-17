

// HACER UN PROGRAMA QUE PEMITA DETERMINAR PARA LOS USUARIOS DE UN JUEGO DE ADIVINACION
// SIMILAR AL DE "ADIVINAR EL NUMERO". EL JUGADOR LO JUGARA VARIAS VECES
// TIENE 3 (PARAMETRIZAR EL NUMERO DE VECES POR TURNO) ADIVINANZAS POR CADA TURNO
// POR CADA TURNO: PUNTAJE, CUANTAS EXACTAS, CUANTAS APROXIMADAS Y CUANTAS FALLO
// ALMACENAR LOS RESULTADOS POR TURNO: RESULTADOS TURNO 1, RESULTADOS TURNO 2, RESULTADOS...N
// EN CADA TURNO SE MUESTRAN LOS RESULTADOS DE ÉL

//  TURNO     PUNTAJE    EXACTAS  APROXIMADAS FALLAS
//    1           6        3          0         0
//    2           3        0          3         0
//    3           2        1          0         2
//    ....
// AL FINAL DEL JUEGO (DESEA TERMINAR EL PROGRAMA)
// (1) SE MUESTRA LA TABLA
// (2) ESTADISTICAS: PUNTAJE TOTAL, CUANTAS EXACTAS, CUANTAS APROXIMACIONES, FALLAS
// PROMEDIO DE PUNTOS POR TURNO

// NOS DA FLOJERA ESTAR ADIVINANDO... COMO PODRIA AUTOMATIZAR LAS PRUEBA DEL PROGRAMA??
// main AGRV Y ARGC

//---- PADAWAN NIVEL 0 : ALIMENTACION MANUAL
// SUPER HEROE: USA ARCHIVOS => ARCHIVO DE ENTRADA Y SALIDA
// NIEVEL ERES DIOS (SI PERO NAMAS POQUITO): AGRAGAR LOS NOMBRES DE LOS JUGADORES

#include <stdio.h>
#include <stdlib.h>
#include "Entrada_Salida.h"
#include "funciones.h"

int main()
{
    //Primero creamos un archivo para guardar la tabla final
    FILE* ap;
    ap=fopen("Tabla.txt", "w");
    if(ap==NULL){
        printf("Error al ejecutar\n");
        return 0;
    }else{
    fprintf(ap, "Turno    Puntuaje    Acertadas    Aproximadas     Falladas\n");
     fprintf(ap, "  %d          %d         %d               %d             %d\n", 0,0,0,0,0);

    }
    fclose(ap);
    //!------------------------------------------------

    //Esto es para hacer la suma total de todos los turnos
    int total_puntos, total_acertadas, total_aproximadas, total_falladas, total_turnos;
    total_puntos=0;
    total_acertadas=0;
    total_aproximadas=0;
    total_falladas=0;
    total_turnos=0;

    //Esto es para las estadisticas actuales
    int puntos, acertadas, aproximadas, falladas, turno;
    puntos=acertadas=aproximadas=falladas=turno=0;

    //variable para el switch
    int opcion;

    //----------------------------------------------------

    do{

    menu(&opcion);

    switch(opcion){

    case 1: Reglas_Ayuda();
        break;
    case 2: Igualar_a_Cero(&puntos, &acertadas, &aproximadas, &falladas);
            Jugar(&turno, &puntos, &acertadas, &aproximadas, &falladas);
            SumaTotal(&total_puntos, &total_acertadas, &total_aproximadas, &total_falladas, &total_turnos, puntos, acertadas, aproximadas, falladas, turno);
            LlenarTabla(puntos, acertadas, aproximadas, falladas, turno);
        break;
    case 3: EstadisticasActuales(puntos, acertadas, aproximadas, falladas, turno);
        break;
    case 4: EstadisticasActuales(total_puntos, total_acertadas, total_aproximadas, total_falladas, total_turnos);
        break;
    case 5: Tabla();
            printf("\n\n");
            EstadisticasActuales(total_puntos, total_acertadas, total_aproximadas, total_falladas, total_turnos);
        break;

    }
    }while(opcion!=0);









    return 0;
}
