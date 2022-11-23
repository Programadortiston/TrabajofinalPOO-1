#pragma once
#include <iostream>
#include<vector>
#include"../model/venta.h"
#include<fstream>
using namespace std;
class VentaController
{
private:
	vector<Venta> vectorVenta;
public:
	VentaController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(Venta obj)
	{
		vectorVenta.push_back(obj); 
	}
	Venta get(int pos)
	{
		return vectorVenta[pos]; 
	}
	int size()
	{
		return vectorVenta.size(); 
	}
	string getCorrelativo()
	{
		if(size() == 0)
		{
			return "f1";
		}
		else
		{
			string temporal;
			temporal = vectorVenta[size()-1].getCodVenta();
			temporal[1] = temporal[1] + 1;
			return temporal; 
		}
	}
	int getCorrelativo2()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorVenta[size()-1].getNumVenta() + 1;
		}
	}
	Venta buscar(string dato)
	{
		Venta objError;
		objError.setCodVenta("Error");
		for(int i = 0; i<vectorVenta.size(); i++)
		{
			if(dato == vectorVenta[i].getCodVenta())
			{
				return vectorVenta[i];
			}
		}
		return objError;
	}
	bool modificar(Venta ObjOld,Venta ObjNew)
	{
		for(int i=0;i<vectorVenta.size();i++)
		{
			if(ObjOld.getCodVenta() == vectorVenta[i].getCodVenta())
			{
				vectorVenta[i].setCodCliente(ObjNew.getCodCliente());
				vectorVenta[i].setEstadoVenta(ObjNew.getEstadoVenta());
				vectorVenta[i].setTotVenta(ObjNew.getTotVenta());
				return true;
			}
		}
		return false;
	}
	int getPostVector(Venta obj)
	{
		for(int i = 0;i<vectorVenta.size();i++)
		{
			if(obj.getCodVenta() == vectorVenta[i].getCodVenta())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(Venta objEncontrado)
	{
		vectorVenta.erase(vectorVenta.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		cout<<"Codigo Venta\t Numero de Venta\t Codigo Cliente\t Fecha\t \tEstado\t \tTotal\n";
		for(int i = 0; i<vectorVenta.size(); i++)
		{
			cout<<vectorVenta[i].getCodVenta()<<"\t \t "<<vectorVenta[i].getNumVenta()<<"\t \t \t"<<" "<<vectorVenta[i].getCodCliente()<<"\t \t"<<vectorVenta[i].getFechaVenta()<<"\t"<<vectorVenta[i].getEstadoVenta()<<"\t"<<vectorVenta[i].getTotVenta()<<"\n";
		}
	}
	void grabarEnArchivo(Venta obj)
	{
		try
		{
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoVenta.is_open())
			{
				archivoVenta<<obj.getCodVenta()<<";"<<obj.getNumVenta()<<";"<<obj.getCodCliente()<<";"<<obj.getFechaVenta()<<";"<<obj.getEstadoVenta()<<";"<<obj.getTotVenta()<<";"<<endl; 
				archivoVenta.close();
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
			fstream archivoVenta;
			archivoVenta.open("ventas.csv",ios::out);
			if(archivoVenta.is_open())
			{
				for(Venta x:vectorVenta)
				{	
					archivoVenta<<x.getCodVenta()<<";"<<x.getNumVenta()<<";"<<x.getCodCliente()<<";"<<x.getFechaVenta()<<";"<<x.getEstadoVenta()<<";"<<x.getTotVenta()<<";"<<endl;
				}
				archivoVenta.close();					
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
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoVenta.is_open())
			{
				while(!archivoVenta.eof() && getline(archivoVenta, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					Venta objVen(temporal[0], stoi(temporal[1]), stoi(temporal[2]), temporal[3], temporal[4], stof(temporal[5]));
					add(objVen);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};
