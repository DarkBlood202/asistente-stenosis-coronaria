#include<iostream>
#include<string.h>
#include<fstream>
#include<exception>
using namespace std;

/*//puntero hacia la ubicacion y nombre del archivo
string ubicacion_registro = "data.txt";
string *a_ubicacion= &ubicacion_registro;*/

//estructura usuario
struct Usuario{
    string nombre;
    char sexo[10];
    int edad;
};

//guardar datos al archivo
void guardar_datos(Usuario user){
    ofstream registro;
    registro.open("data.txt",ios::app);
    if(registro.fail()){
        cout << "\n\nHubo un error al tratar de abrir el arhivo de datos.";
        throw exception();      
    }
    
    registro /*<< "Nombre: " */<< user.nombre << "\n" <<
	 /*"Sexo: " <<*/ user.sexo << "\n" <<
	  /*"Edad: " <<*/ user.edad << "\n\n";
    
    cout << "\n(Se han guardado los datos)\n\n";
    
    registro.close();
}

//leer nombre desde el archivo
string leer_nombre(){
	ifstream registro;
	registro.open("data.txt",ios::in);
	if(registro.fail()){
		
	}
	else{
		string nombre_de_usuario;
		getline(registro,nombre_de_usuario);
		registro.close();
		return nombre_de_usuario;
	}
}

//primer uso del programa
void primer_uso(Usuario usuario){
	bool confirmar_datos = false;

	cout << "Bienvenid@ a su sistema de asistencia en salud." << "\n\nVeo que es un usuario nuevo. Por favor, cuentame un poco sobre ti." << endl;

	//si datos no son correctos, se sigue preguntando por ellos
    while(!confirmar_datos){
    
        cout <<"\nTu nombre, por favor: ";
        getline(cin,usuario.nombre);
        
        cout << "Un gusto, " << usuario.nombre << ".\n\n";
        
        cout << "Y dime, " << usuario.nombre << ", tu eres del sexo : ";
        cin.getline(usuario.sexo,10,'\n');
        
        cout << "Ya veo. Excelente. Eres del sexo " << /*strlwr(*/usuario.sexo/*)*/ << ".\n\n";

        cout << "Por ultimo, " << usuario.nombre << " , cual es tu edad: ";
        //validacion de numero entero
        while(!(cin >> usuario.edad)){
        	cin.clear();
        	cin.ignore(100,'\n');
        	cout << "Uhm... creo que te has confundido, " << usuario.nombre << ".\n";
        	cout << "Por ultimo, " << usuario.nombre << " , cual es tu edad: ";
        }
        
        cout << "Oh entiendo. Tienes " << usuario.edad << ".\n\n";
        
        cout << "Ok. Recapitulemos, te parece?\nEres " << usuario.nombre;
		cout << ", del sexo " << usuario.sexo << " y tienes " << usuario.edad << " anios de edad.";
		
		//limpiar el buffer
  		fflush(stdin);
  		
		bool validez_respuesta=false;
		string respuesta_sn;
		
		while(!validez_respuesta){
			cout << "\n\nSon correctos estos datos? (S/N)\nIngrese su respuesta: ";
			getline(cin,respuesta_sn);
			if (respuesta_sn == "N" || respuesta_sn == "n"){
				cout << "\nComprendido. Intentemoslo nuevamente.\n";
				validez_respuesta=true;
			}
			else if(respuesta_sn == "S" || respuesta_sn == "s"){
				cout << "\nEsplendido. Entonces comencemos.\n";
				guardar_datos(usuario);
    			validez_respuesta=true;
				confirmar_datos=true;
			}
		}

	}
}

//menu de opciones
void menu(){
	bool confirmar_opcion = false;
	int opcion_menu;
	
	cout << "\tMENU DE OPCIONES\n";
	cout << "1.Informacion sobre la stenosis coronaria.\n2.Iniciar evaluacion de diagnostico.\n3.Revisar previas evaluaciones.\n4.Salir.";
	cout << "\nIngrese opcion: ";

	while(!(cin>>opcion_menu)){
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
		cout << "Ingrese opcion: ";
	}

	switch(opcion_menu){
		case 1:
			confirmar_opcion = true; break;
		case 2:
			confirmar_opcion = true; break;
		case 3:
			confirmar_opcion = true; break;
		case 4:
			confirmar_opcion = true; break;
		default:
			cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
	}
}

int main(int argc, char** argv){
    
    Usuario usuario;
    
    ifstream registro;
    registro.open("data.txt",ios::in);
    if(registro.fail()){
    	primer_uso(usuario);
    }
    else{
    	cout << "Bienvenid@ de vuelta, " << leer_nombre() << "!\n\n";
    	
    }
    menu();
    

    return 0;
}
