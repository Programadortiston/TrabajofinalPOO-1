#pragma once
#include <iostream>
#include<vector>
#include"../model/personal.h"
#include"tipoPersonalController.h"
#include<fstream>
using namespace std;
class PersonalController
{
private:
	vector<Personal> vectorPersonal;
public:
	PersonalController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(Personal obj)
	{
		vectorPersonal.push_back(obj); // Usuario obj(1, "Pepito", "xd"); vectorUsuario[0] = {1, "Pepito", "xd"};
	}
	Personal get(int pos)
	{
		return vectorPersonal[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
	}
	int size()
	{
		return vectorPersonal.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1; //vectorUsuario[0].getCodigo() = 1;
		}
		else
		{
			return vectorPersonal[size()-1].getCodPer() + 1; //vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
		}
	}
	Personal buscar(int dato)
	{
		Personal objError;
		objError.setUser("Error");
		for(int i = 0; i<vectorPersonal.size(); i++)
		{
			if(dato == vectorPersonal[i].getCodPer())
			{
				return vectorPersonal[i];
			}
		}
		return objError;
	}
	bool modificar(Personal ObjOld,Personal ObjNew)
	{
		for(int i=0;i<vectorPersonal.size();i++)
		{
			if(ObjOld.getCodPer() == vectorPersonal[i].getCodPer())
			{
				vectorPersonal[i].setNomApe(ObjNew.getNomApe());
				vectorPersonal[i].setDniPer(ObjNew.getDni());
				vectorPersonal[i].setSuePer(ObjNew.getSue());
				vectorPersonal[i].setCodTipPer(ObjNew.getCodTipPer());
				vectorPersonal[i].setUser(ObjNew.getUser());
				vectorPersonal[i].setContra(ObjNew.getContra());
				return true;
			}
		}
		return false;
	}
	int getPostVector(Personal obj)
	{
		for(int i = 0;i<vectorPersonal.size();i++)
		{
			if(obj.getCodPer() == vectorPersonal[i].getCodPer())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(Personal objEncontrado)
	{
		vectorPersonal.erase(vectorPersonal.begin() + getPostVector(objEncontrado));
	}
	bool verificarDatos(string user, string contra)
	{
		TipoPersonalController* obj = new TipoPersonalController; //Personal obj
		for(int i = 0; i<vectorPersonal.size(); i++)
		{
			if(user == vectorPersonal[i].getUser() && contra == vectorPersonal[i].getContra()) // verifica si la contraseña y el usuario son iguales
			{
				cout<<"Usuario y contraseña correctos.\n";
				cout<<"Ha ingresado al sistema como "<<obj->listarTipo(vectorPersonal[i])<<"\n";
				return true;
			}
		}
		return false;
	}
	string encriptarDatos(string contra) // pepito xd
	{
		for(int i = 0; i<contra.length(); i++) //contra = xd; contra[0] = x contra[1] = d
		{
			contra[i] = contra[i] + 3; //contra[0] = x + 3; contra[1] = d + 3;
		}
		return contra;
	}
	string desencriptarDatos(string contra)
	{
		for(int i = 0; i<contra.length(); i++)
		{
			contra[i] = contra[i] - 3;
		}
		return contra;
	}
	void listar()
	{
		TipoPersonalController* obj = new TipoPersonalController;
		cout<<"Nombres y Apellidos\t Dni\t \tSueldo\t Tipo de Personal\tUsuario\n";
		for(int i = 0; i<vectorPersonal.size(); i++)
		{
			cout<<vectorPersonal[i].getNomApe()<<"\t \t "<<vectorPersonal[i].getDni()<<"\t"<<vectorPersonal[i].getSue()<<"\t "<< obj->listarTipo(vectorPersonal[i])<<"\t \t"<<vectorPersonal[i].getUser()<<"\n";
		}
	}
	void grabarEnArchivo(Personal obj)
	{
		try
		{
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			string temporal;
			//Encriptando datos
			temporal = obj.getContra();
			if(archivoPersonal.is_open())
			{
				archivoPersonal<<obj.getCodPer()<<";"<<obj.getNomApe()<<";"<<obj.getDni()<<";"<<obj.getSue()<<";"<<obj.getCodTipPer()<<";"<<obj.getUser()<<";"<<encriptarDatos(temporal)<<";"<<endl; 
				archivoPersonal.close();
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
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv",ios::out);
			string temporal;
			//Encriptando datos
			if(archivoPersonal.is_open())
			{
				for(Personal x:vectorPersonal)
				{	
					temporal = x.getContra();
					archivoPersonal<<x.getCodPer()<<";"<<x.getNomApe()<<";"<<x.getDni()<<";"<<x.getSue()<<";"<<x.getCodTipPer()<<";"<<x.getUser()<<";"<<encriptarDatos(temporal)<<";"<<endl;
				}
				archivoPersonal.close();					
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
			string temporal[7];
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoPersonal.is_open())
			{
				while(!archivoPersonal.eof() && getline(archivoPersonal, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					//Desencriptando datos
					string contraNew;
					contraNew = temporal[6];
					Personal objPer(stoi(temporal[0]), temporal[1], temporal[2], stoi(temporal[3]), stoi(temporal[4]), temporal[5], desencriptarDatos(contraNew));
					add(objPer);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};

