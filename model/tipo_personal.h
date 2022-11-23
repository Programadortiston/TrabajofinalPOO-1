#pragma once
#include<iostream>
using namespace std;
class TipoPersonal
{
private:
	int codTip;
	string nomTipPer;
public:
	TipoPersonal()
	{
		
	}
	TipoPersonal(int codTip, string nomTip)
	{
		this->codTip = codTip;
		this->nomTipPer = nomTip;
	}
	//Set
	void setCodTip(int cod)
	{
		this->codTip = cod;
	}
	void setNomTip(string nom)
	{
		this->nomTipPer = nom;
	}
	//Get
	int getCodTip()
	{
		return this->codTip;
	}
	string getNomTip()
	{
		return this->nomTipPer;
	}
};

