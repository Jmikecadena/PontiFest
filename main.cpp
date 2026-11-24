#include <iostream>
#include <sstream>
using namespace std;

//Constantes utilizadas con frecuencia en las funciones
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
void cancelarReserva(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS]);
void consultarDisponibilidad(Silla sillas[FILAS][COLUMNAS]);
void buscarCompra(Compra compras[], int tam);
void mostrarComprasPorLocalidad(Compra compras[], int tam);
void consultarSillasOcupadas (Silla sillas[20][6]);
void ventasLocalidad (Silla sillas[20][6]);
void calcularIngresosTotales(Compra compras[], int tam);
char numeroACaracter(int columna);
int caracterANumero(char caracter);
int buscarBloques(Silla sillas[FILAS][COLUMNAS], string localidad, int cantidad, int filaBloque[], int columnaBloque[]);
void inicializarEscenario(Silla sillas[20][6]);
void subirComprasIniciales(Compra compras[], int &tam, Silla sillas[20][6], int &siguienteCompra);
string obtenerLocalidad(int fila, char columna);

int main(){
    bool programa = true;
    Compra compras[100];
    int tam = 0, siguienteCompra = 100;
    Silla sillas[FILAS][COLUMNAS];

    inicializarEscenario(sillas);
    subirComprasIniciales(compras, tam, sillas, siguienteCompra);

    int caso;

    while (programa == true){
        cout<< DIVISION << endl << "\t\t" <<TITULO_PONTIFEST << endl << DIVISION;
        cout<< "\n\tPor favor seleccione la opcion que desee\n\n";
        cout<< "1. Registrar compra de entradas \n2. Cancelar reserva \n3. Consultar disponibilidad por fila\n4. Buscar compras \n5. Mostrar compras agrupadas por localidad\n";
        cout<< "6. Consultar sillas ocupadas \n7. Total de entradas vendidas por localidad \n8. Calcular ingresos totales del evento \n9. Salir\n";
        cout<< DIVISION<<"\nSeleccione una opcion (1-9): ";

        cin>> caso;
        cin.ignore(1000, '\n');
        switch (caso){
        case 1: {
            registrarCompra(compras, tam, sillas, siguienteCompra);
        }
        break;
        case 2: {
            cancelarReserva(compras, tam, sillas);
        }
        break;
        case 3: {
            consultarDisponibilidad(sillas);
        }
        break;
        case 4: {
            buscarCompra(compras, tam);
        }
        break;
        case 5: {
            mostrarComprasPorLocalidad(compras, tam);
        }
        break;
        case 6: {
            consultarSillasOcupadas(sillas);
        }
        break;
        case 7: {
            ventasLocalidad(sillas);
        }
        break;
        case 8: {
            calcularIngresosTotales(compras, tam);
        }
        break;
        case 9: {
            programa = false;
            cout<< DIVISION << endl << "\t\t" <<TITULO_PONTIFEST << endl << "\t\t\tDESPEDIDA"<< DIVISION<<endl;
            cout<< "\t\tGracias por usar PONTIFEST. Hasta pronto!"<<endl;
        }
        break;
        default: {
            cout<<"Opcion no valida, intente de nuevo...\n"<<endl;
        }
        break;
        }

    }
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

    string nombres[5] = {"Thomas Diaz", "Juan Miguel Cadena", "Lorenzo Mendez", "Samuel Salazar", "Luis Chicaiza"};
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
    cout<<"Sillas encontradas para la localidad "<<localidad_string<<endl;

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
    "\nSexo (M/F): "<<sexo<<"\nCantidad de entradas (1-6): "<<entradas<<
    "\nLocalidad del asiento ( 1 = VIP $350, 2 = Preferencial $220, 3 = General $ 120): "<<localidad_string<<endl;
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
                    sillas[fila_seleccionada-1][columna_inicial+i].estado = true;
                    sillas[fila_seleccionada-1][columna_inicial+i].numeroCompra = siguienteCompra;
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
    }while(confirmacion!='N' && confirmacion != 'S');
}

//Funcion opcion 2 del menu

void cancelarReserva(Compra compras[], int &tam, Silla sillas [FILAS][COLUMNAS]){
    string documento, nombre, localidad;
    int entradas, valor_total;
    bool reserva_encontrada = false;

    if (tam == 0){
        cout<<"No hay compras registradas"<<endl;
        return;
    }

    //Solicitar num de documento
    cout<<"Ingrese su numero de documento: "<<endl;
    cin>>documento;


    //Buscar todas las reservas registradas con el documento
    cout<<"Reserva/s encontradas con el documento "<<documento<<": "<<endl;

    //Mostrar las reservas por pantalla
    for (int i =0; i<tam; i++){
        if (documento == compras[i].documento){
            cout<<DIVISION<<endl;
            cout<<compras[i].numeroCompra<<endl;
            cout<<compras[i].tipoLocalidad<<endl;
            cout<<compras[i].cantidadEntradas<<endl;
            cout<<"Sillas asignadas: ";

            for (int j=0; j<FILAS; j++){
                for(int k = 0; k<COLUMNAS; k++){
                    if (sillas[j][k].numeroCompra == compras[i].numeroCompra){
                        cout<<sillas[j][k].fila<<sillas[j][k].columna<<endl;
                    }
                }
            }

            cout<<"Valor total: "<<compras[i].valorTotal<<endl;
            cout<<DIVISION<<endl;
            reserva_encontrada = true;
        }
    }

    if (!reserva_encontrada) {
        cout<<"No se encontraron reservas para el documento "<<documento<<endl;
        return;
    }

    bool compra_encontrada = false;
    int compra_a_cancelar;

    //Do while hasta que ingrese una compra valida
    do {
        //Solicitar numero de compra a cancelar
        cout<<"Ingrese el numero de compra que desee cancelar: "<<endl;
        cin>>compra_a_cancelar;

        for (int i = 0; i < tam; i++){
            if (compra_a_cancelar == compras[i].numeroCompra && compras[i].documento == documento){
                nombre = compras[i].nombreComprador;
                entradas = compras[i].cantidadEntradas;
                localidad = compras[i].tipoLocalidad;
                valor_total = compras[i].valorTotal;

                compra_encontrada = true;
                break;
            }
        }

        if (!compra_encontrada) cout<<"Ingrese un numero valido"<<endl;

    }while(!compra_encontrada);

    //Pedir confirmacion
    cout<<DIVISION<<endl;
    cout<<TITULO_PONTIFEST<<endl;
    cout<<"Cancelar reserva"<<endl;
    cout<<DIVISION<<endl;

    cout<<"Numero de compra a cancelar: "<<compra_a_cancelar<<endl;
    cout<<"Compra:  "<<compra_a_cancelar<<" | "<<nombre<<" | "<<entradas<<" entradas";
    cout<<" | "<<localidad<<" | "<<"$"<<valor_total<<endl;

    //Do while hasta que digite S o N
    char respuesta;
    do {
        cout<<"Confirmar cancelacion (S/N):"<<endl;
        cin>>respuesta;

        if(respuesta != 'S' && respuesta != 'N') {
            cout<<"Ingrese 'S' para confirmar, 'N' para rechazar"<<endl;
        }
    }while(respuesta != 'S' && respuesta != 'N');

    if (respuesta == 'N') {
        cout<<DIVISION<<endl;
        cout<<"Cancelacion abortada. "<<endl;
        cout<<DIVISION<<endl;

        return;
    }


    Silla sillas_auxiliar[120]; // arreglo para guardar las sillas con el numero de compra
    int posicion = 0;
    //Cambiar las sillas con ese numero de compra a true
    for(int i=0; i<FILAS; i++){
        for(int j = 0; j<COLUMNAS; j++){
            if (sillas[i][j].numeroCompra == compra_a_cancelar){
                sillas[i][j].numeroCompra = -1;
                sillas[i][j].estado = false;
                sillas_auxiliar[posicion] = sillas[i][j];
                posicion++;
            }
        }
    }

    //Eliminar la compra del arreglo de Compras (Mover las compras de i+1 hasta tam-1, a la izquierda)
    for (int i = 0; i < tam; i++){
        if (compras[i].numeroCompra == compra_a_cancelar){
            for (int j = i; j < tam-1; j++){
                compras[j] = compras[j+1];
            }
            break;
        }
    }

    cout<<DIVISION<<endl;
    cout<<"Compra cancelada. Sillas liberadas: "<<endl;
    for (int i =0; i<posicion; i++){
        cout<<sillas_auxiliar[i].fila<<sillas_auxiliar[i].columna;
        if(i<posicion-1) cout<<", ";
    }

    tam--; //restar 1 a la cantidad de compras en el arreglo

}

//Funcion opcion 3 del menu

void consultarDisponibilidad(Silla sillas[FILAS][COLUMNAS]){
    int fila, ocupadas = 0, disponibles = 0;
    cout<<DIVISION<<endl;
    cout<<"\t\t"<<TITULO_PONTIFEST<<endl;
    cout<<"Consultar disponibilidad por fila"<<endl;
    cout<<DIVISION<<endl;

    cout<<"Ingrese la fila en la que desee ver el estado de las sillas (1-20): "<<endl;
    cin>>fila;

    if (fila < 1 || fila > 20){
        cout<<"Fila invalida"<<endl;
        return;
    }

    cout<<"==="<<"Fila "<<fila<<"==="<<endl;

    for (int i = 0; i<COLUMNAS; i++){
        cout<<numeroACaracter(i)<<" | "<<sillas[fila-1][i].localidad<<" | ";

        if(sillas[fila-1][i].estado) {
            cout<<"Ocupada"<<endl;
            ocupadas++;
        } else{
            cout<<"Disponible"<<endl;
            disponibles++;
        }
    }

    cout<<"Disponibles: "<<disponibles<<" | Ocupadas: "<<ocupadas<<endl;
    cout<<DIVISION<<endl;

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

    for(int i = 0; i < tam; i++){ //aca se recorre las compras y muestra cuales coinciden
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

//Funcion opcion 6 del menu
void consultarSillasOcupadas (Silla sillas[20][6]){
    int total = 0;

    cout<< DIVISION << endl << "\t\t" <<TITULO_PONTIFEST << "\n\t\t\tSillas Ocupadas\n"<< endl << DIVISION<<endl;
    cout<< "Fila | Col | Localidad | N. Compra\n";
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 6; j++){
            if (sillas[i][j].estado == true){
                cout<< i+1 << " | "<< numeroACaracter(j) << " | "<< sillas[i][j].localidad << " | "<< sillas[i][j].numeroCompra << endl;
                total++;
            }
        }
    }
    cout<< DIVISION << endl;
    cout<< "Total de sillas ocupadas: " << total << endl;
}

//Funcion opcion 7 del menu
void ventasLocalidad (Silla sillas[20][6]){
    int vip = 0, pref = 0, gen = 0;

    cout<< DIVISION << endl << "\t\t" <<TITULO_PONTIFEST << "\n\t\tEntradas vendidas por localidad\n" << endl << DIVISION<<endl;
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 6; j++){
            if (sillas[i][j].estado == true){
                if (sillas[i][j].localidad == "VIP"){
                    vip++;
                }
                if (sillas[i][j].localidad == "Preferencial"){
                    pref++;
                }
                if (sillas[i][j].localidad == "General"){
                    gen++;
                }
            }

        }
    }
    cout<< "VIP: " << vip << "\tPreferencial: " << pref << "\tGeneral: " << gen << "\tTotal: " << vip + pref + gen << endl;
}

//Funcion opcion 8 del menu
void calcularIngresosTotales(Compra compras[], int tam){
    cout<< DIVISION << endl << "\t\t" <<TITULO_PONTIFEST << "\n\t\tIngresos totales del evento\n" << endl << DIVISION<<endl;
    int valorTotal = 0;
    for (int i = 0; i < tam; i++){
        valorTotal += (compras[i].valorTotal*1000);
    }
    cout<< "Total recaudado: $" << valorTotal << "COP\n";
}
