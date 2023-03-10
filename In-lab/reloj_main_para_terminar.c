//reloj_main_para_terminar.c


#include <stdio.h>


//                  Reloj.h
typedef struct{
    int horas;
    int minutos;
    int segundos;
}Reloj;


//                  Reloj.c
void Reloj_Imprime(const Reloj* this){
    printf( "%02d:%02d:%02d\n", this->horas, this->minutos, this->segundos );
}

void Reloj_Poner(Reloj* this, int horas, int minutos, int segundos){
    this->horas=horas;
    this->minutos=minutos;
    this->segundos=segundos;
}

void Reloj_Incrementar(Reloj* this){
    ++this->segundos;
    if (this->segundos>59){
        this->segundos=0;
        ++this->minutos;
        if (this->minutos>59){
            this->minutos=0;
            ++this->horas;
            if (this->horas>23){
                this->horas=0;
            }
        }
    }
}
//     
//
//      DUDA 1
//
void Reloj_SetHoras(Reloj* this, int horas){
    this->horas=horas;
}
void Reloj_SetMinutos(Reloj* this, int minutos){
    this->minutos=minutos;
}
void Reloj_SetSegundos(Reloj* this, int segundos){
    this->segundos=segundos;
}


int Reloj_GetHoras(Reloj* this){
    return this->horas;
}
int Reloj_GetMinutos(Reloj* this){
    return this->minutos;
}
int Reloj_GetSegundos(Reloj* this){
    return this->segundos;
}

//                  main.c
int main (){
    Reloj casio;
    Reloj swatch;
    
    Reloj_Poner(&casio,12,0,0);
    printf("Reloj 'casio' antes: ");
    Reloj_Imprime(&casio);

    Reloj_Poner(&swatch,19,30,0);
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