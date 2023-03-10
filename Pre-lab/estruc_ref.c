// estruc_ref.c
// muestra el uso de las estructuras y funciones

#include <stdio.h>

struct Reloj{
    int horas;
    int minutos;
};

/*
void Imprime(struct Reloj* r){
    printf( "%02d:%02d\n", r->horas, r->minutos );

    // r->horas = 4;
    // ¡error: el objeto r es de sólo lectura!
}
*/

void Imprime(struct Reloj* r){
    printf( "%02d:%02d\n", r->horas, r->minutos );
}

int main(){
    struct Reloj casio={.horas=15,.minutos=30};
    Imprime(&casio);
}