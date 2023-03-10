// estruc_arr.c
// muestra el uso de los arreglos de estructuras
#include <stdio.h>
struct Reloj
{
    int horas;
    int minutos;
};
#define MAX_RELOJES 3
int main()
{
    struct Reloj relojes[ MAX_RELOJES ];
    for( size_t i = 0; i < MAX_RELOJES; ++i ){
        relojes[ i ].horas = 12;
        relojes[ i ].minutos = 0;
    }
    for( size_t i = 0; i < MAX_RELOJES; ++i ){
        printf( "%02d:%02d\n", relojes[ i ].horas, relojes[ i ].minutos );
    }
}