#pragma once
#include <iostream>
#include<vector>
#include"../model/detalle_venta.h"
#include<fstream>
using namespace std;
class DetalleVentaController
{
private:
	vector<DetalleVenta> vectorDetalleVenta;
public:
	DetalleVentaController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void add(DetalleVenta obj)
	{
		vectorDetalleVenta.push_back(obj); 
	}
	DetalleVenta get(int pos)
	{
		return vectorDetalleVenta[pos]; 
	}
	int size()
	{
		return vectorDetalleVenta.size(); 
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
			temporal = vectorDetalleVenta[size()-1].getCodigoVenta();
			temporal[1] = temporal[1] + 1;
			return temporal; 
		}
	}
	DetalleVenta buscar(string dato)
	{
		DetalleVenta objError;
		objError.setCodigoVenta("Error");
		for(int i = 0; i<vectorDetalleVenta.size(); i++)
		{
			if(dato == vectorDetalleVenta[i].getCodigoVenta())
			{
				return vectorDetalleVenta[i];
			}
		}
		return objError;
	}
	bool modificar(DetalleVenta ObjOld,DetalleVenta ObjNew)
	{
		for(int i=0;i<vectorDetalleVenta.size();i++)
		{
			if(ObjOld.getCodigoVenta() == vectorDetalleVenta[i].getCodigoVenta())
			{
				vectorDetalleVenta[i].setCodigoPro(ObjNew.getCodigoPro());
				vectorDetalleVenta[i].setPrecio(ObjNew.getPrecio());
				vectorDetalleVenta[i].setCantidad(ObjNew.getCantidad());
				vectorDetalleVenta[i].setImporte(ObjNew.getImporte());
				return true;
			}
		}
		return false;
	}
	int getPostVector(DetalleVenta obj)
	{
		for(int i = 0;i<vectorDetalleVenta.size();i++)
		{
			if(obj.getCodigoVenta() == vectorDetalleVenta[i].getCodigoVenta())			
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(DetalleVenta objEncontrado)
	{
		vectorDetalleVenta.erase(vectorDetalleVenta.begin() + getPostVector(objEncontrado));
	}
	void listar()
	{
		/*
		cout<<"Nombre del Cliente\t Direccion\t \tRuc\n";
		for(int i = 0; i<vectorVenta.size(); i++)
		{
		cout<<vectorVenta[i].getCodVenta()<<"\t \t "<<vectorVenta[i].getDirCli()<<"\t"<<vectorVenta[i].getRucCli()<<"\n";
	}
		*/
	}
	void grabarEnArchivo(DetalleVenta obj)
	{
		try
		{
			fstream archivoDetalleVenta;
			archivoDetalleVenta.open("detalle_ventas.csv", ios::app); //ios::app = las operaciones se realizan al final del archivo
			if(archivoDetalleVenta.is_open())
			{
				archivoDetalleVenta<<obj.getCodigoVenta()<<";"<<obj.getCodigoPro()<<";"<<obj.getPrecio()<<";"<<obj.getCantidad()<<";"<<obj.getImporte()<<";"<<endl; 
				archivoDetalleVenta.close();
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
			fstream archivoDetalleVenta;
			archivoDetalleVenta.open("detalle_ventas.csv",ios::out);
			if(archivoDetalleVenta.is_open())
			{
				for(DetalleVenta x:vectorDetalleVenta)
				{	
					archivoDetalleVenta<<x.getCodigoVenta()<<";"<<x.getCodigoPro()<<";"<<x.getPrecio()<<";"<<x.getCantidad()<<";"<<x.getImporte()<<";"<<endl;
				}
				archivoDetalleVenta.close();					
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
			fstream archivoDetalleVenta;
			archivoDetalleVenta.open("detalle_ventas.csv", ios::in);//ios::in = modo lectura(entrada)
			if(archivoDetalleVenta.is_open())
			{
				while(!archivoDetalleVenta.eof() && getline(archivoDetalleVenta, linea))//mientras archivoUsuario tenga datos; linea = "1;Pepito;xd;"
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)//string::npos = -1, posi = 1
					{
						temporal[i] = linea.substr(0, posi);//temporal[0] = linea.substr(0, 1); temporal[0] = 1
						linea.erase(0, posi+1);//linea.erase(0,2); linea = "Pepito;xd;"
						++i; //i = 1
						//Vuelve a iterar
					}
					DetalleVenta objDet(temporal[0], stoi(temporal[1]), stof(temporal[2]), stof(temporal[3]), stof(temporal[4]));
					add(objDet);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio  un error al grabar el archivo";
		}
	}
};
