/*En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
Tipo  Servicio      Costo  X Hectárea
1     Mala hierba         10.00
2     Langostas           20.00
3      Gusanos			  30.00
4   Todo lo anterior      50.00
Además del área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes.
*/


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct servicio{
	int tipo;
	int hectareas;
	float descuento;
	float total;
};
void venta();

int main(){
	venta();
}

void venta(){
	//variables
	int mala;
	int langostas;
	int gusanos;
	int todo;
	int tipo;
	int hectareas;
	int total;
	int descuento;
	int descuento2;
	string s;
	float sumatoriatotal=0.00;
	//datos
	cout<<"Ingrese el numero que corresponde al tipo de fumigacion que desea."<<endl<<"Mala hierba = 1"<<'\t'<<'\t'<<"/10.00 por hectarea/"<<endl<<"Langostas = 2"<<'\t'<<'\t'<<"/20.00 por hectarea/"<<endl<<"Gusanos = 3"<<'\t'<<'\t'<<"/30.00 por hectarea/"<<endl<<"Todo lo anterior = 4"<<'\t'<<"/50.00 por hectarea/"<<endl;
	cin>>tipo;
	cout<<"Digite el numero de hectareas:"<<endl;cin>>hectareas;
	//condiciones
	if(tipo==1){
		total=hectareas*10;
		cout<<"el monto total es: "<<total<<endl;
		mala+=1;
	}
	else if(tipo==2){
		total=hectareas*20;
		cout<<"el monto total es: "<<total<<endl;
		langostas+=1;
	}
	else if(tipo==3){
		total=hectareas*30;
		cout<<"el monto total es: "<<total<<endl;
		gusanos+=1;
	}
	else if(tipo==4){
		total=hectareas*50;
		cout<<"el monto total es: "<<total<<endl;
		todo+=1;
	}
	else{
		cout<<"uups algo salio mal"<<endl;
	}
	//validacion del 5%
	if(hectareas>500){
		descuento = (total*0.05);
		total = total-descuento;
		cout<<"Felicidades usted ha obtenido un descuento del 5%, el nuevo monto es: "<<total<<endl;
	}
	//validacion del 10%
	if(total>1500){
		descuento2 = (total*0.1);
		total = total-descuento2;
		cout<<"Felicidades usted ha obtenido un descuento adicional del 10%, el nuevo monto es: "<<total<<endl;
	}
	cout<<"------------------------------------Resumen: el monto total a pagar es: "<<total<<"-----------------------------------------"<<endl;
	
	//agregar y leer archivo
	cout<<"TIPO: "<<tipo<<"\n"<<"HECTAREAS: "<<hectareas<<"\n"<<"TOTAL: "<<total<<"\n";
	ofstream grabararchivo;
	try {
		grabararchivo.open("planilla.txt",ios::app);
		grabararchivo<<tipo<<"\t"<<hectareas<<"\t"<<total<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"TIPO//HECTAREAS//TOTAL"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("planilla.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"--------------------------------------DEMANDA DE CADA SERVICIO-------------------------------------------"<<endl;
	cout<<"MALA HIERBA: "<<mala<<endl;
	cout<<"LANGOSTAS: "<<mala<<endl;
	cout<<"GUSANOS: "<<mala<<endl;
	cout<<"TODOS LOS SERVICION: "<<mala<<endl;
}


