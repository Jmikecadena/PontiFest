#include <iostream>
#include <<sstream>
using namespace std;

const int FILAS = 20;
const int COLUMNAS = 6;
const string DIVISION = "================================================================";
const string TITULO_PONTIFEST = "PONTIFEST - Vive Javeriano"

struct Compra{
    int numeroCompra;
    string nombreComprador;
    string documento;
    char sexo;
    int cantidadEntradas;
    string tipoLocalidad;
    int valorTotal;
};

struct Silla{
    int numeroEvento;
    int fila;
    char columna;
    bool estado;
    string localidad;
    int numeroCompra;
}

void registrarCompra(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS], int &siguienteCompra);

int main(){

    return 0;

}

void registrarCompra(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS], int &siguienteCompra){
    string nombre, documento;
    char sexo, localidad = '';

    if (tam>100){
        cout<<"Numero maximo de compras alcanzado"<<endl;
        return;
    }

    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"REGISTRAR COMPRA"<<endl;
    cout<<DIVISION<<endl;

    //solicitar el usuario sus datos primero
    cout<<"Ingrese su nombre completo: "<<endl;
    geltline(cin, nombre);
    cout<<"Ingrese su documento (sin espacios): "<<endl;
    cin>>documento;
    cout<<"Ingrese su sexo (digite 'M' si es hombre, 'F' si es mujer): "<<endl;
    cin>>sexo;

    //solicitar localidad a la que desee comprar y cantidad de entradas
    do{
        cout<<"¿En que localidad desea reservar? (digite 'V' para VIP, 'P' para preferencial, 'G' para general): "<<endl;
        cin>>localidad;
    }while(localidad != 'V' && localidad != 'P' && localidad != 'G');

    cout<<"¿Cuantas entradas desea reservar? (1 a 6)"



}
