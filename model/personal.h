#pragma once
#include<iostream>
#include"tipo_personal.h"
using namespace std;
class Personal
{
private:
	int codPersonal;
	string nomApePer;
	string dniPer;
	int suePer;
	int codTipPer;
	string usuario;
	string contra;
public:
	Personal()
	{
		
	}
	Personal(int cod, string nomApe, string dni, int sue, int codTip, string usuario, string contra)
	{
		this->codPersonal = cod;
		this->nomApePer = nomApe;
		this->dniPer = dni;
		this->suePer = sue;
		this->codTipPer = codTip;
		this->usuario = usuario;
		this->contra = contra;
	}
	//Set
	void setCodPer(int cod)
	{
		this->codPersonal = cod;
	}
	void setNomApe(string nomApe)
	{
		this->nomApePer = nomApe;
	}
	void setDniPer(string dni)
	{
		this->dniPer = dni;
	}
	void setSuePer(int sue)
	{
		this->suePer = sue;
	}
	void setCodTipPer(int codTip)
	{
		this->codTipPer = codTip;
	}
	void setUser(string usuario)
	{
		this->usuario = usuario;
	}
	void setContra(string contra)
	{
		this->contra = contra;
	}
	//Get
	int getCodPer()
	{
		return this->codPersonal;
	}
	string getNomApe()
	{
		return this->nomApePer;
	}
	string getDni()
	{
		return this->dniPer;
	}
	int getSue()
	{
		return this->suePer;
	}
	int getCodTipPer()
	{
		return this->codTipPer;
	}
	string getUser()
	{
		return this->usuario;
	}
	string getContra()
	{
		return this->contra;
	}
};

