#include<iostream>
#include<string.h>
using namespace std;

struct Usuario{
    string nombre;
    string sexo;
    int edad;
};

int main(int argc, char** argv){
    
    Usuario usuarios[10];
    
    cout << "Bienvenid@ a su sistema de asistencia en salud." << "\n\nVeo que es un usuario nuevo. Por favor, cuentame un poco sobre ti." << endl;
    
    //while(!confirmar){
    
        cout <<"\nTu nombre, por favor: ";
        getline(cin,usuarios[0].nombre);
        
        cout << "Un gusto, " << usuarios[0].nombre << ".\n\n";
        
        cout << "Y dime, " << usuarios[0].nombre << ", tu eres del sexo...: ";
        getline(cin,usuarios[0].sexo);
        
        cout << "Ya veo. Excelente. Eres del sexo " << usuarios[0].sexo << ".\n\n";
//}
    return 0;
}