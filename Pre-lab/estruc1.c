// estruc1.c
// muestra el uso simple de las estructuras
#include <stdio.h>
struct Reloj
{
    int horas;
    int minutos;
};
int main()
{
    struct Reloj casio;
    casio.horas = 13;
    casio.minutos = 30;
    printf( "%02d:%02d\n", casio.horas, casio.minutos );
    printf( "Por favor introduzca las horas\n$ " );
    scanf( "%d", &casio.horas );
    printf( "Por favor introduzca los minutos\n$ " );
    scanf( "%d", &casio.minutos );
    printf( "%02d:%02d\n", casio.horas, casio.minutos );
    if( casio.horas > 4 && casio.horas <= 12 ){
        printf( "¡Buenos días!\n" );
    }
    else if( casio.horas > 12 && casio.horas <= 19 ){
        printf( "¡Buenas tardes!\n" );
    }
    else{
        printf( "¡Buenas noches!\n" );
    }
}