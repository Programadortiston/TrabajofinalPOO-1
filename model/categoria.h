#pragma once
#include<iostream>
using namespace std;
class Categoria
{
private:
	int codCat;
	string nomCat;
public:
	Categoria()
	{
		
	}
	Categoria(int codCat, string nomCat)
	{
		this->codCat = codCat;
		this->nomCat = nomCat;
	}
	//Set
	void setCodCategoria(int cod)
	{
		this->codCat = cod;
	}
	void setNomCat(string nom)
	{
		this->nomCat = nom;
	}
	//Get
	int getCodCategoria()
	{
		return this->codCat;
	}
	string getNomCat()
	{
		return this->nomCat;
	}
};
