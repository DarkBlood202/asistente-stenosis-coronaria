#include<iostream>
#include<string.h>
using namespace std;

struct ingresos_personales{
	float salario;

};

struct ingresos_familiares{

};

void ingresarEstado(){
	cout << "\nOpcion elegida: Ingresar nuevo estado de cuenta familiar." << "\nSe procedera a ingresar los datos necesarios.\n" << endl;

	bool validacion=false;
	int opcionMenu1;

	while(!validacion){
		cout << "1. Agregar gasto." << "\n2. Agregar ingreso." << "\n3. Terminar." << endl;	
		cout << "Ingresar opcion: ";

		while(!(cin >> opcionMenu1)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nOpcion invalida. Intentelo nuevamente.\n";
			cout << "\n1. Agregar gasto." << "\n2. Agregar ingreso." << "\n3. Terminar." << endl;	
			cout << "Ingresar opcion: ";
		}

		switch(opcionMenu1){
			case 1:
				validacion=true; break;
			case 2:
				validacion=true; break;
			case 3:
				cout << endl; validacion=true; break;
			default:
				cout << "\nOpcion invalida. Intentelo nuevamente.\n\n"; break;
		}
	}
}

int main(int argc, char** argv){

	bool corriendo=true;

	while(corriendo){

		cout << "Bienvenid@ a su sistema de gestion de estado de cuenta familiar" << endl;

		bool validacion=false;
		int opcionMenu;

		while(!validacion){
			cout << "\n\tMENU DE OPCIONES" << endl;
			cout << "1. Ingresar o crear un nuevo estado de cuenta." << "\n2. Revisar estados de cuenta anteriores." << "\n3. Salir" << endl;
			cout << "Ingresar opcion: ";

			while(!(cin >> opcionMenu)){
				cin.clear();
				cin.ignore(100,'\n');
				cout << "\nOpcion invalida. Intentelo nuevamente.\n";
				cout << "\n\tMENU DE OPCIONES" << endl;
				cout << "1. Ingresar o crear un nuevo estado de cuenta." << "\n2. Revisar estados de cuenta anteriores." << "\n3. Salir" << endl;
				cout << "Ingresar opcion: ";
			}

			switch(opcionMenu){
				case 1:
					ingresarEstado();
					validacion=true; break;
				case 2:
					//verEstado();
				 	validacion=true; break;
				case 3:
				 	corriendo=false; validacion=true; break;
				default:
					cout << "\nOpcion invalida. Intentelo nuevamente.\n"; break;
				}
		}

	}

	return 0;
}