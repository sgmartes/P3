// estruc_apunt.c
// muestra el uso de los apuntadores a estructura

#include <stdio.h>

struct Reloj {
    int horas;
    int minutos;
};

int main (){
    struct Reloj casio;
    struct Reloj* p;
    p=&casio;
    p->horas=15;
    p->minutos=30;
    printf("%02d:%02d\n",p->horas,p->minutos);
    printf("%02d:%02d\n",casio.horas,casio.minutos);
    
    printf( "Ingrese la hora:\n$ " );
    scanf( "%d", &p->horas );

    printf( "Ingrese los minutos:\n$ " );
    scanf( "%d", &p->minutos );

    printf( "%02d:%02d\n", p->horas, p->minutos );
}