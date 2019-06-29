#include<iostream> //entrada y salida estandar de c++
#include<string.h> //manejo de cadenas
#include<fstream> //manejo de archivos
#include<exception> //manejo de excepciones
#include<stdlib.h> //acceso a algunas funciones como random
#include<time.h> //acceso al tiempo del sistema
#include<stdio.h> //entrada y salida estandar de c
using namespace std;

//ubicacion y nombre del archivo
char ubicacion_registro[] = "user.txt";
char archivo_diagnosticos[] = "diag.txt";

//estructura reporte medico
struct Dolor_Torax{
	bool existe;
	int intensidad;
	int duracion_min;
	bool cede;
};

struct Reporte{
	Dolor_Torax dolor_torax;
	bool estres;
	bool arritmia;
	bool agotamiento;
	bool hinchazon;
	bool nauseas;
	bool insomnio;
	int contador;
};

//estructura usuario
struct Usuario{
    string nombre;
    char sexo[10];
    int edad;
    Reporte reporte;
};

//tiempo local con formato
string tiempo_actual(){
	time_t ahora = time(NULL); //obtener el tiempo actual del sistema (segundos desde el 01/01/1900)
	tm *ltm = localtime(&ahora); //crea la estructura ltm de tipo tm tomando como argumento los segundos
	
	char tiempo_en_cadena[30]; //crea arreglo de caracteres para guardar el tiempo en formato cadena
	memset(tiempo_en_cadena,0x0,30); //inicializa el arreglo de caracteres para evitar caracteres basura
	
	/*funcion de C que permite tomar diferentes valores (ejm numericos) y convertirlos a formato cadena
	y luego guardarlo en un arreglo de caracteres
	* ltm -> tm_day // apartado dia de la estructura de tiempo ltm (y asi consecuentemente)*/
	sprintf(tiempo_en_cadena,"%d/%d/%d",ltm->tm_mday, ltm->tm_mon, ltm->tm_year+1900);
	
	return tiempo_en_cadena; //retorna la cadena con la fecha actual del sistema
}

//linea divisoria de texto
void linea_divisoria(int n){
	for(int i=0;i<n;i++){
		for(int j=0; j<80; j++){
			cout << "-";
		}
		if(n>1){cout << endl;}
	}
}

//frases de presentacion de informacion
void frase_presentar_informacion(){
	srand(time(NULL));
	int indice_frase = rand() % 10;
	switch(indice_frase){
		case 0:	cout << "\nPor supuesto. Aqui te presento la informacion que poseo:\n"; break;
		case 1:	cout << "\nEsta es la informacion que tengo al respecto:\n"; break;
		case 2:	cout << "\nHe podido encontrar esto:\n"; break;
		case 3:	cout << "\nPresentando informacion:\n"; break;
		case 4:	cout << "\nLa siguiente informacion le puede ser util:\n"; break;
		case 5:	cout << "\nEsto he podido recabar:\n"; break;
		case 6:	cout << "\nAqui tiene la informacion recolectada:\n"; break;
		case 7:	cout << "\nAqui te muestro lo que tengo a mi disposicion.\n"; break;
		case 8:	cout << "\nProcedo a mostrarle la informacion:\n"; break;
		case 9:	cout << "\nMira lo que te traigooo (-w-)/ !!!:\n"; break;
	}
}

//informacion sobre stenosis coronaria al usuario
void informacion(){
	
	linea_divisoria(2);
	
	int opcion_menu;
	bool menu = true;
	
	while(menu){
		cout << "\nPor favor elige el apartado del cual deseas saber:\n\n\t1.Que es la stenosis coronaria." <<
		"\n\t2.Causas de la enfermedad." << "\n\t3.Tratamiento de la enfermedad." << "\n\t4.Regresar al menu principal.";
		cout << "\n\tIngrese opcion: ";
		while(!(cin>>opcion_menu)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n\nUhm... Te has confundido. Por favor, ingresa una opcion valida.\n\n";
			cout << "\tIngrese opcion: ";
		}
		
		switch(opcion_menu){
			case 1:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\t\tSTENOSIS CORONARIA\n\n" <<
				"La stenosis coronaria o tambien llamada cardiopatia isquemica, es una\n" <<
				"enfermedad ocasionada por la arteriosclerosis de las arterias coronarias.\n" <<
				"Estas, son las encargadas de proporcionar sangre al musculo cardiaco. La\n" <<
				"arteriosclerosis coronaria es un proceso lento de acumulacion de grasas y\n" <<
				"linfocitos que provocan el estrechamiento de las arterias coronarias.\n" <<
				"Este proceso inicia en las primeras decadas de vida pero es asintomatico\n" <<
				"hasta que la oclusion es tan grave que causa un desequilibrio en el aporte\n" <<
				"de oxigeno al miocradio, provocando asi, una isquemia miocardica o una\n" <<
				"oclusion subita por trombosis de la arteria. Esto concluye finalmente\n" <<
				"en el sindrome coronario agudo, mas conocido como infarto agudo de\n" <<
				"miocardio.\n";
				linea_divisoria(1);
				break;
			case 2:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\t\tCAUSAS DE LA STENOSIS CORONARIA\n\n" <<
				"Los principales factores que producen la enfermedad son:\n" <<
				"- Edad avanzada.\n- Menopausia.\n- Antecedentes de la enfermedad en la familia.\n" <<
				"- Aumento del colesterol LDL (malo).\n- Disminucion del colesterol HDL (bueno).\n" <<
				"- Tabaquismo.\n- Hipertension arterial.\n- Diabetes miellitus.\n- Obesidad.\n" <<
				"- Sedentarismo.\n- Haber padecido previamente la enfermedad.\n";
				linea_divisoria(1);
				break;
			case 3:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\t\tTRATAMIENTO DE LA STENOSIS CORONARIA\n\n" <<
				"Se deben controlar estrictamente los factores de riesgo cardiovascular\n" <<
				"y seguir chequeos periodicos para prevenir la aparicion de nuevos riesgos.\n" <<
				"De existir, deben corregirse inmediatamente:\n" <<
				"- Dejar el tabaco.\n- Vigilar la hipertension y diabetes.\n" <<
				"- Llevar una dieta baja en colesterol y grasas.\n- Alcanzar un peso ideal.\n" <<
				"- Reducir el colesterol hasta obtener una medida de LDL menor a 70mg/dl.\n";
				linea_divisoria(1);
				break;
			case 4:
				linea_divisoria(2);
				menu = false; break;
			default:
				cout << "\n\nUhm... Te has confundido. Por favor, ingresa una opcion valida.\n\n"; break;
		}	
	}
}

//hacer pregunta para diagnostico y guardar informacion a la estructura
template<class valor> //plantilla de funcion
void hacer_pregunta(string pregunta, valor& dato, bool sn){
	bool validez=false;
	int opcion;
	linea_divisoria(1);
	while(!validez){
		cout << endl <<pregunta << endl << endl;
		if(sn){cout << "1.Si\t2.No\t3.No lo se\n\nTu respuesta: ";}
		else{cout << "\nTu respuesta: ";}
		while(!(cin>>opcion)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n\nERROR. Por favor introduce una opcion valida.\n\n";
			cout << pregunta << endl;
			if(sn){cout << "1.Si\t2.No\t3.No lo se\n\nTu respuesta: ";}
		}
		if(sn){
			switch(opcion){
				case 1:	dato=true; validez=true; break;
				case 2: dato=false; validez=true; break;
				case 3: validez=true; break;
				default: cout << "\n\nERROR. Por favor introduce una opcion valida.\n\n";
			}
		}
		else{
			dato = opcion;
			validez = true;
		}
	}
}

//mostrar resultado al usuario (formato que el pueda entender)
template<class val> //plantilla de funcion
void mostrar_resultado(string categoria, val valor, bool sn){
	cout << categoria << ": ";
	if(sn){
		switch(valor){
			case 0: cout << "\t\t\tNo"; break;
			case 1: cout << "\t\t\tSi"; break;
			default: cout << "\t\t\tNo lo se"; break;
		}
	}
	else{
		cout << "\t\t" << valor;
	}
	cout << endl;
}

//devolver resultado como cadena para anadir al archivo facilmente
template<class val> //plantilla de funcion
string resultado_como_cadena(string categoria, val valor, bool sn){
	
	char cat[categoria.length()+1]; //crear arreglo de caracteres con tama�o de la string categoria +1
	memset(cat,0x0,categoria.length()+1); //inicializa el arreglo con elementos nulos para evitar caracteres basura
	
	strcpy(cat,categoria.c_str()); //copia el valor de categoria (String) a cat (arreglo)
	
	char respuesta[20]; //crea arreglo para respuesta
	memset(respuesta,0x0,20); //inicializa el arreglo con elementos nulos para evitar caracteres basura
	
	char resultado[50]; //crea arreglo para resultado
	memset(resultado,0x0,50); //inicializa el arreglo con elementos nulos para evitar caracteres basura
	
	strcat(cat,": "); //agrega al arreglo cat el arreglo ": "
	
	if(sn){
		switch(valor){
			case 0: strcpy(respuesta,"\t\t\tNo"); break; //copia el valor de "\t\t\tNo" al arreglo respuesta
			case 1: strcpy(respuesta,"\t\t\tSi"); break; //copia el valor de "\t\t\tNo" al arreglo respuesta
			default: strcpy(respuesta,"\t\t\tNo lo se"); break; //copia el valor de "\t\t\tNo lo se" al arreglo respuesta
		}
	}
	else{
		strcpy(respuesta,"\t\t"); //copia el valor del arreglo "\t\t" al arreglo respuesta
		
		char valor_en_cadena[5]; //crea arreglo para guardar el valor numerico
		memset(valor_en_cadena,0x0,5); //inicializ el arreglo con elementos nulos para evitar caracteres basura
	 
  		sprintf(valor_en_cadena,"%d",valor); //funcion de c para convertir un valor numerico en formato arreglo y guardarlo en el arreglo
	
		strcat(respuesta,valor_en_cadena); //agrega al arreglo respuesta el arreglo valor_en_cadena que es el numero convertido
		
	}
	strcat(resultado,cat); //en teoria: "categoria: "
	strcat(resultado,respuesta); //en teoria: "categoria: respuesta"
	
	string cadena_resultado(resultado); //convierte de arreglo de caracteres (resultado) a clase String (cadena_resultado)
	
	return cadena_resultado; //retorna la cadena como clase String
}

//evaluacion de diagnostico
void diagnostico(Usuario user){
	
	bool confirmar_datos = false;
	
	while(!confirmar_datos){

		linea_divisoria(2);
		cout << "\nMuy bien. Realicemos un diagnostico rapidamente, " << user.nombre << ".\n" <<
		"Te hare algunas preguntas, de acuerdo?\n\n";
		
		hacer_pregunta("Sufres de estres?",user.reporte.estres,true);
		hacer_pregunta("Has experimentado arritmia cardiaca?",user.reporte.arritmia,true);
		hacer_pregunta("Sientes agotamiento constantemente?",user.reporte.agotamiento,true);
		hacer_pregunta("Has notado hinchazon en partes de tu cuerpo?",user.reporte.hinchazon,true);
		hacer_pregunta("Has sufrido episodios de nausea?",user.reporte.nauseas,true);
		hacer_pregunta("Presentas dificultad para dormir?",user.reporte.insomnio,true);
		
		hacer_pregunta("En algun momento has sentido dolor en la zona superior de tu cuerpo?",user.reporte.dolor_torax.existe,true);
		if(user.reporte.dolor_torax.existe){
			hacer_pregunta("Que tan intenso es ese dolor?\nRANGO: [1]Poco intenso a Muy intenso[9]",user.reporte.dolor_torax.intensidad,false);
			hacer_pregunta("Cuanto aproximadamente dura ese dolor en minutos?",user.reporte.dolor_torax.duracion_min,false);
			hacer_pregunta("El dolor cede pasado ese tiempo?",user.reporte.dolor_torax.cede,true);
		}
		
		linea_divisoria(1);
		
		cout << "\nEstos son los datos que has introducido:\n\n";
		
		mostrar_resultado("ESTRES",user.reporte.estres,true);
		mostrar_resultado("ARRITMIA",user.reporte.arritmia,true);
		mostrar_resultado("AGOTAMIENTO",user.reporte.agotamiento,true);
		mostrar_resultado("HINCHAZON",user.reporte.hinchazon,true);
		mostrar_resultado("NAUSEAS",user.reporte.nauseas,true);
		mostrar_resultado("INSOMNIO",user.reporte.insomnio,true);
		mostrar_resultado("DOLOR_TORAX",user.reporte.dolor_torax.existe,true);
		if(user.reporte.dolor_torax.existe){
			mostrar_resultado("INTENSIDAD DOLOR",user.reporte.dolor_torax.intensidad,false);
			mostrar_resultado("DURACION DOLOR(MIN)",user.reporte.dolor_torax.duracion_min,false);
			mostrar_resultado("EL DOLOR CEDE",user.reporte.dolor_torax.cede,true);
		}
		
		bool validez_respuesta = false;
		string respuesta_sn;
		
		fflush(stdin);
		
		while(!validez_respuesta){
			cout << "\n\nConfirma que los datos ingresados son correctos? (S/N)\nIngrese su respuesta:";
			getline(cin,respuesta_sn);
			if (respuesta_sn == "N" || respuesta_sn == "n"){
				cout << "\nComprendido. Intentemoslo nuevamente.\n";
				validez_respuesta=true;
			}
			else if(respuesta_sn == "S" || respuesta_sn == "s"){
				
				//proceso de guardado de resultados de evaluacion a archivo
				ofstream diag; //creacion de archivo de diagnostico
				diag.open(archivo_diagnosticos,ios::app); //abrir archivo de diagnostico en modo agregar
				if(diag.fail()){ //si no puede crearse el archivo
					cout << "\n\nSe produjo un error al generar el archivo de diagnosticos.";
					throw exception(); //enviar mensaje de error y cerrar el programa
				}
				
				//se guarda linea por linea cada resultado en formato cadena legible para el usuario
				
				diag << "======================================================" << "\n"
				<< "\t\t" << "DIAGNOSTICO DE: " << user.nombre << "\n"
				<< "\t\tgenerado el " << tiempo_actual() << "\n"
				<< "======================================================" << endl;
				
				diag << resultado_como_cadena("ESTRES",user.reporte.estres,true) << "\n"
				<< resultado_como_cadena("ARRITMIA",user.reporte.arritmia,true) << "\n"
				<< resultado_como_cadena("AGOTAMIENTO",user.reporte.agotamiento,true) << "\n"
				<< resultado_como_cadena("HINCHAZON",user.reporte.hinchazon,true) << "\n"
				<< resultado_como_cadena("NAUSEAS",user.reporte.nauseas,true) << "\n"
				<< resultado_como_cadena("INSOMNIO",user.reporte.insomnio,true) << "\n"
				<< resultado_como_cadena("DOLOR_TORAX",user.reporte.dolor_torax.existe,true) << endl;
				
				if(user.reporte.dolor_torax.existe){
					diag << resultado_como_cadena("INTENSIDAD DOLOR",user.reporte.dolor_torax.intensidad,false) << "\n"
					<< resultado_como_cadena("DURACION DOLOR(MIN)",user.reporte.dolor_torax.duracion_min,false) << "\n"
					<< resultado_como_cadena("EL DOLOR CEDE",user.reporte.dolor_torax.cede,true) << endl;
				}
				
				diag << "------------------------------------------------------" << endl;
				
				diag.close(); //se cierra el archivo
				
				cout << "\n\n...Guardando Datos...\n\n";
				linea_divisoria(2);
    			validez_respuesta=true;
				confirmar_datos=true;
			}
		}
	}
}

//leer diagnosticos desde archivo de diagnosticos
void leer_diagnosticos(){
	
	bool continuar=true;
	
	ifstream diag;
	diag.open(archivo_diagnosticos,ios::in);
	if(diag.fail()){
		cout << "\n\nERROR. NO EXISTE NINGUN ARCHIVO DE DIAGNOSTICO.\n\n";
		//hacer algo que aun no se que es uu
	}
	
	string linea_de_texto;
	
	int diagnostico_actual = 0;
		
	int linea_actual = 0;
	int lineas_totales = 0;
		
	int tamano_diagnostico = 15;
	int limite_inferior;
	int limite_superior;
	
	bool volver_a_inicio = false;
	
	//contar lineas totales en el archivo de diagnostico
	while(!diag.eof()){
		lineas_totales++;
		getline(diag,linea_de_texto);
	}
	
	lineas_totales--; //evitar el salto de linea final
	
	//cout << endl << "TOTAL LINEAS: " << lineas_totales << endl;
	
	int maximos_diagnosticos = (lineas_totales/tamano_diagnostico)-1;
	
	//cout << endl << "MAX DIAG: " << maximos_diagnosticos+1 << endl;
	
	int opcion;
	
	while(continuar){//parte que se llamara varias veces para ver diferentes diagnosticos (bloques de texto en el archivo)
	
		limite_inferior = 1 + (tamano_diagnostico*diagnostico_actual);
		//cout << endl << "LI: " << limite_inferior << endl;
		limite_superior = tamano_diagnostico + (tamano_diagnostico*diagnostico_actual);
		//cout << endl << "LS: " << limite_superior << endl;
		
		if(diag.eof() && !volver_a_inicio){
			diag.clear();
			diag.seekg(0,ios::beg);
			linea_actual = 0;
			volver_a_inicio = true;
		}
		
		while(!diag.eof()){ //leyendo linea por linea el archivo e imprime unicamente las lineas dentro de los limites
			//cout << endl << "LINEA ACTUAL: " << linea_actual << endl;
			linea_actual++;
			getline(diag,linea_de_texto);
			if(linea_actual >= limite_inferior && linea_actual <= limite_superior){
				cout << linea_de_texto << endl;
			}
		}
		
		if(maximos_diagnosticos > 0){
			
			if(diagnostico_actual==0){cout << "\n\n \t\t\t\tVER SIGUIENTE[2]->\n\n";}
			else if(diagnostico_actual==maximos_diagnosticos){cout << "\n\n<-[1]VER ANTERIOR\n\n";}
			else{cout << "\n\n<-[1]VER ANTERIOR\t\tVER SIGUIENTE[2]->\n\n";}
			
			cout << "Salir[3]\n";
			cout << "Introduzca opcion: ";
			
			while(!(cin>>opcion)){
				cin.clear();
				cin.ignore(100,'\n');
				cout << "\n\nOh!Vaya...Te has equivocado. Intentalo nuevamente.\n\n";
				cout << "Introduzca opcion: ";
			}
			
			switch(opcion){
				case 1:
					if(diagnostico_actual==0){
						cout << "\n\nOh!Vaya...Te has equivocado. Intentalo nuevamente.\n\n";
						linea_actual = 0;
						volver_a_inicio = false;
						break;
					}
					diagnostico_actual--;
					linea_actual = 0;
					volver_a_inicio = false;
					break;
				case 2:
					if(diagnostico_actual==maximos_diagnosticos){
						cout << "\n\nOh!Vaya...Te has equivocado. Intentalo nuevamente.\n\n";
						break;
					}
					diagnostico_actual++;
					linea_actual = 0;
					volver_a_inicio = false;
					break;
				case 3:
					diag.close();
					linea_actual = 0;
					continuar=false;
					break;
				default:
					cout << "\n\nOh!Vaya...Te has equivocado. Intentalo nuevamente.\n\n";
					linea_actual = 0;
					volver_a_inicio = false;
					break;
			}
		}
	}
}

//guardar datos al archivo
void guardar_datos(Usuario user){
    ofstream registro; //crear un archivo referido por variable registro
    registro.open(ubicacion_registro,ios::app); //abrir archivo en la ubicacion, en modo agregar
    if(registro.fail()){ //si no puede crearse el archivo
        cout << "\n\nSe produjo un error al crear el archivo de datos.";
        throw exception(); //enviar mensaje de error y terminar el programa.
    }
    
    registro << user.nombre << "\n"
	<< user.sexo << "\n"
	<< user.edad << endl;
    
    registro.close();
    
    cout << "\n(Se han guardado los datos)\n\n";
}

//cargar usuario desde el archivo a la estructura
void cargar_usuario(Usuario& user){
	ifstream registro; //abrir archivo en modo lectura
	registro.open(ubicacion_registro,ios::in); //abriendo archivo en modo lectura de la ubicacion dada
	if(registro.fail()){
		cout << "\n\nSe produjo un error al leer el archivo de datos.";
		throw exception();
	}
	
	getline(registro,user.nombre); //cargando el nombre
	registro.getline(user.sexo,10,'\n'); //cargando el sexo
	
	string cadena_edad; //se define una cadena que tendra el valor de la edad
	int linea_archivo=0; //se crea un iterador que cuenta las lineas del archivo
	int linea_edad=3; //linea en el archivo donde se encuentra la edad
	
	//mientras el numero de linea no sea la deseada (en este caso la edad) y exista esa linea en el archivo
	while(linea_archivo != linea_edad && getline(registro,cadena_edad)){
		++linea_archivo; //se aumenta el valor de la variable iterativa para pasar de lineas hasta la deseada
	}
	if(linea_archivo == linea_edad){
		//se llega a la linea deseada, pero se lee en formato string, por lo que se convierte a int para guardarlo en la estructura
		user.edad = atoi(cadena_edad.c_str());
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
        
        cout << "Y dime, " << usuario.nombre << ", tu eres del sexo: ";
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
void menu(Usuario usuario){
	bool confirmar_opcion = false;
	int opcion_menu;
	
	while(!confirmar_opcion){
		cout << "\n\tMENU PRINCIPAL\n";
		cout << "1.Informacion.\n2.Iniciar evaluacion de diagnostico.\n3.Revisar previas evaluaciones.\n4.Salir.";
		cout << "\nIngrese opcion: ";
	
		while(!(cin>>opcion_menu)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
			cout << "Ingrese opcion: ";
		}
	
		switch(opcion_menu){
			case 1:
				informacion();
				break;
			case 2:
				diagnostico(usuario);
				break;
			case 3:
				leer_diagnosticos();
				break;
			case 4:
				confirmar_opcion = true; break;
			default:
				cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
		}
	}
}

int main(int argc, char** argv){
    
    Usuario usuario;
    
    ifstream registro;
    registro.open(ubicacion_registro,ios::in);
    if(registro.fail()){
    	primer_uso(usuario);
    	linea_divisoria(2);
    	cargar_usuario(usuario);
    }
    else{
    	cargar_usuario(usuario);
    	cout << "Bienvenid@ de vuelta, " << usuario.nombre << "!\n";
    }
    menu(usuario);

    return 0;
}
