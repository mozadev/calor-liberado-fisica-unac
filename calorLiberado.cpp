#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

float calorLiberado(float,float, float, float);// funcion sobrecargada calor liberado de un material de un solo espesor
float calorLiberado(float,float, float, float,float,float, float, float);// funcion sobrecargada calor liberador de un material de 3 espesores

float area; // declaramos variable global ya que no esta incluida dentro de los parametros

int main()
{
	
	cout << "ingrese el area del material en m2: ";// ingresarmos el area del material
	cin >> area;// capturando la entrada de la consola y guardandola en la variable area
	int opcion; // variable para el menu de opciones
	bool repetir=true; // variable booleeana para el menu si es true sigue preguntando, si es false sale del  bucle de preguntas
	
	do {  // do while -> hacer mientras , es decir va seguir mostrando el menu hasta q le digamos q no
		
		
		// mostrando las opciones
		cout << "\t\t\tMenu de Opciones" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\n\t1. Calor liberado de 1 espesor:" << endl;
		cout << "\t2. Calor liberado de  3 espesores" << endl;
		cout << "\t0. SALIR" << endl;
		
		cout << "\tIngrese una opcion: ";
		cin >> opcion; // variable q va ser pasada como parametro dentro del switch para seleccionar el caso a ejecutar
		
		
		switch (opcion) {
			// declaramos las variables que van ser usadas segun el caso
			float conduct_1, temp_int, temp_ext,espesor_1;
			float conduct_2, conduct_3;
			float espesor_2, espesor_3;
			
			//=========================CASO 1: Calor liberado 1 espesor  (4 parametros) ===================================
		case 1:
			
			cout << "\tIngrese conductividad (W/m*K): ";
			cin >> conduct_1;
			
			cout << "\tIngrese temperatura interior en kelvin (k): ";
			cin >> temp_int;
			
			cout << "\tIngrese temperatura exterior en kelvin (k): ";
			cin >> temp_ext;
			
			cout << "\tIngrese espesor en metros (m) : ";
			cin >> espesor_1;
			
			cout << "\t---------------------------" << endl;
			
			// Invocamos a la funcion y le pasamos los 4 parametros, el area es variable global para q nos devuelva el valor de
			// tipo float del calor liberado
			cout << "\t Calor liberado 1 espesor  (4 parametros)  " << " es: "
				<< calorLiberado(conduct_1,temp_int,temp_ext,espesor_1)<<" W"<<endl;
			
		
			break;
			
			//=========================CASO 2: Calor liberado 3 espesores ( 8 parametros) ===================================
		case 2:
			cout << "\tIngrese conductividad material 1 (W/m*K): ";
			cin >> conduct_1;
			
			cout << "\tIngrese conductividad material 2 (W/m*K): ";
			cin >> conduct_2;
			
			cout << "\tIngrese conductividad material 3 (W/m*K): ";
			cin >> conduct_3;
			
			cout << "\tIngrese temperatura interior en kelvin (k) : ";
			cin >> temp_int;
			
			cout << "\tIngrese temperatura exterior en kelvin (k): ";
			cin >> temp_ext;
			
			cout << "\tIngrese espesor material 1 en metros (m) : ";
			cin >> espesor_1;
			
			cout << "\tIngrese espesor material 2 en metros (m): ";
			cin >> espesor_2;
			
			cout << "\tIngrese espesor material 3 en metros (m): ";
			cin >> espesor_3;
			
			cout << "\t---------------------------" << endl;
			
			// Invocamos a la funcion y le pasamos los 8 parametros, el area es variable global para q nos devuelva el valor de
			// tipo float del calor liberado
			cout << "\n\t Calor liberado 3 espesores ( 8 parametros)  " << " es: "
				<< calorLiberado(conduct_1,conduct_2,conduct_3,temp_int,temp_ext,espesor_1,espesor_2,espesor_3)<<" W"<<endl;
			
		
			break;
			
			// Si se elije el 0 en el menu salimos del programa
		case 0:
			repetir = false;
			break;
			
		}
	} while (repetir);
	
	system("PAUSE");
	return EXIT_SUCCESS;
}


//======================funcion sobrecargada calor liberado de un material de un solo espesor=============================
// el area de la seccion transversal  es variable glogal
// esta funcion retorna el valor de tipo float del calor liberado.
float  calorLiberado(float conduct_1,float temp_int, float temp_ext, float espesor_1)
{
	float calor_lib=-(area*conduct_1)*(temp_ext-temp_int)/(espesor_1);
	return calor_lib;
}

//======================funcion sobrecargada calor liberado de un material de un 3 espesores,=============================
// el area de la seccion transversal  es variable glogal
// esta funcion retorna el valor de tipo float del calor liberado.
float calorLiberado(float conduct_1,float conduct_2,float conduct_3,
					float temp_int,float temp_ext,float espesor_1,
					float espesor_2, float espesor_3)
{
	float calor_lib=(temp_int-temp_ext)/((espesor_1)/(area*conduct_1)+(espesor_2)/(area*conduct_2)+(espesor_3)/(area*conduct_3));
	return calor_lib;
}
