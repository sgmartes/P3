//producto.c

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 32

typedef struct{
    int barcode;
    char name[MAX];
    float price;
}Product;

void Product_Ctor(Product* this, int barcode, char* name, float price){
    this->barcode=barcode;
    strncpy(this->name,name,MAX);
    this->price=price;
}

void Product_SetBarcode(Product* this, int barcode){
    this->barcode=barcode;
}
void Product_SetName(Product* this, char* name){
    strncpy(this->name,name,MAX);
}
void Product_SetPrice(Product* this, float price){
    this->price=price;
}

const int Product_GetBarcode(const Product* this){
    return this->barcode;
}
const char* Product_GetName(const Product* this){
    return this->name;
}
const float Product_GetPrice(const Product* this){
    return this->price;
}

void Product_Imprimir(Product* this){
    printf("Información del producto:\n");
    printf("Nombre: %s\nPrecio: %.2f\nC. de barras: %d\n",this->name,this->price,this->barcode);
}

void Product_Assign(Product* this, const Product* other){
    this->barcode=other->barcode;
    strncpy(this->name,other->name,MAX);
    this->price=other->price;
}

bool Product_IsEqual(const Product* this, const Product* other){
    return(this->barcode==other->barcode && strcmp(this->name,other->name)==0 && this->price==other->price);
}

bool Product_IsEqual_ByBarcode(const Product* this, const Product* other){
    return(this->barcode==other->barcode);
}

int main(){
    Product sabritas;
    Product_Ctor(&sabritas,102,"limón y sal",15.4);
    Product_SetBarcode(&sabritas,123);
    float precio_sabritas=Product_GetPrice(&sabritas);
    Product_SetName(&sabritas,"adobadas");

    Product leche[3];
    for (size_t i=0;i<3;++i){
        Product_Ctor(&leche[i],159,"deslactosada",25.52);
    }

    float precio_leche=0;
    printf("¿A cuánto está la leche? ");
    scanf("%f",&precio_leche);
    Product_SetPrice(&leche[1],precio_leche);

    /*
    Product_SetName(&leche[0],"Entera");
    Product_SetBarcode(&leche[1],199);
    Product_SetPrice(&leche[2],5829.01);
    */

    printf("\nInformación de los productos\n");
    for (size_t i=0;i<3;++i){
        printf("Producto %d:\n",i+1);
        printf("Nombre: %s\n",Product_GetName(&leche[i]));
        printf("Precio: %.2f\n",Product_GetPrice(&leche[i]));
        printf("C. de barras: %d\n\n",Product_GetBarcode(&leche[i]));
    }

    Product p1;
    Product_Ctor(&p1,130,"Lubriderm chocolate",90.01);
    Product p2;
    Product_Assign(&p2,&p1);
    
    //Product_Imprimir(&p2);
    if (Product_IsEqual(leche,&leche[1])){
        printf("SON IGUALES\n\n");
    }
    else{
        printf("No son iguales :(\n\n");
    }

}