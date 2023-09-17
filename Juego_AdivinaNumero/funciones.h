#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int GenerarNumero();
void SumaTotal(int* PuntosTotal, int* AcertadasTotal, int* AproximadasTotal, int*FalladasTotal, int* TurnosTotal, int puntos, int acertadas, int aproximadas, int falladas, int turno);
void LlenarTabla(int puntos, int acertadas, int aproximadas, int falladas, int turno);
void Evaluar(int* puntos, int* acertadas, int* aproximadas, int* falladas, int apuesta, int* numero_secreto);
void Igualar_a_Cero(int* puntos, int* acertadas, int* aproximadas, int* falladas);

#endif // FUNCIONES_H_INCLUDED
