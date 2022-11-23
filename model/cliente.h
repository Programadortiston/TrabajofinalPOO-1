#pragma once
#include <iostream>
using namespace std;
class Cliente
{
private:
	int codCli;
	string nomApeCli;
	string dirCli;
	string rucCli;
public:
	Cliente()
	{
		
	}
	Cliente(int cod, string nomApe, string dir, string ruc)
	{
		this->codCli = cod;
		this->nomApeCli = nomApe;
		this->dirCli = dir;
		this->rucCli = ruc;
	}
	//set
	void setCodCli(int cod)
	{
		this->codCli = cod;
	}
	void setNomApeCli(string nomApe)
	{
		this->nomApeCli = nomApe;
	}
	void setDirCli(string dir)
	{
		this->dirCli = dir;
	}
	void setRucCli(string ruc)
	{
		this->rucCli = ruc;
	}
	//get 
	int getCodCli()
	{
		return this->codCli;
	}
	
	string getNomApeCli()
	{
		return this->nomApeCli;
	}
	string getDirCli()
	{
		return this->dirCli;
	}
	string getRucCli()
	{
		return this->rucCli;
	}
};
