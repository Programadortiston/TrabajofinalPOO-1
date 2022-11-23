#pragma once
#include <iostream>
#include<vector>
#include"../model/cliente.h"
#include<fstream>
using namespace std;
class ClienteController
{
private:
	vector<Cliente> vectorCliente;
public:
	ClienteController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(Cliente obj)
	{
		vectorCliente.push_back(obj); // Usuario obj(1, "Pepito", "xd"); vectorUsuario[0] = {1, "Pepito", "xd"};
	}
	Cliente get(int pos)
	{
		return vectorCliente[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
	}
	int size()
	{
		return vectorCliente.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1; //vectorUsuario[0].getCodigo() = 1;
		}
		else
		{
			return vectorCliente[size()-1].getCodCli() + 1; //vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
		}
	}
	Cliente buscar(int dato)
	{
		Cliente objError;
		objError.setNomApeCli("Error");
		for(int i = 0; i<vectorCliente.size(); i++)
		{
			if(dato == vectorCliente[i].getCodCli())
			{
				return vectorCliente[i];
			}
		}
		return objError;
	}
	void buscarString(string dato)
	{
		for(int i = 0; i<vectorCliente.size(); i++)
		{
			if(vectorCliente[i].getNomApeCli().find(dato) != string::npos)
			{
				cout<<"["<<i+1<<"]"<<"\t"<<vectorCliente[i].getNomApeCli()<<endl;
			}
		}
	}
	bool modificar(Cliente ObjOld,Cliente ObjNew)
	{
		for(int i=0;i<vectorCliente.size();i++)
		{
			if(ObjOld.getCodCli() == vectorCliente[i].getCodCli())
			{
				vectorCliente[i].setNomApeCli(ObjNew.getNomApeCli());
				vectorCliente[i].setDirCli(ObjNew.getDirCli());
				vectorCliente[i].setRucCli(ObjNew.getRucCli());
				return true;
			}
		}
		return false;
	}
	int getPostVector(Cliente obj)
	{
		for(int i = 0;i<vectorCliente.size();i++)
		{
			if(obj.getCodCli() == vectorCliente[i].getCodCli())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(Cliente objEncontrado)
	{
		vectorCliente.erase(vectorCliente.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		cout<<"Nombre del Cliente\t Direccion\t \tRuc\n";
		for(int i = 0; i<vectorCliente.size(); i++)
		{
			cout<<vectorCliente[i].getNomApeCli()<<"\t \t "<<vectorCliente[i].getDirCli()<<"\t"<<vectorCliente[i].getRucCli()<<"\n";
		}
	}
	void grabarEnArchivo(Cliente obj)
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoCliente.is_open())
			{
				archivoCliente<<obj.getCodCli()<<";"<<obj.getNomApeCli()<<";"<<obj.getDirCli()<<";"<<obj.getRucCli()<<";"<<endl; 
				archivoCliente.close();
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
			fstream archivoCliente;
			archivoCliente.open("clientes.csv",ios::out);
			if(archivoCliente.is_open())
			{
				for(Cliente x:vectorCliente)
				{	
					archivoCliente<<x.getCodCli()<<";"<<x.getNomApeCli()<<";"<<x.getDirCli()<<";"<<x.getRucCli()<<";"<<endl;
				}
				archivoCliente.close();					
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
			string temporal[4];
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoCliente.is_open())
			{
				while(!archivoCliente.eof() && getline(archivoCliente, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					Cliente objCli(stoi(temporal[0]), temporal[1], temporal[2], temporal[3]);
					add(objCli);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};
