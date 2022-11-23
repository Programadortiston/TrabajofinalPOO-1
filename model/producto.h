#pragma once
#include<iostream>
#include"categoria.h"
using namespace std;
class Producto
{
private:
	int codProducto;
	string nomPro;
	float prePro;
	int stockPro;
	int codCategoria;
public:
	Producto()
	{
		
	}
	Producto(int cod, string nom, float prePro, int stock, int codCat)
	{
		this->codProducto = cod;
		this->nomPro = nom;
		this->prePro = prePro;
		this->stockPro = stock;
		this->codCategoria = codCat;
	}
	//Set
	void setCodPro(int cod)
	{
		this->codProducto = cod;
	}
	void setNomApe(string nom)
	{
		this->nomPro = nom;
	}
	void setPrePro(float prePro)
	{
		this->prePro = prePro;
	}
	void setStockPro(int stock)
	{
		this->stockPro = stock;
	}
	void setCodCat(int codCat)
	{
		this->codCategoria = codCat;
	}
	//Get
	int getCodPro()
	{
		return this->codProducto;
	}
	string getNomApePro()
	{
		return this->nomPro;
	}
	float getPrePro()
	{
		return this->prePro;
	}
	int getStockPro()
	{
		return this->stockPro;
	}
	int getCodCat()
	{
		return this->codCategoria;
	}
};
