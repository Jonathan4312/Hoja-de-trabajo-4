/*Una persona desea realizar un muestreo con un numero de personas para determinar el porcentaje de
niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive.
La categoría se determina en base a la siguiente tabla:
-----------------------------------
Categoría				Edad
-----------------------------------
Niños					0-12
Jóvenes					13-29
Adultos					30-59
Adultos Mayores			60 en adelante
--------------------------------------
Teniendo en cuenta que para el muestreo de personas no será mayor a 50, realice un programa que en
primer lugar reciba como dato el numero de personas del muestreo y luego por cada persona permita el
ingreso de su edad y grabar todo a un archivo. El programa deberá leer los datos del archivo y mostrar
como resultado el porcentaje de personas que hay por cada una de las categorías.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


//Llamo a las funciones con las que trabajaré
void grabar();
void reporte();

int main(){
	grabar();
	reporte();
}
//funcion grabar 
void grabar(){
	int ninos = 0;
	int jovenes = 0;
	int adultos = 0;
	int ancianos = 0;
	int npersonas;//numero de personas a ingresar 
	int edad;
	string s;
	
	cout<<"Digite el numero de personas que desea ingresar: "<<endl;cin>>npersonas;
	for(int i;i<npersonas;i++){
		cout<<"Ingrese la edad de la persona: "<<endl;cin>>edad;
		if(edad<=12){
			cout<<"Pertenece a la categoria 'Ninos'"<<endl<<endl;
			ninos=ninos+1;
		}
		else if(edad>=13 and edad<=29){
			cout<<"Pertenece a la categoria 'Jovenes'"<<endl<<endl;
			jovenes=jovenes+1;
		}
		else if(edad>=30 and edad<=59){
			cout<<"Pertenece a la categoria 'Adultos'"<<endl<<endl;
			adultos=adultos+1;
		}
	}
	//agregar y leer archivo
	ofstream grabararchivo;
	try {
		grabararchivo.open("edades.txt",ios::app);
		grabararchivo<<"\t"<<ninos<<"\t"<<jovenes<<"\t"<<adultos<<"\t"<<"\t"<<ancianos<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"---------------------------------Conteo de edades---------------------------------------"<<endl;
	cout<<"\t"<<"NINOS//JOVENES//ADULTOS//ADULTOS MAYORES"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("edades.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
}

//reporte
void reporte(){

	ifstream db;
	float n,j,a,am,m;
	try{	
		db.open("edades.txt",ios::in);
		
		while (db >>n>>j>>a>>am>>m){
			n=(n/m)*100;
			j=(j/m)*100;
			a=(a/m)*100;
			am=(am/m)*100;
		}	
		db.close();
		
		cout<<"------------------------------Porcentajes de cada categoria---------------------------------"<<endl;
		cout<<"CATEGORIA"<<'\t'<<'\t'<<"EDAD"<<endl;
		cout<<"NINOS \t \t"<<"\t O-12 \t"<<"="<<n<<"%"<<endl;
		cout<<"JOVENES \t"<<"\t 13-29 \t"<<"="<<j<<"%"<<endl;
		cout<<"ADULTOS \t"<<"\t 30-59 \t"<<"="<<a<<"%"<<endl;
		cout<<"ADULTOS MAYORES \t"<<" >60 \t"<<"="<<am<<"%"<<endl;
		
	}
	catch (exception X){		
		cout<<"Error en la manipulacion del archivo"<<endl;
	}			
}

