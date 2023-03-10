//producto.c

#include <stdio.h>

typedef struct{
    int barcode;
    char *name;
    float price;
}Product;

void Product_Ctor(Product* this, int barcode, char* name, float price){
    this->barcode=barcode;
    this->name=name;
    this->price=price;
}

void Product_SetBarcode(Product* this, int barcode){
    this->barcode=barcode;
}
void Product_SetName(Product* this, char* name){
    this->name=name;
}
void Product_SetPrice(Product* this, float price){
    this->price=price;
}

int Product_GetBarcode(Product* this){
    return this->barcode;
}
char* Product_GetName(Product* this){
    return this->name;
}
float Product_GetPrice(Product* this){
    return this->price;
}

void Product_Imprimir(Product* this){
    printf("Información del producto:\n");
    printf("Nombre: %s\nPrecio: %.2f\nC. de barras: %d\n",this->name,this->price,this->barcode);
}

int main(){
    Product sabritas,leche[3];
    Product_Ctor(&sabritas,102,"limón y sal",15.4);
    Product_Imprimir(&sabritas);

    for (size_t i=0;i<3;++i){
        Product_Ctor(&leche[i],159,"deslactosada",25.52);
    }

    Product_SetName(&leche[0],"Entera");
    Product_SetBarcode(&leche[1],199);
    Product_SetPrice(&leche[2],5829.01);

    printf("\nInformación de los productos\n");
    for (size_t i=0;i<3;++i){
        printf("Producto %d:\n",i+1);
        printf("Nombre: %s\n",Product_GetName(&leche[i]));
        printf("Precio: %.2f\n",Product_GetPrice(&leche[i]));
        printf("C. de barras: %d\n\n",Product_GetBarcode(&leche[i]));
    }
}