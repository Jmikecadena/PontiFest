#include <iostream>
#include <sstream>
using namespace std;

const int FILAS = 20;
const int COLUMNAS = 6;
const string DIVISION = "================================================================";
const string TITULO_PONTIFEST = "PONTIFEST - Vive Javeriano";

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
};

void registrarCompra(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS], int &siguienteCompra);
void buscarCompra(Compra compras[], int tam);
void mostrarComprasPorLocalidad(Compra compras[], int tam);
char numeroACaracter(int columna);
int caracterANumero(char caracter);
int buscarBloques(Silla sillas[FILAS][COLUMNAS], string localidad, int cantidad, int filaBloque[], int columnaBloque[]);
void inicializarEscenario(Silla sillas[20][6]);
void subirComprasIniciales(Compra compras[], int &tam, Silla sillas[20][6], int &siguienteCompra);
string obtenerLocalidad(int fila, char columna);

int main(){

    Compra compras[100];
    int tam = 0, siguienteCompra = 0;
    Silla sillas[FILAS][COLUMNAS];

    registrarCompra(compras, tam, sillas, siguienteCompra);
    return 0;

}

//Funciones auxiliares
char numeroACaracter(int columna){
    char caracteres[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    return caracteres[columna];
}

int caracterANumero(char caracter){
    char caracteres[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for(int i=0; i<6; i++){
        if(caracter == caracteres[i]) return i;
    }

    return -1;
}

int buscarBloques(Silla sillas[20][6], string localidad, int cantidad, int filaBloque[], int columnaBloque[]){

    if(cantidad < 1 || cantidad > 6){
        return 0;
    }

    int contador = 0;

    for(int i = 0; i < 20; i++){
        for(int j = 0; j <= 6 - cantidad; j++){

            bool disponible = true;

            for(int k = 0; k < cantidad; k++){

                if(sillas[i][j + k].estado == true || sillas[i][j + k].localidad != localidad){
                    disponible = false;
                    break;
                }
            }

            if(disponible == true){
                filaBloque[contador] = i + 1;
                columnaBloque[contador] = j;
                contador++;
            }
        }
    }

    return contador;
}

void inicializarEscenario(Silla sillas[20][6]){

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 6; j++){

            sillas[i][j].numeroEvento = 1;
            sillas[i][j].fila = i + 1;
            sillas[i][j].columna = 'A' + j;
            sillas[i][j].localidad = obtenerLocalidad(i + 1, 'A' + j);
            sillas[i][j].estado = false;
            sillas[i][j].numeroCompra = -1;

        }
    }
}

void subirComprasIniciales(Compra compras[], int &tam, Silla sillas[20][6], int &siguienteCompra) {
    if (tam < 0 || tam > 95) {
        return;
    }

    string nombres[5] = {"Thomas Diaz", "Juan Miguel Cadena", "Lorenzo Mendez", "Samuel Salazar", "Juan Carlos Gonzalez"};
    string documentos[5] = {"10000001", "10000002", "10000003", "10000004", "10000005"};
    string localidades[5] = {"VIP", "Preferencial", "Preferencial", "General", "General"};

    int cantidades[5] = {2, 2, 3, 3, 2};
    int valores[5] = {700, 440, 660, 360, 240};
    int filas[5] = {1, 3, 8, 14, 18};
    int columnasIniciales[5] = {2, 4, 0, 1, 4};

    for (int i = 0; i < 5; i++) {
        compras[tam + i].numeroCompra = siguienteCompra + i;
        compras[tam + i].nombreComprador = nombres[i];
        compras[tam + i].documento = documentos[i];
        compras[tam + i].sexo = 'M';
        compras[tam + i].cantidadEntradas = cantidades[i];
        compras[tam + i].tipoLocalidad = localidades[i];
        compras[tam + i].valorTotal = valores[i];

        for (int j = 0; j < cantidades[i]; j++) {
            int fila = filas[i] - 1;
            int columna = columnasIniciales[i] + j;

            sillas[fila][columna].estado = true;
            sillas[fila][columna].numeroCompra = siguienteCompra + i;
        }
    }

    tam += 5;
    siguienteCompra += 5;
}

string obtenerLocalidad(int fila, char columna) {
    if (fila < 1 || fila > 20 || columna < 'A' || columna > 'F') {
        return "";
    }

    if (fila <= 5 && (columna == 'C' || columna == 'D')) {
        return "VIP";
    }
    else if (fila <= 12) {
        return "Preferencial";
    }
    else {
        return "General";
    }
}

//Funcion opcion 1 del menu
void registrarCompra(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS], int &siguienteCompra){
    int entradas, filas[120], columnas[120], fila_seleccionada, precio_total;
    string nombre, documento, localidad_string;
    char sexo, localidad;

    if (tam>=100){
        cout<<"Numero maximo de compras alcanzado"<<endl;
        return;
    }

    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"REGISTRAR COMPRA"<<endl;
    cout<<DIVISION<<endl;

    //solicitar el usuario sus datos primero
    cout<<"Ingrese su nombre completo: "<<endl;
    getline(cin, nombre);
    cout<<"Ingrese su documento (sin espacios): "<<endl;
    cin>>documento;
    cout<<"Ingrese su sexo (digite 'M' si es hombre, 'F' si es mujer): "<<endl;
    cin>>sexo;

    if (sexo != 'M' && sexo != 'F'){
        cout<<"Ingrese un sexo valido (M o F)"<<endl;
        return;
    }

    //solicitar localidad a la que desee comprar y cantidad de entradas
    cout<<"¿En que localidad desea reservar? (digite 'V' para VIP, 'P' para preferencial, 'G' para general): "<<endl;
    cin>>localidad;

    if(localidad!='V' && localidad != 'P' && localidad != 'G') {
        cout<<"Ingrese una localidad valida"<<endl;
        return;
    }

    cout<<"¿Cuantas entradas desea reservar? (1 a 6)"<<endl;
    cin>>entradas;

    if (entradas < 1 || entradas > 6) {
        cout<<"Ingrese un numero entre 1 y 6"<<endl;
        return;
    }

    if(localidad == 'V'){
        localidad_string = "VIP";
        precio_total = 350*entradas;
    } else if(localidad == 'P'){
        localidad_string = "Preferencial";
        precio_total = 220*entradas;
    } else {
        localidad_string = "General";
        precio_total = 120*entradas;
    }

    //buscarBloques retorna la cantidad de bloques encontrados
    int bloques_encontrados = buscarBloques(sillas, localidad_string, entradas, filas, columnas);
    if (bloques_encontrados == 0) {
        cout<<"No hay "<<entradas<<" sillas consecutivas para esta localidad"<<endl;
        return;
    }

    //Mostrar en pantalla las sillas disponibles
    cout<<"Sillas encontradas para la localidad "<<localidad;

    for (int i = 0; i < bloques_encontrados; i++){
        cout<<"Fila "<<filas[i]<<", columnas "<<numeroACaracter(columnas[i])<<"-"
        <<numeroACaracter(columnas[i]+entradas - 1)<<endl;
    }

    //Solicitar al usuario las sillas que desea reservar

    //Solicitar fila
    bool fila_encontrada = false;

    do {
        cout<<"Seleccione la fila que desea reservar: "<<endl;
        cin>>fila_seleccionada;

        for (int i = 0; i < bloques_encontrados; i++) {
            if (filas[i] == fila_seleccionada) {
                fila_encontrada = true;
                break;
            }
        }

        if (!fila_encontrada) {
            cout<<"Fila seleccionada no disponible, intente de nuevo"<<endl;
        }
    } while (!fila_encontrada);

    //Solicitar la columna inicial

    int columna_inicial;
    char letra;
    bool columna_encontrada = false;

    do {
        cout<<"Seleccione la columna inicial de las sillas que desea reservar"<<endl;
        cin>>letra;

        int columna = caracterANumero(letra);

        for (int i=0; i < bloques_encontrados; i++) {
            if (columna == columnas[i] && filas[i] == fila_seleccionada) {
                columna_encontrada = true;
                columna_inicial = columna;
                break;
            }
        }

        if (!columna_encontrada) {
            cout << "La columna ingresada no corresponde a un bloque diponible en la fila"<<
            fila_seleccionada<<endl;
        }
    } while (!columna_encontrada);

    //Confirmacion de compra
    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"REGISTRAR COMPRA"<<endl;
    cout<<DIVISION<<endl;

    cout<<"Nombre del comprador: "<<nombre<<"\nNúmero de documento: "<<documento<<
    "\nSexo (M/F): "<<sexo<<"Cantidad de entradas (1-6): "<<entradas<<
    "Localidad del asiento ( 1 = VIP $350, 2 = Preferencial $220, 3 = General $ 120): "<<localidad_string<<endl;
    cout<<DIVISION<<endl;

    cout<<"Resumen de la compra: "<<endl;
    cout<<localidad_string<<": "<<entradas<<", "<<"Fila asignada "<<fila_seleccionada<<
    ", "<<"sillas ";

    for (int i = 0; i<entradas; i++){
        cout<<fila_seleccionada<<numeroACaracter(columna_inicial +i);
        if(i<entradas-1) cout<<", ";
    }

    cout<<"\nValor total: $"<<precio_total<<"(mil pesos)"<<endl;
    char confirmacion;

    do{
        cout<<"¿Confirma que el pedido está correcto? (S/N): "<<endl;
        cin>>confirmacion;

        switch(confirmacion){

            case 'S':
                cout<<DIVISION<<endl;
                cout<<"Compra registrada. Número de compra: "<<siguienteCompra<<endl;
                cout<<"Sillas: Fila "<<fila_seleccionada<<", columnas "<<numeroACaracter(columna_inicial)<<
                '-'<<numeroACaracter(columna_inicial+entradas - 1)<<'('<<localidad_string<<')'<<endl;

                for (int i = 0; i<entradas; i++){
                    sillas[fila_seleccionada-1][columna_inicial+1].estado = false;
                    sillas[fila_seleccionada-1][columna_inicial+1].numeroCompra = siguienteCompra;
                }

                compras[tam].numeroCompra = siguienteCompra;
                compras[tam].nombreComprador = nombre;
                compras[tam].documento = documento;
                compras[tam].sexo = sexo;
                compras[tam].cantidadEntradas = entradas;
                compras[tam].tipoLocalidad = localidad_string;
                compras[tam].valorTotal = precio_total;

                tam++;
                siguienteCompra++;

                break;

            case 'N':
                cout<<"Compra cancelada"<<endl;
                break;

            default:
                cout<<"Seleccione una opcion correcta ('S' para confirmar, 'N' para cancelar compra)"<<endl;
                break;

        }
    }while(confirmacion!='N');
}

//Funcion opcion 4 del menu
void buscarCompra(Compra compras[], int tam){
    string opcion;
    string dato_compra;
    bool encontrado = false;

    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"BUSCAR COMPRA"<<endl;
    cout<<DIVISION<<endl;
    cout<<"1. Por nombre"<<endl;
    cout<<"2. Por numero de documento"<<endl;

    //se pide la opcion
    do{
        cout<<"Opcion: ";
        getline(cin, opcion);

        if(opcion != "1" && opcion != "2"){
            cout<<"Opcion invalida porfavor ingrese 1 o 2"<<endl;
        }

    }while(opcion != "1" && opcion != "2");//esto repite mientras no se ingrese 1 o 2

    if (opcion == "1"){// aca el programa mirara que dato buscar
        cout<<"Nombre: ";
    } else {
        cout<<"Documento: ";
    }

    getline(cin, dato_compra);

    for(int i = 0; i < tam; i++){ //aca se recorre las compras y muetsra cuales coinciden
        bool coincidencia = false;

        if(opcion == "1" && compras[i].nombreComprador == dato_compra){
            coincidencia = true;
        }
        if(opcion == "2" && compras[i].documento == dato_compra){
            coincidencia = true;
        }
        if (coincidencia == true){
            encontrado = true;
            cout<<DIVISION<<endl;
            cout<<"Compra: "<<compras[i].numeroCompra<<endl;
            cout<<"Comprador: "<<compras[i].nombreComprador<<endl;
            cout<<"Documento: "<<compras[i].documento<<endl;
            cout<<"Sexo: "<<compras[i].sexo<<endl;
            cout<<"Entradas: "<<compras[i].cantidadEntradas<<endl;
            cout<<"Localidad: "<<compras[i].tipoLocalidad<<endl;
            cout<<"Valor total: $"<<compras[i].valorTotal<<endl;
        }
    }

    if (encontrado == false){
        cout<<"No se encontraron compras"<<endl;
    }
    cout<<DIVISION<<endl;

}

//Funcion opcion 5 del menu
void mostrarComprasPorLocalidad(Compra compras[], int tam){
    string localidades[3] = {"VIP", "Preferencial", "General"};
    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"Compras por localidad"<<endl;
    cout<<DIVISION<<endl;

    for (int l = 0; l < 3; l++){//esto mirara cada localidad
        bool hay_compras = false;
        cout<<"=="<<localidades[l]<<"=="<<endl;

        for(int i = 0; i < tam; i++){
            if (compras[i].tipoLocalidad == localidades[l]){
                hay_compras = true;
                cout<<"#"<<compras[i].numeroCompra<<" | "//aca se muestra las compras que haya en la localidad
                <<compras[i].nombreComprador<<" | "
                <<compras[i].cantidadEntradas<<" entradas | $"
                <<compras[i].valorTotal<<endl;
            }
        }
        if (hay_compras==false){
            cout<<"Sin compras"<<endl;
        }
    }
    cout<<DIVISION<<endl;
}
