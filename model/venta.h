#pragma once
#include<iostream>
using namespace std;
class Venta
{
private:
	string codVenta;
	int numVenta;
	int codCliente;
	string fechaVenta;
	string estadoVenta;
	float totVenta;
public:
	Venta()
	{
		
	}
	Venta(string codVenta, int numVenta, int codCliente, string fecha, string estadoVenta, float totVenta)
	{
		this->codVenta = codVenta;
		this->numVenta = numVenta;
		this->codCliente = codCliente;
		this->fechaVenta = fecha;
		this->estadoVenta = estadoVenta;
		this->totVenta = totVenta;
	}
	//Set
	void setCodVenta(string cod)
	{
		this->codVenta = cod;
	}
	void setNumVenta(int num)
	{
		this->numVenta = num;
	}
	void setCodCliente(int codCliente)
	{
		this->codCliente = codCliente;
	}
	void setFechaVenta(string fecha)
	{
		this->fechaVenta = fecha;
	}
	void setEstadoVenta(string estado)
	{
		this->estadoVenta = estado;
	}
	void setTotVenta(float totVenta)
	{
		this->totVenta = totVenta;
	}
	//Get
	string getCodVenta()
	{
		return this->codVenta;
	}
	int getNumVenta()
	{
		return this->numVenta;
	}
	int getCodCliente()
	{
		return this->codCliente;
	}
	string getFechaVenta()
	{
		return this->fechaVenta;
	}
	string getEstadoVenta()
	{
		return this->estadoVenta;
	}
	float getTotVenta()
	{
		return this->totVenta;
	}
};
