#ifndef ENTRADA_SALIDA_H_INCLUDED
#define ENTRADA_SALIDA_H_INCLUDED

void Reglas_Ayuda();
void menu(int* valor);
void Jugar(int* turno, int* puntos, int* acertadas, int*aproximadas, int* falladas);
void leer(int* valor);
void Prejuego();
void EstadisticasActuales(int puntos, int acertadas, int aproximadas, int falladas, int turno);
void Tabla();

#endif // ENTRADA_SALIDA_H_INCLUDED
