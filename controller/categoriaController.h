#pragma once
#include <iostream>
#include<vector>
#include"../model/categoria.h"
#include<fstream>
using namespace std;
class CategoriaController
{
private:
	vector<Categoria> vectorCategoria;
public:
	CategoriaController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(Categoria obj)
	{
		vectorCategoria.push_back(obj); // Usuario obj(1, "Pepito", "xd"); vectorUsuario[0] = {1, "Pepito", "xd"};
	}
	Categoria get(int pos)
	{
		return vectorCategoria[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
	}
	int size()
	{
		return vectorCategoria.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1; //vectorUsuario[0].getCodigo() = 1;
		}
		else
		{
			return vectorCategoria[size()-1].getCodCategoria() + 1; //vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
		}
	}
	Categoria buscar(int dato)
	{
		Categoria objError;
		objError.setNomCat("Error");
		for(int i = 0; i<vectorCategoria.size(); i++)
		{
			if(dato == vectorCategoria[i].getCodCategoria())
			{
				return vectorCategoria[i];
			}
		}
		return objError;
	}
	bool modificar(Categoria ObjOld,Categoria ObjNew)
	{
		for(int i=0;i<vectorCategoria.size();i++)
		{
			if(ObjOld.getCodCategoria() == vectorCategoria[i].getCodCategoria())
			{
				vectorCategoria[i].setNomCat(ObjNew.getNomCat());
				return true;
			}
		}
		return false;
	}
	int getPostVector(Categoria obj)
	{
		for(int i = 0;i<vectorCategoria.size();i++)
		{
			if(obj.getCodCategoria() == vectorCategoria[i].getCodCategoria())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(Categoria objEncontrado)
	{
		vectorCategoria.erase(vectorCategoria.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		for(int i = 0; i<vectorCategoria.size(); i++)
		{
			cout<<"["<<vectorCategoria[i].getCodCategoria()<<"]\t"<<vectorCategoria[i].getNomCat()<<endl;
		}
		cout<<"Ingresar una opcion:";
	}
	string listarCategoria(Producto obj)
	{
		string temporal;
		for(int i = 0; i<vectorCategoria.size(); i++)
		{
			if(obj.getCodCat() == vectorCategoria[i].getCodCategoria())
			{
				temporal = vectorCategoria[i].getNomCat();
			}
		}
		return temporal;
	}
	void listar2()
	{
		cout<<"Codigo\t Categoria de producto\n";
		for(int i = 0; i<vectorCategoria.size(); i++)
		{
			cout<<vectorCategoria[i].getCodCategoria()<<"\t "<<vectorCategoria[i].getNomCat()<<"\n";
		}
	}
	void grabarEnArchivo(Categoria obj)
	{
		try
		{
			fstream archivoCategoria;
			archivoCategoria.open("categorias.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoCategoria.is_open())
			{
				archivoCategoria<<obj.getCodCategoria()<<";"<<obj.getNomCat()<<";"<<endl; 
				archivoCategoria.close();
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
			fstream archivoCategoria;
			archivoCategoria.open("categorias.csv",ios::out);
			if(archivoCategoria.is_open())
			{
				for(Categoria x:vectorCategoria)
				{	
					archivoCategoria<<x.getCodCategoria()<<";"<<x.getNomCat()<<";"<<endl;
				}
				archivoCategoria.close();					
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
			fstream archivoCategoria;
			archivoCategoria.open("categorias.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoCategoria.is_open())
			{
				while(!archivoCategoria.eof() && getline(archivoCategoria, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					Categoria objTipPer(stoi(temporal[0]), temporal[1]);
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
