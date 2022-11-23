#pragma once
#include <iostream>
#include<vector>
#include"../model/tipo_personal.h"
#include<fstream>
using namespace std;
class TipoPersonalController
{
private:
	vector<TipoPersonal> vectorTipoPersonal;
public:
	TipoPersonalController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(TipoPersonal obj)
	{
		vectorTipoPersonal.push_back(obj); // Usuario obj(1, "Pepito", "xd"); vectorUsuario[0] = {1, "Pepito", "xd"};
	}
	TipoPersonal get(int pos)
	{
		return vectorTipoPersonal[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
	}
	int size()
	{
		return vectorTipoPersonal.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1; //vectorUsuario[0].getCodigo() = 1;
		}
		else
		{
			return vectorTipoPersonal[size()-1].getCodTip() + 1; //vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
		}
	}
	TipoPersonal buscar(int dato)
	{
		TipoPersonal objError;
		objError.setNomTip("Error");
		for(int i = 0; i<vectorTipoPersonal.size(); i++)
		{
			if(dato == vectorTipoPersonal[i].getCodTip())
			{
				return vectorTipoPersonal[i];
			}
		}
		return objError;
	}
	bool modificar(TipoPersonal ObjOld,TipoPersonal ObjNew)
	{
		for(int i=0;i<vectorTipoPersonal.size();i++)
		{
			if(ObjOld.getCodTip() == vectorTipoPersonal[i].getCodTip())
			{
				vectorTipoPersonal[i].setNomTip(ObjNew.getNomTip());
				return true;
			}
		}
		return false;
	}
	int getPostVector(TipoPersonal obj)
	{
		for(int i = 0;i<vectorTipoPersonal.size();i++)
		{
			if(obj.getCodTip() == vectorTipoPersonal[i].getCodTip())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(TipoPersonal objEncontrado)
	{
		vectorTipoPersonal.erase(vectorTipoPersonal.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		for(int i = 0; i<vectorTipoPersonal.size(); i++)
		{
			cout<<"["<<vectorTipoPersonal[i].getCodTip()<<"]\t"<<vectorTipoPersonal[i].getNomTip()<<endl; // [1]  Empleado
		}
		cout<<"Ingresar una opcion:";
	}
	string listarTipo(Personal obj)
	{
		string temporal;
		for(int i = 0; i<vectorTipoPersonal.size(); i++)
		{
			if(obj.getCodTipPer() == vectorTipoPersonal[i].getCodTip())
			{
				temporal = vectorTipoPersonal[i].getNomTip();
			}
		}
		return temporal;
	}
	void listar2()
	{
		cout<<"Codigo\t Tipo de personal\n";
		for(int i = 0; i<vectorTipoPersonal.size(); i++)
		{
			cout<<vectorTipoPersonal[i].getCodTip()<<"\t "<<vectorTipoPersonal[i].getNomTip()<<"\n";
		}
	}
	void grabarEnArchivo(TipoPersonal obj)
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("tipo_personal.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoTipoPersonal.is_open())
			{
				archivoTipoPersonal<<obj.getCodTip()<<";"<<obj.getNomTip()<<";"<<endl; 
				archivoTipoPersonal.close();
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	void grabarModificarEliminar()
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("tipo_personal.csv",ios::out);
			if(archivoTipoPersonal.is_open())
			{
				for(TipoPersonal x:vectorTipoPersonal)
				{	
					archivoTipoPersonal<<x.getCodTip()<<";"<<x.getNomTip()<<";"<<endl;
				}
				archivoTipoPersonal.close();					
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}	
	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;
			string linea;
			string temporal[2];
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("tipo_personal.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoTipoPersonal.is_open())
			{
				while(!archivoTipoPersonal.eof() && getline(archivoTipoPersonal, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					TipoPersonal objTipPer(stoi(temporal[0]), temporal[1]);
					add(objTipPer);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};
