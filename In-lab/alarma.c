//alarma.c


#include <stdio.h>
#include <stdbool.h>

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

bool Reloj_Cmp_IsEqual( const Reloj* this, const Reloj* other ){
    if (this->horas==other->horas && this->minutos==other->minutos && this->segundos==other->segundos){
        return true;
    }
    else{
        return false;
    }
}

//                  main.c
int main(){
    Reloj alarma1={.horas=4,.minutos=40,.segundos=0};
    Reloj alarma2={.horas=20,.minutos=35,.segundos=23};
    Reloj casio;
    
    Reloj_Poner(&casio,10,5,30);

    printf("...\n");
    for (size_t i=0;i<86400;++i){ //Incrementa 86,400 segundos, es decir, 24 horas.
        Reloj_Incrementar(&casio);
        if(Reloj_Cmp_IsEqual(&casio,&alarma1)){
            printf("HORA DE LEVANTARSE\n");
        }
        if(Reloj_Cmp_IsEqual(&casio,&alarma2)){
            printf("HORA DE DORMIRSE\n");
        }
    }
}