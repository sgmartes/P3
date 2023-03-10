//reloj_tda_2.c

#include <stdio.h>


//                  Reloj.h
typedef struct{
    int horas;
    int minutos;
}Reloj;


//                  Reloj.c
void Reloj_Imprime(const Reloj* this){
    printf( "%02d:%02d\n", this->horas, this->minutos );
}

void Reloj_Poner(Reloj* this, int horas, int minutos){
    this->horas=horas;
    this->minutos=minutos;
}

void Reloj_Incrementar(Reloj* this){
    ++this->minutos;
    if (this->minutos>59){
        this->minutos=0;
        ++this->horas;
        if (this->horas>23){
            this->horas=0;
        }
    }
}

//                  main.c
int main (){
    Reloj casio;
    Reloj swatch;
    
    Reloj_Poner(&casio,12,0);
    printf("Reloj 'casio' antes: ");
    Reloj_Imprime(&casio);

    Reloj_Poner(&swatch,19,30);
    printf("Reloj 'swatch' antes: ");
    Reloj_Imprime(&swatch);

    printf("...\n");
    for (size_t i=0;i<82;++i){
        Reloj_Incrementar(&casio);
        Reloj_Incrementar(&swatch);
    }

    printf("Reloj 'casio' después: ");
    Reloj_Imprime(&casio);

    printf("Reloj 'swatch' después: ");
    Reloj_Imprime(&swatch);
}