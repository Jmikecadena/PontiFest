

<!-- Start of picture text -->
Citsy<br>Pontificia Universidad<br>JAVERIANA<br><!-- End of picture text -->

**Facultad de Ingeniería Departamento de Sistemas** 

**Introducción a la programación - 1157 2026-30** 

#### **Proyecto final** 

#### **Presentado por:** 

Thomas Diaz Camacho 

Juan Miguel Cadena Fajardo Samuel Salazar Moreno Lorenzo Mendez Rubio 

#### **Presentado a:** 

Profesor Luis Carlos Chicaíza 

Lunes, 16 de noviembre de 2026 

#### **TABLA DE CONTENIDO** 

|**1. Introducción**|**1**|
|---|---|
|**2. Estructuras de datos**|**3**|
|2.1 Estructura 1: Compra|3|
|2.2 Estructura 2: Silla|4|
|2.3 Arreglo de compras y matriz de sillas|4|
|**3. Funciones**|**6**|
|3.1 Registrar compra de entradas|6|
|3.2 Cancelar reserva|7|
|3.3 Consultar disponibilidad por fila|8|
|3.4 Buscar compra|9|
|3.5 Mostrar compras agrupadas por localidad|9|
|3.6 Consultar sillas ocupadas|10|
|3.7 Calcular total de entradas vendidas por localidad|10|
|3.8 Ingresos totales|10|
|3.9 Inicializar escenario|11|
|3.10 Subir compras iniciales|11|
|3.11 Funciones auxiliares|12|
|3.12 Programa principal|13|
|**4. Diseño de pantallas**|**13**|



## **1. Introducción** 

PontiFest es una empresa que se dedica a la organización de eventos, festivales musicales y espectáculos. Debido al crecimiento de sus eventos, la empresa requiere de un sistema que le permita gestionar la venta de entradas, la asignación de sillas y el control de ocupación de las sillas del escenario. Por ello, se requiere realizar un programa en C++ que simule una plataforma de gestión de eventos y facilite a PontiFest mantener una organización estructurada y automatizada de los registros de las compras y de la disponibilidad de las sillas. 

El escenario se distribuye en distintas localidades, cada localidad con un precio y una ubicación diferentes. Las localidades son VIP, Preferencial y General. El escenario está diseñado de manera que representa una matriz de 20 filas (numeradas del 1 al 20) y 6 columnas (identificadas de la A a la F), sumando un total de 120 sillas. La zona VIP se encuentra en la parte central, ubicada delante del escenario en las filas más cercanas. La Preferencial está ubicada en las zonas laterales de las primeras filas y en la parte intermedia del escenario, mientras que la General corresponde a las sillas más alejadas. 

La ubicación y los precios de cada localidad se representan en la siguiente tabla, suministrada en el documento de requerimientos: 



<!-- Start of picture text -->
SEAT:MPR ttFitas1-5,columnascd S850_ |<br>1-12, cournnas AB yEF yes 612, couunmesco | _62 | $220 _|<br>120<br>[GeneralTotal Fitas 13-20, columnasae 8 S20<br><!-- End of picture text -->

_Tabla 1. Localidades, ubicación, cantidad de sillas, precio por silla_ 

1 

De igual manera, se presenta un diseño del escenario de PontiFest, donde se evidencian las localidades, junto a sus sillas y ubicaciones correspondientes: 



<!-- Start of picture text -->
5 PONTIFEST -<br>Fila A B rc D E F \<br>:OBOEa Ez ao<br>$<br>3 Pret<br>AR bret IE bret<br>i Preferencial (Pref.) ie General [General General ‘General_[ Generst<br>Wi General FEY General I General General General General<br>i oclidad referencia A B c D E F<br><!-- End of picture text -->

_Figura 1. Representación del escenario de PontiFest_ 

Consideramos pertinente que el sistema contenga estructuras de datos que permitan almacenar las compras registradas y la disponibilidad de sillas del escenario en tiempo real. Mientras que, para la lógica, consideramos la creación de distintas funciones que permitan ejecutar funcionalidades específicas, dependiendo de la acción que se desee registrar, ya sea: registrar una compra, cancelar una reserva, consultar disponibilidad, calcular entradas vendidas en tiempo real, entre otras. De esta manera, podemos organizar la estructura del sistema y el código de manera más eficiente. 

La plataforma gestionará un máximo de 100 compras y 6 entradas por compra. Las sillas de una misma compra deberán ser consecutivas y estar en una misma fila y localidad. La disponibilidad de las sillas deberá actualizarse en tiempo real, en caso de compra o de cancelación. Adicionalmente, no se utilizarán las librerías _<vector>_ ni _<algorithm>_ , ni las funciones _stoi_ y _stof_ , y todos los arreglos y matrices tendrán tamaños predefinidos. La entrada y la salida de datos se realizarán por consola, mediante _cin_ y _cout_ . 

A continuación, se describe el diseño de las estructuras de datos y las funciones tentativas a utilizar: 

2 

## **2. Estructuras de datos** 

Nuestro programa contará con dos estructuras, las cuales están expuestas a continuación por medio de tablas en las que se clasifica cada atributo: 

### **2.1 Estructura 1: Compra** 

|**Atributo**|**Tipo de**<br>**dato**|**¿Qué almacena?**|**Validaciones y características**|
|---|---|---|---|
|numeroCompra|int|Número de compra|Debe ser asignado automáticamente,<br>comenzar en 100 y aumentar<br>consecutivamente sin repetirse.|
|nombreComprado<br>r|string|Nombre del comprador|Es obligatorio. No puede estar vacío, contener<br>números ni símbolos especiales. Debe<br>permitir nombres compuestos y espacios.|
|documento|string|Número de documento|Es obligatorio. Debe contener únicamente<br>números, sin espacios ni letras, de 5 a 12<br>dígitos. Debe conservar los ceros iniciales.|
|sexo|char|M o F|Solo se permite M o F.|
|cantidadEntradas|int|Cantidad de entradas<br>compradas|Debe ser un número entre 1 y 6. No acepta<br>letras u otros valores.|
|tipoLocalidad|string|VIP, Preferencial o<br>General|Solo se permite VIP, Preferencial o General.|
|valorTotal|int|Valor total de la compra|Se debe calcular automáticamente según la<br>cantidad de entradas y el precio de la<br>localidad.|



La estructura “Compra” es la que permite almacenar toda la información relacionada con la compra de entradas realizada por un cliente. Cada persona que compra una entrada debe proporcionar los datos que se piden dentro de la estructura. 

#### **¿Por qué el atributo documento es de tipo string?** 

Al utilizarse como identificador de cada persona, no se necesita hacer ningún tipo de operación matemática con este. Adicionalmente, en caso de usar un _int_ , _float_ o _double_ e ingresar un documento que inicie con ceros, estos no se almacenarán, ya que estos tipos de datos lo interpretan como un valor numérico y no como una secuencia de números. Por esto mismo usamos el _string_ , que permite almacenarlo como una secuencia de caracteres. 

3 

### **2.2 Estructura 2: Silla** 

|**Atributo**|**Tipo de**<br>**dato**|**¿Qué almacena?**|**Validaciones y características**|
|---|---|---|---|
|numeroEvento|int|Número del evento al que<br>pertenece la silla|Debe ser 1, porque se trabaja con un único<br>evento.|
|fila|int|Fila en donde está<br>ubicada la silla (1-20)|Debe ser un número entre 1 y 20.|
|columna|char|Columna donde está<br>ubicada la silla (A-F)|Solo se permiten las letras A, B, C, D, E o F.|
|estado|bool|Indica si la silla está<br>Disponible u Ocupada|Solo puede tener dos valores: false<br>(Disponible) o true (Ocupada). El programa lo<br>modifica automáticamente.|
|localidad|string|VIP, Preferencial o<br>General|Debe corresponder a la ubicación de la silla en<br>la localidad establecida.|
|numeroCompra|int|Número de compra al que<br>está asociada la silla|Debe ser -1 cuando la silla está Disponible o<br>contener un número de compra existente<br>cuando está Ocupada.|



La estructura “Silla” permite almacenar toda la información relacionada con cada una de las sillas del escenario. Cada silla tiene una ubicación específica, pertenece a una de las tres localidades y cuenta con un estado que indica si está Disponible u Ocupada. 

Además, permite relacionar cada silla con la compra que tiene asignada mediante su número de compra. De esta manera, el programa puede consultar la disponibilidad de los puestos y asignarlos durante una compra. 

### **2.3 Arreglo de compras y matriz de sillas** 

El programa almacenará su información en las siguientes variables, declaradas en la función principal, y enviadas como argumentos a las demás funciones: 

|**Variable**|**Tipo**|**Descripción**|
|---|---|---|
|compras|Compra[100]|Arreglo de estructuras con las compras registradas. Las<br>compras ocupan siempre las posiciones 0 a tam-1; al<br>cancelar una compra, las posteriores se mueven una<br>posición a la izquierda.|
|tam|int|Cantidad de compras registradas actualmente (0 a 100).|
|sillas|Silla[20][6]|Matriz que representa el escenario. La fila n del escenario<br>corresponde a la posición n-1 de la matriz, y las columnas<br>A a F a las posiciones 0 a 5.|



4 

|**Variable**|**Tipo**|**Descripción**|
|---|---|---|
|siguienteCompra|int|Número que se asignará a la próxima compra. Inicia en<br>100 más la cantidad de compras precargadas y no<br>disminuye al cancelar una compra.|



5 

## **3. Funciones** 

Siguiendo la estructura del menú, proponemos el diseño de las siguientes funciones: 

### **3.1 Registrar compra de entradas** 

**_void registrarCompra(Compra compras[], int &tam, Silla sillas[20][6], int &siguienteCompra)_** 

Esta función tiene el objetivo de solicitar los datos de compra al usuario y almacenarlos a la estructura de datos. Igualmente, actualizar el estado de las sillas compradas. 

#### **Argumentos:** 

- Arreglo de tipo Compra _compras[]_ : estructura de datos que almacena todas las compras registradas en el sistema. En ella se van a registrar las compras de clientes nuevos. El argumento debe ser un arreglo de tipo Compra para que la función pueda ejecutarse. El arreglo es de tamaño 100 y se escribe la nueva compra en la posición _tam_ . 

- Variable _&tam_ de tipo entero: representa la cantidad de compras que contiene el arreglo de compras (0 a 100), utiliza & (ampersand) para pasar el argumento por referencia, ya que a medida que se registra una nueva compra, su cantidad va aumentando. La variable debe ser de tipo _int_ y debe contener el valor real de las compras registradas hasta el momento para que la función se ejecute exitosamente. 

- _Silla sillas[20][6]_ : matriz sillas de tipo _Silla[20][6]_ , representa el escenario, donde cada posición es una silla. La función cambia el estado y el número de compra de las sillas asignadas. 

- _&siguienteCompra_ de tipo entero: lleva el número de la siguiente compra (arranca en 100 más la cantidad de compras precargadas). Se pasa por referencia, porque se incrementa tras cada compra. 

#### **Descripción:** 

1. Verificar que _tam_ < 100; si no, se informa al usuario y se retorna. 

2. Solicitar al usuario su nombre ( _getline_ ), su número de documento (solo dígitos) y su sexo (M o F). Guardar las entradas del usuario en las variables correspondientes. 

3. Pedir la localidad en la que se desee realizar la compra, sea VIP, Preferencial o General, y la cantidad de entradas (de 1 a 6). 

4. Entrar a la matriz de sillas y recorrer fila por fila buscando la cantidad de sillas consecutivas que se encuentren disponibles y sean de esa localidad, con la función _buscarBloques_ . 

5. Si no existe ningún bloque de sillas consecutivas disponibles en esa localidad, se informa al usuario que no se pudo completar la compra y se retorna. 

6 

6. En caso de que sí, se mostrarán por pantalla las sillas disponibles, por fila y columna, para que el usuario seleccione, si hay varios bloques disponibles. 

7. Se calculará el precio del total de la compra: precio por localidad * cantidad de entradas. Se mostrará por pantalla y se le pedirá al usuario que confirme la compra (S/N). Si responde N, se informa que la compra fue cancelada y se retorna sin modificar nada. 

8. Posteriormente, modificar la matriz de sillas, cambiando el estado de las sillas seleccionadas y asignándoles el número de compra. 

9. Agregar una nueva compra al arreglo _compras_ , en posición _tam_ , llenando con los datos del comprador, los datos sobre la compra y el número de compra, que es _siguienteCompra_ . Luego, incrementar _tam_ y _siguienteCompra_ en 1. 

10. Finalmente, se mostrará por pantalla el resumen de la compra. 

**Retorno:** void, no retorna ningún valor. 

**Precondición:** 0<=tam<=100. Arreglo de compras y matriz de sillas declaradas. La matriz debe contener las sillas precargadas, y el valor de _siguienteCompra_ debe ser >=100. 

**Postcondición:** Si se efectúa la compra, _tam_ y _siguienteCompra_ aumentan en 1. Se actualiza el estado de las sillas compradas (pasan a estar Ocupadas), junto al número de compra, y _compras[tam-1]_ queda con todos los atributos llenos. Si no se efectúa, se informa al usuario y ningún argumento cambia. 

### **3.2 Cancelar reserva** 

#### **_void cancelarReserva(Compra compras[], int &tam, Silla sillas[20][6])_** 

Esta función cancela una compra previamente realizada: actualiza la disponibilidad de las sillas, de Ocupada a Disponible, y restablece su número de compra a -1. De igual forma, busca la posición de la compra en el arreglo y la elimina. 

**Argumentos:** 

- _Compra compras[]_ : arreglo de tipo Compra que almacena todas las compras registradas. En esta función, se utilizará para buscar la compra que el usuario desee cancelar y sustraerla del arreglo. 

- _int &tam_ : variable _tam_ de tipo entero, almacena la cantidad de compras registradas en el sistema. Se pasa por referencia para actualizar el número en caso de que el usuario desee eliminar una reserva previamente realizada. 

- _Silla sillas[20][6]_ : matriz de 20 x 6 que representa el escenario: cada posición representa una estructura de tipo Silla, donde se almacena información sobre la disponibilidad, ubicación y localidad de cada una de ellas. En esta función, se utilizará para actualizar el 

7 

estado de las sillas que se deseen cancelar su reserva: de “Ocupada” a “Disponible”, y actualizar su número de compra a -1, para indicar que no ha sido reservada. 

**Descripción:** 

1. Verificar que 0 < _tam_ . En caso de que no, informar al usuario que no hay compras registradas y retornar. 

2. Solicitar al usuario su número de documento. 

3. Recorrer el arreglo de compras y mostrar todas las reservas realizadas con ese documento (número de compra, localidad, cantidad de boletas, sillas asignadas y valor). En caso de no haber reservas, informar al usuario y retornar. 

4. Pedir al usuario el número de compra que desee cancelar. 

5. Validar que el número ingresado corresponda a una de las reservas disponibles y a ese documento. 

6. Pedir al usuario que confirme la cancelación (S/N). Si responde N, se informa que la cancelación fue descartada y se retorna sin modificar nada. 

7. Modificar el estado de las sillas de la compra seleccionada: de “Ocupada” a “Disponible”, recorriendo la matriz por el número de compra. 

8. Recorrer el arreglo de compras hasta encontrar el número de compra solicitado y mover todas las compras que se encuentren después (de i+1 hasta tam-1) a la izquierda. 

9. Actualizar _tam_ a _tam-1_ , es decir, restar 1 a la cantidad de compras en el arreglo. 

10. Informar que la cancelación de la reserva pudo realizarse de manera exitosa, mostrando al usuario las sillas liberadas por pantalla. 

**Retorno:** void, no retorna ningún valor. 

**Precondición:** Que 0<=tam<=100, la matriz de sillas y el arreglo de compras declarados. 

**Postcondición:** Si el número de compra existe y corresponde al documento ingresado, y el usuario confirma, esa compra se elimina del arreglo. La variable _tam_ disminuye en 1, y las sillas asociadas a la reserva quedan Disponibles, con número de compra igual a -1. Si no hay compras registradas, el número de compra no pertenece a ese documento o el usuario no confirma, se informa al usuario y ningún argumento cambia. 

### **3.3 Consultar disponibilidad por fila** 

#### **_void consultarDisponibilidad(Silla sillas[20][6])_** 

Esta función recorre la matriz sillas, en una determinada fila, e imprime por pantalla las sillas, mostrando su disponibilidad, su localidad y su posición. 

8 

**Argumentos:** 

- _Silla sillas[20][6]_ : matriz de tipo Silla que representa la información de cada una de las sillas del escenario. En esta función, se utilizará para buscar todas las sillas en la fila que desee buscar el usuario y mostrarlas por pantalla. 

#### **Descripción:** 

1. Solicita al usuario la fila en la que desee ver el estado de las sillas (entero de 1 a 20). 

2. Se verifica que la entrada del usuario sea un entero entre 1 y 20. Si no, se informa al usuario y se retorna. 

3. Se recorren las 6 columnas en la fila que el usuario desea consultar (posición fila - 1, en la matriz). 

4. Se muestra por pantalla cada una de las sillas pertenecientes a esa fila, mostrando su estado: “Ocupada” o “Disponible”; su localidad: VIP, Preferencial o General; y su posición: fila (1-20) y columna (A-F). 

5. Mostrar, al final, la cantidad de sillas disponibles y ocupadas en esa fila. 

**Retorno:** void, no retorna ningún valor. 

**Precondición:** Matriz _sillas_ inicializada: cada silla tiene su localidad y su estado definidos. 

**Postcondición:** La matriz no se modifica, simplemente se muestra la información de la fila, o un mensaje de error que muestre que la fila ingresada es inválida, en caso de que sea menor que 1 o mayor que 20. 

### **3.4 Buscar compra** 

**_void buscarCompra(Compra compras[], int tam)_** 

**Argumentos:** 

- _compras_ (Compra [100]): arreglo de compras; solo se lee. 

- _tam_ (int): cantidad de compras registradas. 

#### **Descripción:** 

Muestra un submenú: 1) buscar por nombre, 2) buscar por documento. Por nombre: solicita el nombre y recorre las compras mostrando todas las que tengan exactamente ese nombre. Por documento: solicita el documento y muestra todas las compras con ese documento (un mismo comprador puede tener varias compras). Si no hay coincidencias, informa que no se encontraron compras. 

**Retorno:** Ninguno (void). 

**Precondición:** 0 <= tam <= 100. 

9 

**Postcondición:** El arreglo de compras no se modifica. 

### **3.5 Mostrar compras agrupadas por localidad** 

**_void mostrarComprasPorLocalidad(Compra compras[], int tam)_** 

**Argumentos:** 

- _compras_ (Compra [100]): arreglo de compras; solo se lee. 

- _tam_ (int): cantidad de compras registradas. 

#### **Descripción:** 

Para cada localidad, en orden (VIP, Preferencial, General), recorre el arreglo de compras y muestra por pantalla las compras cuyo tipoLocalidad coincide. Si una localidad no tiene compras, el programa muestra “Sin compras”. 

**Retorno:** Ninguno (void). 

**Precondición:** 0 <= tam <= 100. 

**Postcondición:** Ningún dato es modificado. 

### **3.6 Consultar sillas ocupadas** 

#### **_void consultarSillasOcupadas(Silla sillas[20][6])_** 

**Argumentos:** 

- _Silla sillas[20][6]_ : matriz de Silla, se lee el estado a ver si está Ocupada o no. 

#### **Descripción:** 

La función recorre la matriz y, con un _if_ , revisa si _sillas[x][y].estado_ es o no verdadero. Luego, le indica al usuario mediante un _cout_ la posición (fila y columna), la localidad y el número de compra de las sillas ocupadas. 

**Retorno:** void. 

**Precondición:** Llenar la matriz _sillas_ con la información necesaria al menos para determinar si está o no Ocupada. 

**Postcondición:** La matriz no se modifica. 

### **3.7 Calcular total de entradas vendidas por localidad** 

**_void ventasLocalidad(Silla sillas[20][6])_** 

**Argumentos:** 

- _Silla sillas[20][6]_ : matriz de Silla, se usa para ver el estado de la silla y su localidad. 

10 

**Descripción:** 

Se determina si está tomada la silla y se revisa la localidad a la que pertenece. Luego se almacena cada localidad en una variable temporal ( _vip_ , _pref_ , _gen_ ), que se usan como contador: todas empiezan en cero y cuando se encuentre una silla de su tipo se suma uno al contador. Para finalmente imprimirlo en la pantalla. 

**Retorno:** void. 

**Precondición:** Llenar la matriz _sillas_ con la información necesaria al menos para determinar si está o no Ocupada. 

**Postcondición:** La matriz no se modifica. 

### **3.8 Ingresos totales** 

**_int calcularIngresosTotales(Compra compras[], int tam)_** 

**Argumentos:** 

- _compras_ (Compra compras[]): arreglo de compras; solo se lee. 

- _tam_ (int): cantidad de compras registradas. 

**Descripción:** 

Suma _valorTotal_ de las compras 0 a _tam-1_ ; donde la opción del menú mostrará el resultado en miles de pesos y su equivalente en pesos (x1000). 

**Retorno:** int, suma de ingresos en miles de pesos. 

**Precondición:** 0 <= tam <= 100. 

**Postcondición:** No modifica datos y retorna 0 si no hay compras. 

### **3.9 Inicializar escenario** 

**_void inicializarEscenario(Silla sillas[20][6])_** 

**Argumentos:** 

- _Silla sillas[20][6]_ : matriz de Silla que representa el escenario; todas sus posiciones son modificadas. 

**Descripción:** 

Recorre la matriz asignando a cada silla su posición (fila y columna), su localidad, el estado Disponible (false) y el número de compra -1. 

**Retorno:** void. 

**Precondición:** Matriz de sillas declarada con tamaño 20 x 6. 

11 

**Postcondición:** Las 120 sillas quedan con su posición y localidad, Disponibles y con número de compra -1. 

### **3.10 Subir compras iniciales** 

#### **_void subirComprasIniciales(Compra compras[], int &tam, Silla sillas[20][6], int &siguienteCompra)_** 

**Argumentos:** 

- _Compra compras[]_ : arreglo de compras, en donde se escriben las compras iniciales. 

- _int &tam_ : cantidad de compras; se pasa por referencia ya que la función la actualiza. 

- _Silla sillas[20][6]_ : matriz de Silla ya inicializada; se marcan como Ocupadas las sillas de las compras iniciales. 

- _int &siguienteCompra_ : número de la siguiente compra. Se pasa por referencia porque la función lo actualiza. 

#### **Descripción:** 

Al iniciar el programa, registra las 5 compras del ejemplo de la tabla 2, en el arreglo de compras y marca como Ocupadas las sillas correspondientes, con su número de compra. De esta manera, las sillas ocupadas iniciales quedan en 5 filas y 6 columnas distintas, cada una con un número de compra válido. 

**Retorno:** void. 

**Precondición:** La matriz fue inicializada, _tam_ es 0 y _siguienteCompra_ es 100. 

**Postcondición:** _tam_ queda en 5, _siguienteCompra_ queda en 105 y 12 sillas quedan Ocupadas, con números de compra del 100 al 104. 

**Tabla 2.** 

|**Num de**<br>**compra**|**Localidad**|**Entradas**|**Sillas**|**Valor total**|
|---|---|---|---|---|
|100|VIP|2|Fila 1, columnas C-D|$700.000|
|101|Preferencial|2|Fila 3, columnas E-F|$440.000|
|102|Preferencial|3|Fila 8, columnas A-C|$660.000|
|103|General|3|Fila 14, columnas B-D|$360.000|
|104|General|2|Fila 18, columnas E-F|$240.000|



### **3.11 Funciones auxiliares** 

Estas funciones son utilizadas por las funciones anteriores. 

12 

#### **_3.11.1 obtenerLocalidad_** 

**_string obtenerLocalidad(int fila, char columna)_** 

Determina la localidad de una silla a partir de su fila y su columna. 

**Argumentos:** 

- _int fila_ : número de fila de la silla (1-20). 

- _char columna_ : letra de la columna de la silla (A-F). 

#### **Descripción:** 

1. Si la fila es menor o igual a 5 y la columna es C o D, retornar “VIP”. 

2. Si no, si la fila es menor o igual a 12, retornar “Preferencial”. 

3. En cualquier otro caso retornar “General”. 

**Retorno:** variable de tipo string, ya sea “VIP”, “Preferencial” o “General”. 

**Precondición:** 1<=fila<=20 y la columna está entre ‘A’ y ‘F’. 

**Postcondición:** No modifica ningún dato; retorna la localidad de la silla. 

#### **_3.11.2 buscarBloques_** 

#### **_int buscarBloques(Silla sillas[20][6], string localidad, int cantidad, int filaBloque[], int columnaBloque[])_** 

Recorre la matriz buscando los bloques de sillas consecutivas, disponibles, de una misma fila y de una misma localidad, con el tamaño solicitado. 

#### **Argumentos:** 

- _Silla sillas[20][6]_ : matriz del escenario 

- _string localidad_ : localidad en la que debe estar todo el bloque. 

- _int cantidad_ : cantidad de sillas consecutivas buscadas (1 a 6). 

- _int filaBloque[]_ : arreglo de tamaño 120 donde se guarda la fila de cada bloque encontrado. 

- _int columnaBloque[]_ : arreglo de tamaño 120 donde se guarda la columna inicial de cada bloque encontrado. 

#### **Descripción:** 

1. Declarar una variable contador, que cuente los bloques, y empiece en 0 

2. Para cada fila y para cada columna inicial, desde 0 hasta 6 - _cantidad_ , verificar que las _cantidad_ sillas estén Disponibles y pertenezcan a la localidad pedida. 

3. Si el bloque cumple, guardar su fila y su columna inicial en los arreglos y sumar 1 al contador. 

13 

#### 4. Retornar el contador. 

**Retorno:** int, cantidad de bloques encontrados (0 si no hay ninguno). 

**Precondición:** 1 <= cantidad <= 6, la localidad es válida y los arreglos tienen al menos 120 posiciones. 

**Postcondición:** La matriz no se modifica. Los arreglos contienen la ubicación de los bloques encontrados. 

Estas son las funciones auxiliares que como grupo consideramos para el sistema. Es posible que, sobre la marcha, se establezcan y utilicen más funciones auxiliares. 

### **3.12 Programa principal** 

**_int main()_** 

**Argumentos:** 

Ninguno. 

**Descripción:** 

Declara el arreglo _compras_ , la matriz _sillas_ y las variables _tam_ , igual a 0 y _siguienteCompra, igual a 100_ . Invoca _inicializarEscenario_ y _subirComprasIniciales_ , y mantiene el menú principal en ejecución: muestra las 9 opciones, lee la opción de 1 a la 9 e invoca la función correspondiente hasta que el usuario elija 9, que es, la opción de salir. 

**Retorno:** int, 0 al terminar el programa. 

**Precondición:** Ninguna. 

**Postcondición:** El programa finaliza cuando el usuario elige la opción 9. 

## **4. Diseño de pantallas** 

A continuación se presentan los diseños de las pantallas del programa y la interacción entre el usuario y el sistema (no necesariamente se verán así en el código final). Los valores entre comillas representan lo que el usuario digita. 

#### **Pantalla 1: Menu principal** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

================================================================ 

#### **_<u>Por Favor seleccione la opción que desea</u>_** 

14 

1. <u>Registrar compra de entradas</u> 

2. <u>Cancelar reserva</u> 

3. <u>Consultar disponibilidad por fila</u> 

4. <u>Buscar compra</u> 

5. <u>Mostrar compras agrupadas por localidad</u> 

6. <u>Consultar sillas ocupadas</u> 

7. <u>Total de entradas vendidas por localidad</u> 

8. <u>Calcular ingresos totales del evento</u> 

9. <u>Salir</u> 

================================================================ 

Seleccione una opción (1-9):_ 

Si se digita una letra o un número fuera de 1-9: “opción inválida. Ingrese un número entre 1 y 9 “ 

y se vuelve a mostrar el menú y pedir una opción. 

#### **Pantalla 2: Registrar compra (exito)** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano REGISTRAR COMPRA</u> 

================================================================ 

**<u>Nombre del comprador:</u>** “XXXXX” 

**<u>Número de documento:</u>** “xxxxxxxxxx” 

**<u>Sexo (M/F):</u>** “x” **<u>Cantidad de entradas (1-6):</u>** “x” 

**<u>Localidad del asiento ( 1 = VIP $350, 2 = Preferencial $220, 3 = General $ 120):</u>** “x” 

================================================================ 

#### **_<u>Resumen de la compra:</u>_** 

Preferencial: 3, Fila asignada “x”, sillas “x, x, x” Valor total: $660 (mil pesos) 

15 

¿Confirma que el pedido está correcto?  (S/N): “X” 

================================================================ Compra registrada. Número de compra: “xxx” 

Sillas: Fila “x”, columnas “x-x” (Preferencial) 

**Pantalla 3: Registrar compra (Errores)** 

# ================================================================ <u>PONTIFEST - Vive Javeriano REGISTRAR COMPRA</u> 

================================================================ 

**<u>Cantidad de entradas (1-6):</u>** “9” **<u>Error: la cantidad debe estar entre 1 y 6</u>** 

**<u>Número de documento:</u>** “12ab” 

**<u>Error: el documento solo debe contener numeros (5 a 12 digitos) Cantidad de entradas (1-6):</u>** “6” 

**<u>Error: No es posible completar la compra: no hay 6 sillas consecutivas disponibles en una misma fila y localidad</u>** 

#### **Pantalla 4: Cancelar reserva** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

# <u>Cancelar reserva</u> 

================================================================ 

**<u>Número de compra a cancelar:</u>** “xxx” 

**<u>Compra:</u>** “xxx” | Carlos Ramirez | 3 entradas | General | $360 **<u>Confirmar cancelacion (S/N):</u>** “X” 

================================================================ 

**<u>Compra cancelada. “x” sillas liberadas.</u>** 

================================================================ 

**(si no existe) No se encontró la compra “xxx”** 

#### **Pantalla 5: Disponibilidad por fila** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

# <u>Consultar</u> 

16 

================================================================ 

**<u>Fila a consultar (1-20):</u>** “x” **===Fila “x”===** 

**A | Preferencial | Disponible B | Preferencial | Disponible C | VIP              | Ocupada D | VIP              | Ocupada E | Preferencial |  Disponible F | Preferencial | Disponible Disponibles: 4  | Ocupadas: 2** 

#### **Pantalla 6: Buscar compra** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

# <u>Buscar compra</u> 

================================================================ 

**===BUSCAR COMPRA===** 

**1. Por nombre 2. Por número de documento** 

**Opción:** 2 

**Documento:** “xxxxxxxxxx” 

**Compra:** “xxx” 

================================================================ 

**Comprador:** “XX” **Documento:** “xxxxxxxxxx” **Sexo:** “x” **Entradas:** 2 **Localidad:** VIP **Valor total:** $700 

================================================================ 

**(si no existe) No se encontraron compras.** 

#### **Pantalla 7: Compras agrupadas por localidad** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

# <u>Compras por localidad</u> 

================================================================ 

===VIP=== 

#100 | xxx   | 2 entradas | $700 

===Preferencial=== 

#101 | xxx   | 2 entradas | $440 

17 

#102 | xxx   | 3 entradas | $660 ===GENERAL=== #103 | xxx   | 2 entradas | $360 #104 | xxx   | 2 entradas | $240 

#### **Pantalla 8: Sillas ocupadas** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano Sillas Ocupadas</u> 

================================================================ 

Fila | Col | Localidad   | N. compra 

1     | C    | VIP             | 100 1     | D    | VIP             | 100 

3     | E    | Preferencial | 101 

================================================================ Total de sillas ocupadas: 12 

**Pantalla 9: Totales** 

================================================================ 

# <u>PONTIFEST - Vive Javeriano</u> 

# <u>Entradas vendidas por localidad</u> 

================================================================ 

VIP: 2 Preferencial: 5 General:5 Total:12 

================================================================ 

#### **<u>INGRESOS TOTALES DEL EVENTO</u>** 

Total recaudado: $2.400 (miles de pesos) = 2.400.000 COP 

#### **Pantalla 10: Salir** 

================================================================ 

# **<u>PONTIFEST - Vive Javeriano</u>** 

# **<u>DESPEDIDA</u>** 

18 

================================================================ 

## **_<u>Gracias por usar PONTIFEST. Hasta pronto!</u>_** 

19 

