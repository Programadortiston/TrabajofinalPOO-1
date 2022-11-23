#pragma once
#include <iostream>
#include<vector>
#include"../model/producto.h"
#include"categoriaController.h"
#include<fstream>
using namespace std;
class ProductoController
{
private:
	vector<Producto> vectorProducto;
public:
	ProductoController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(Producto obj)
	{
		vectorProducto.push_back(obj); // Usuario obj(1, "Pepito", "xd"); vectorUsuario[0] = {1, "Pepito", "xd"};
	}
	Producto get(int pos)
	{
		return vectorProducto[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
	}
	int size()
	{
		return vectorProducto.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1; //vectorUsuario[0].getCodigo() = 1;
		}
		else
		{
			return vectorProducto[size()-1].getCodPro() + 1; //vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
		}
	}
	Producto buscar(int dato)
	{
		Producto objError;
		objError.setNomApe("Error");
		for(int i = 0; i<vectorProducto.size(); i++)
		{
			if(dato == vectorProducto[i].getCodPro())
			{
				return vectorProducto[i];
			}
		}
		return objError;
	}
	void buscarString(string dato)
	{
		for(int i = 0; i<vectorProducto.size(); i++)
		{
			if(vectorProducto[i].getNomApePro().find(dato) != string::npos)
			{
				cout<<"["<<i+1<<"]"<<"\t"<<vectorProducto[i].getNomApePro()<<endl;
			}
		}
	}
	bool modificar(Producto ObjOld,Producto ObjNew)
	{
		for(int i=0;i<vectorProducto.size();i++)
		{
			if(ObjOld.getCodPro() == vectorProducto[i].getCodPro())
			{
				vectorProducto[i].setNomApe(ObjNew.getNomApePro());
				vectorProducto[i].setPrePro(ObjNew.getPrePro());
				vectorProducto[i].setStockPro(ObjNew.getStockPro());
				vectorProducto[i].setCodCat(ObjNew.getCodCat());
				return true;
			}
		}
		return false;
	}
	int getPostVector(Producto obj)
	{
		for(int i = 0;i<vectorProducto.size();i++)
		{
			if(obj.getCodPro() == vectorProducto[i].getCodPro())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(Producto objEncontrado)
	{
		vectorProducto.erase(vectorProducto.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		CategoriaController* obj = new CategoriaController;
		cout<<"Nombre del producto\t Precio\t \tStock\t Categoria\n";
		for(int i = 0; i<vectorProducto.size(); i++)
		{
			cout<<vectorProducto[i].getNomApePro()<<"\t \t "<<vectorProducto[i].getPrePro()<<"\t \t"<<vectorProducto[i].getStockPro()<<"\t "<< obj->listarCategoria(vectorProducto[i])<<"\n";
		}
	}
	void grabarEnArchivo(Producto obj)
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("productos.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoProducto.is_open())
			{
				archivoProducto<<obj.getCodPro()<<";"<<obj.getNomApePro()<<";"<<obj.getPrePro()<<";"<<obj.getStockPro()<<";"<<obj.getCodCat()<<";"<<endl; 
				archivoProducto.close();
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
			fstream archivoProducto;
			archivoProducto.open("productos.csv",ios::out);
			if(archivoProducto.is_open())
			{
				for(Producto x:vectorProducto)
				{	
					archivoProducto<<x.getCodPro()<<";"<<x.getNomApePro()<<";"<<x.getPrePro()<<";"<<x.getStockPro()<<";"<<x.getCodCat()<<";"<<endl;
				}
				archivoProducto.close();					
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
			string temporal[5];
			fstream archivoProducto;
			archivoProducto.open("productos.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoProducto.is_open())
			{
				while(!archivoProducto.eof() && getline(archivoProducto, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					Producto objPro(stoi(temporal[0]), temporal[1], stof(temporal[2]), stoi(temporal[3]), stoi(temporal[4]));
					add(objPro);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};
