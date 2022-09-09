#pragma once
#include "CProducto.h"
class CArreglo
{
public:
	CArreglo();
	~CArreglo();

	void push_back(CProducto* dato);
	void eliminar(int posicion);
	int size();
	CProducto* at(int posicion);

private:
	int tamanioArr;
	CProducto** arrObjetos;
};

CArreglo::CArreglo()
{
	tamanioArr = 0;
	arrObjetos = new CProducto * [tamanioArr];
}

CArreglo::~CArreglo()
{
}
void CArreglo::push_back(CProducto* dato) {
	CProducto** aux = new CProducto * [tamanioArr + 1];
	for (int i = 0; i < tamanioArr; i++)
	{
		aux[i] = arrObjetos[i];
	}
	aux[tamanioArr] = dato;
	tamanioArr++;
	delete[]arrObjetos;
	arrObjetos = aux;
	aux = nullptr;
	delete aux;
}
void CArreglo::eliminar(int posicion) {
	CProducto** aux = new CProducto * [tamanioArr - 1];
	for (int i = 0; i < tamanioArr - 1; i++)
	{
		if (i < posicion) {
			aux[i] = arrObjetos[i];
		}
		else { aux[i] = arrObjetos[i + 1]; }
	}
	tamanioArr--;
	delete[]arrObjetos;
	arrObjetos = aux;
	aux = nullptr;
	delete aux;
}
int CArreglo::size() {
	return tamanioArr;
}
CProducto* CArreglo::at(int posicion) {
	return arrObjetos[posicion];
}
