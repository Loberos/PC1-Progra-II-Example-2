#pragma once
#include <iostream>
#include <string>
using namespace std;
using namespace System;
class CProducto
{
public:
	CProducto(string _Codigo, string _Nombre, int _Visualizaciones, int _Antiguedad, int _VecesCompartido);
	~CProducto();
	string getCodigo(); 
	string getNombre();
	int getVisualizaciones();
	int getAntiguedad();
	int getVecesCompartido();
private:
	string Codigo, Nombre; 
	int Visualizaciones, Antiguedad, VecesCompartido;
};

CProducto::CProducto(string _Codigo, string _Nombre, int _Visualizaciones, int _Antiguedad, int _VecesCompartido)
{
	Codigo = _Codigo;
	Nombre = _Nombre;
	Visualizaciones = _Visualizaciones; 
	Antiguedad = _Antiguedad; 
	VecesCompartido = _VecesCompartido; 
}

CProducto::~CProducto()
{
}
string CProducto::getCodigo(){
	return Codigo;
}
string CProducto::getNombre(){
	return Nombre;
}
int CProducto::getVisualizaciones() {
	return Visualizaciones;
}
int CProducto::getAntiguedad(){
	return Antiguedad;
}
int CProducto::getVecesCompartido(){
	return VecesCompartido;
}