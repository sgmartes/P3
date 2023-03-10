//reloj_tda_1.c

#include <stdio.h>

typedef struct{
    int horas;
    int minutos;
}Reloj;

void Reloj_Imprime(const Reloj* this){
    printf( "%02d:%02d\n", this->horas, this->minutos );
}

void Reloj_Poner(Reloj* this, int horas, int minutos){
    this->horas=horas;
    this->minutos=minutos;
}

int main (){
    Reloj casio;

    Reloj_Poner(&casio,12,0);
    Reloj_Imprime(&casio);


    Reloj swatch;

    Reloj_Poner(&swatch,19,30);
    Reloj_Imprime(&swatch);
}