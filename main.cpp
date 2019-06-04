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
    
    cout << "Bienvenid@ a su sistema de asistencia en salud." << "\n\nVeo que es un usuario nuevo. Por favor, cuentame un poco sobre ti." << endl;
    
    //while(!confirmar){
    
        cout <<"\nTu nombre, por favor: ";
        getline(cin,usuarios[0].nombre);
        
        cout << "Un gusto, " << usuarios[0].nombre << ".\n\n";
        
        cout << "Y dime, " << usuarios[0].nombre << ", tu eres del sexo : ";
        cin.getline(usuarios[0].sexo,10,'\n');
        
        cout << "Ya veo. Excelente. Eres del sexo " << strlwr(usuarios[0].sexo) << ".\n\n";

        cout << "Por ultimo, " << usuarios[0].nombre << " , cual es tu edad: ";
        cin >> usuarios[0].edad;
        
        cout << "Oh entiendo. Tienes " << usuarios[0].edad << ".\n\n";


//}
    return 0;
}
