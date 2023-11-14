/*
Programa Proyecto Integrador
Ingreso, eliminación y consulta de datos de Clientes

Fecha: 25 de Noviembre de 2022

Participantes:
- Estefanía Antonio Villaseca A01736897
- Sofía Zugasti Delgado A00837478
- Yahel Alejandro Jiménez Fernández A01736980

*/

#include <iostream>
#include <vector>
using namespace std;

//Clase que modela el objeto Cuenta bancaria, atributo de la clase Cliente, que registra los datos de cuenta de banco del usuario//
class CuentaBancaria {
public:
  string titular;
  double clabe;
  int ccv;
  string fecha;
  CuentaBancaria(string, double, int, string);
  CuentaBancaria();
};

//Clase que modela el objeto Dirección, atributo de la clase Cliente, que registra la dirección de entrega del usuario//
class Direccion {
public:
  string calle;
  int cp;
  string colonia;
  int numero;
  Direccion(string, int, string, int);
  Direccion();
};

//Clase Cliente que contiene a las clases CuentaBancaria y Dirección, que funciona para registrar a los usuarios dentro de la base de datos de la Pyme//
class Cliente {
private:
  string nombre;
  CuentaBancaria cuenta;
  Direccion direccion;

public:
  Cliente(string, CuentaBancaria, Direccion);
  Cliente();
  string getNombre();
  CuentaBancaria getCuenta();
  Direccion getDireccion();
  void setNombre(string n);
  void setCuenta(CuentaBancaria c);
  void setDireccion(Direccion d);
};

//Constructor default de la clase Cliente
Cliente::Cliente() {
}

//Constructor que recibe los datos para registrar al usuario, siendo el nombre, la cuenta y su dirección, estos 2 últimos pertenecientes a clases propias
Cliente::Cliente(string n, CuentaBancaria c, Direccion d) {
  nombre = n;
  cuenta = c;
  direccion = d;
}

//Getter que regresa la variable privada "nombre"
string Cliente::getNombre() { 
	return nombre;
}

//Getter que regresa la variable privada "cuenta"
CuentaBancaria Cliente::getCuenta() { 
	return cuenta;
}

//Getter que regresa la variable privada "direccion"
Direccion Cliente::getDireccion() { 
	return direccion; 
}

//Setter para el nombre del usuario
void Cliente::setNombre(string n) { 
	nombre = n; 
}

//Setter para la variable de tipo CuentaBancaria
void Cliente::setCuenta(CuentaBancaria c) { 
	cuenta = c; 
}

//Setter para la variable de tipo Direccion
void Cliente::setDireccion(Direccion d) { 
	direccion = d; 
}

//Constructor default de Direccion
Direccion::Direccion() {
}

//Constructor que recibe los datos de dirección del usuario para construir la variable del mismo tipo
Direccion::Direccion(string ca, int c_p, string co, int num) {
  calle = ca;
  cp = c_p;
  colonia = co;
  numero = num;
}

//Constructor default de CuentaBancaria
CuentaBancaria::CuentaBancaria() {
}

//Constructor que recibe los datos de cuenta del usuario para construir la variable del mismo tipo
CuentaBancaria::CuentaBancaria(string ti, double claBe, int c_cv, string fe) {
  titular = ti;
  clabe = claBe;
  ccv = c_cv;
  fecha = fe;
}

int main() {
  //se inician las variables vacías para poder irlas llenando conforme el empleado registra clientes
  string nombreA = "";
  string calleA = "";
  int cpA = 0;
  string coloniaA = "";
  int numeroCasaA = 0;
  string nombreTitularA = "";
  double clabeA = 0;
  int ccvA = 0;
  string fechaA = "";

//Arreglo que contiene a los clientes agregados con valores de tipo Cliente
  vector<Cliente> vectorCliente;

//Variables para hacer funcionar el menú while
  int seleccion = 0;
  int clienteEliminado = 0;

//Estructura del menú iniciado con un Do y que se detendrá cuando se reciba un 0, usando un While
  do {
  //Explicación de las opciones del menú
    cout << "Utiliza alguna de las opciones disponibles " << endl << "Menú Clientes:" << endl << "1. Agregar Cliente" << endl<< "2. Eliminar Cliente" << endl << "3. Imprimir Clientes" << endl << "0. Salir" << endl;

  //Inputs para determinar la opción a ejecutar
    cin >> seleccion;
    cout<<endl;
  //Funcionamiento de la opción 1 agregar, que recibe datos en cada variable y ejecuta las clases para construir el arreglo de objetos de tipo Cliente  
    if (seleccion == 1) {

      cout << "--DATOS DEL CLIENTE--" << endl;
			cout<< "Nombre del cliente: "<<endl;
			cin>>nombreA;
			
      cout << "Calle: "<<endl;
      cin>>calleA;

      cout << "Colonia: "<<endl;
      cin>>coloniaA;

      cout << "Número de Casa: "<<endl;
      cin >> numeroCasaA;

      cout << "Código Postal: "<<endl;
      cin >> cpA;

      cout << "-DATOS DE LA TARJETA BANCARIA-" << endl;
      cout << "Titular de tarjeta de banco: "<<endl;
      cin>> nombreTitularA;

      cout << "Clabe: "<<endl;
      cin >> clabeA;

      cout << "CCV: "<<endl;
      cin >> ccvA;

      cout << "Fecha: "<<endl;
      cin>> fechaA;

      cout<<"\n"<<endl;
      cout << "Cliente añadido con éxito!\n" << endl;

      Direccion direccionDefault(calleA, cpA, coloniaA, numeroCasaA);
      CuentaBancaria cuentaDefault(nombreTitularA, clabeA, ccvA, fechaA);
      Cliente clienteDefault(nombreA, cuentaDefault, direccionDefault);

    //Una vez construído el objeto cliente, el programa lo agrega al final del vector
      vectorCliente.push_back(clienteDefault);
    }

  //Ejecución de la opción 2 aplicada con un else if para concatenar todas las opciones. Esta sección desplega todos los elementos del arreglo vectorial de objetos de tipo cliente enumerados para facilitar la eliminación
    else if (seleccion == 2) {
      for (int i = 0; i < vectorCliente.size(); ++i) {
        cout << "---Cliente " << i + 1 << "---" << endl;
        cout << "Nombre: " << vectorCliente[i].getNombre() << endl;

        cout << "--DATOS DE DIRECCIÓN--" << endl;
        cout << "Calle: " << vectorCliente[i].getDireccion().calle << endl;
        cout << "Código Postal: " << vectorCliente[i].getDireccion().cp << endl;
        cout << "Colonia: " << vectorCliente[i].getDireccion().colonia << endl;
        cout << "Número de casa: " << vectorCliente[i].getDireccion().numero
             << endl;

        cout << "--DATOS DE CUENTA BANCARIA--" << endl;
        cout << "Titular: " << vectorCliente[i].getCuenta().titular << endl;
        cout << "Clabe: " << vectorCliente[i].getCuenta().clabe << endl;
        cout << "CCV: " << vectorCliente[i].getCuenta().ccv << endl;
        cout << "Fecha: " << vectorCliente[i].getCuenta().fecha << endl;
        cout << endl;
      }

    //Se elimina el cliente y se recorren los demás elementos para alinearse y rellenar el espacio vacío
      cout << "Ingrese el número del cliente a eliminar: "<<endl;
      cin >> clienteEliminado;
      vectorCliente.erase(vectorCliente.begin() + (clienteEliminado - 1));
      cout << "Cliente eliminado exitosamente!\n" << endl;
    }

  //Esta sección reutiliza el código en la opción 2 para sólo desplegar todos los clientes existentes
    else if (seleccion == 3) {
      for (int i = 0; i < vectorCliente.size(); ++i) {
        cout << "---Cliente " << i + 1 << "---" << endl;
        cout << "Nombre: " << vectorCliente[i].getNombre() << endl;

        cout << "--DATOS DE DIRECCIÓN--" << endl;
        cout << "Calle: " << vectorCliente[i].getDireccion().calle << endl;
        cout << "Código Postal: " << vectorCliente[i].getDireccion().cp << endl;
        cout << "Colonia: " << vectorCliente[i].getDireccion().colonia << endl;
        cout << "numeroCasa: " << vectorCliente[i].getDireccion().numero
             << endl;

        cout << "--DATOS DE CUENTA BANCARIA--" << endl;
        cout << "Titular: " << vectorCliente[i].getCuenta().titular << endl;
        cout << "Clabe: " << vectorCliente[i].getCuenta().clabe << endl;
        cout << "CCV: " << vectorCliente[i].getCuenta().ccv << endl;
        cout << "Fecha: " << vectorCliente[i].getCuenta().fecha << endl;
        cout << endl;
      }
			
    }
  //Elif que envía mensaje de despedida al momento de cerrar el programa
    else if (seleccion==0){
      cout<< "Esperamos el programa le haya sido de utilidad, hasta pronto!" << endl;
    }
  //En caso de teclear una opción no disponible, así responde el programa
    else{
      cout<<"Esa opción no está disponible, escoje alguna del menú\n"<< "desplegado\n"<< endl;
    }

  } while (seleccion != 0);

  return 0;
}