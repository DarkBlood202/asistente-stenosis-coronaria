#include<iostream>
#include<string.h>
using namespace std;

struct Usuario{
    string nombre;
    char sexo[10];
    int edad;
};

int main(int argc, char** argv){
    
    Usuario usuarios[10];
    bool confirmar_datos = false;
    
    cout << "Bienvenid@ a su sistema de asistencia en salud." << "\n\nVeo que es un usuario nuevo. Por favor, cuentame un poco sobre ti." << endl;
    
    while(!confirmar_datos){
    
        cout <<"\nTu nombre, por favor: ";
        getline(cin,usuarios[0].nombre);
        
        cout << "Un gusto, " << usuarios[0].nombre << ".\n\n";
        
        cout << "Y dime, " << usuarios[0].nombre << ", tu eres del sexo : ";
        cin.getline(usuarios[0].sexo,10,'\n');
        
        cout << "Ya veo. Excelente. Eres del sexo " << strlwr(usuarios[0].sexo) << ".\n\n";

        cout << "Por ultimo, " << usuarios[0].nombre << " , cual es tu edad: ";
        while(!(cin >> usuarios[0].edad)){
        	cin.clear();
        	cin.ignore(100,'\n');
        	cout << "Uhm... creo que te has confundido, " << usuarios[0].nombre << ".\n";
        	cout << "Por ultimo, " << usuarios[0].nombre << " , cual es tu edad: ";
        }
        
        cout << "Oh entiendo. Tienes " << usuarios[0].edad << ".\n\n";
        
        cout << "Ok. Recapitulemos, te parece?\nEres " << usuarios[0].nombre;
		cout << ", del sexo " << usuarios[0].sexo << " y con " << usuarios[0].edad << " abriles.";
		
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
				validez_respuesta=true;
				confirmar_datos=true;
			}
		}

	}
    return 0;
}
