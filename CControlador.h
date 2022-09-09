#pragma once
#include "ListaProducto.h"
#include "CProducto.h"
#include<stdlib.h>
#include<time.h>
#include <locale.h>
class CController
{
public:
	CController();
	~CController();
	void menu(); 
	void agregarProducto(); 
	void mostrarLista(); 
	void Reporte1(); 
	void Reporte2();
	void Reporte3();
	void Reporte4();

private:
	int randVisualizaciones, randVecesCompartidas, randAntiguedad; 
	string Codigo, Nombre;
	CArreglo* objArr; 
	CProducto* objProducto; 
};

CController::CController()
{
	 
	setlocale(LC_ALL, "");
	srand(time(NULL));	
	objArr = new CArreglo();

}

CController::~CController()
{
}
void CController::menu() {
	int opcion, posicion;
	do
	{
		cout << "                      ::::::::::::::::::::MENU::::::::::::::::::::			  " << endl;
		cout << "1 - Agregar producto															  " << endl;
		cout << "2 - Listar productos															  " << endl;
		cout << "3 – Eliminar producto															  " << endl;
		cout << "4 – Reporte de todos los productos con más 1, 000 vistas						  " << endl;
		cout << "5 – Reporte de todos los productos con más de 10, 000 veces compartido			  " << endl;
		cout << "6 – Reporte de todos los productos con menos de 5 años de antiguedad			  " << endl;
		cout << "7 – Reporte de todos los productos con más de 10, 000 veces compartido y más de	  " << endl;
		cout << "     3 años de antiguedad															  " << endl;
		cout << "8 - Salir																		  " << endl;
		do
		{
			cout << "Ingrese Opcion: ";
			cin >> opcion;
		} while (opcion < 1 || opcion>7);
		
		switch (opcion)
		{
		case 1:
			agregarProducto(); 
			system("pause");
			break;
		case 2:
			mostrarLista(); 
			system("pause");
			break;
		case 3:
			cout << "Que posicion de cancion desea eliminar: ";
			cin >> posicion;
			objArr->eliminar(posicion);  
			break;
		case 4: 
			Reporte1(); 
			system("pause");
			break;
		case 5:
			Reporte2(); 
			system("pause");
			break;
		case 6:
			Reporte3(); 
			system("pause");
			break;
		case 7:
			Reporte4(); 
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 8);
}
void CController::agregarProducto() {
	cout << endl; cout << endl;
	cout << "::::::::::::::::::::REGISTRAR PRODUCTOS::::::::::::::::::::" << endl;
	cout << "Nombre de Usuario: "; cin >> Nombre;
	cout << "Codigo de Producto: "; cin >> Codigo;
	cout << endl;
	objArr->push_back(new CProducto(Codigo, Nombre, randVisualizaciones = rand() % 15000, randAntiguedad = rand() % 10, randVecesCompartidas = rand() % 17000));
}
void CController::mostrarLista() {
	cout << "::::::::::::::::::::LISTA DE PRODUCTOS::::::::::::::::::::" << endl;
	cout << "NOMBRE \t |     CODIGO \t |     VISUALIZACIONES \t |    ANTIGUEDAD \t |    VECES COMPARTIDO " << endl;
	for (int i = 0; i < objArr->size(); i++)
	{
		cout << objArr->at(i)->getNombre(); cout << "\t\t";
		cout << objArr->at(i)->getCodigo(); cout << "\t\t";
		cout << objArr->at(i)->getVisualizaciones();	 cout << "\t\t\t\t";
		cout << objArr->at(i)->getAntiguedad();	 cout << "\t\t\t\t";
		cout << objArr->at(i)->getVecesCompartido(); cout << "\t\t\t\t";
		cout << endl;
	}
	cout << endl;
}
void CController::Reporte1(){
	for (int i = 0; i < objArr->size(); i++)
	{
		if (objArr->at(i)->getVisualizaciones() >= 1000) {
			cout << "NOMBRE \t |     CODIGO \t |     VISUALIZACIONES \t |    ANTIGUEDAD \t |    VECES COMPARTIDO " << endl;
			cout << objArr->at(i)->getNombre() << "\t\t"<<
				objArr->at(i)->getCodigo() << "\t\t" <<
				objArr->at(i)->getVisualizaciones() << "\t\t\t\t" <<
				objArr->at(i)->getAntiguedad() << "\t\t\t\t" <<
				objArr->at(i)->getVecesCompartido(); 
			cout << endl;

		}
	}
	cout << endl;
}
void CController::Reporte2(){
	for (int i = 0; i < objArr->size(); i++)
	{
		if (objArr->at(i)->getVecesCompartido() >= 10000) {
			cout << "NOMBRE \t |     CODIGO \t |     VISUALIZACIONES \t |    ANTIGUEDAD \t |    VECES COMPARTIDO " << endl;
			cout << objArr->at(i)->getNombre() << "\t\t" <<
				objArr->at(i)->getCodigo() << "\t\t" <<
				objArr->at(i)->getVisualizaciones() << "\t\t\t\t" <<
				objArr->at(i)->getAntiguedad() << "\t\t\t\t" <<
				objArr->at(i)->getVecesCompartido();
			cout << endl;

		}
	}
	cout << endl;

}
void CController::Reporte3(){
	for (int i = 0; i < objArr->size(); i++)
	{
		if (objArr->at(i)->getAntiguedad() <=5) {
			cout << "NOMBRE \t |     CODIGO \t |     VISUALIZACIONES \t |    ANTIGUEDAD \t |    VECES COMPARTIDO " << endl;
			cout << objArr->at(i)->getNombre() << "\t\t" <<
				objArr->at(i)->getCodigo() << "\t\t" <<
				objArr->at(i)->getVisualizaciones() << "\t\t\t\t" <<
				objArr->at(i)->getAntiguedad() << "\t\t\t\t" <<
				objArr->at(i)->getVecesCompartido();
			cout << endl;

		}
	}
	cout << endl;

}
void CController::Reporte4(){
	for (int i = 0; i < objArr->size(); i++)
	{
		if (objArr->at(i)->getVecesCompartido() >= 10000 && objArr->at(i)->getAntiguedad() >= 3) {
			cout << "NOMBRE \t |     CODIGO \t |     VISUALIZACIONES \t |    ANTIGUEDAD \t |    VECES COMPARTIDO " << endl;
			cout << objArr->at(i)->getNombre() << "\t\t" <<
				objArr->at(i)->getCodigo() << "\t\t" <<
				objArr->at(i)->getVisualizaciones() << "\t\t\t\t" <<
				objArr->at(i)->getAntiguedad() << "\t\t\t\t" <<
				objArr->at(i)->getVecesCompartido();
			cout << endl;

		}
	}
	cout << endl;

}