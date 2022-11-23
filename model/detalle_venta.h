#pragma once
#include<iostream>
using namespace std;
class DetalleVenta
{
private:
	string codigoVenta;
	int codigoPro;
	float precio;
	float cantidad;
	float importe;
public:
	DetalleVenta()
	{
		
	}
	DetalleVenta(string codVenta, int codPro, float pre, float cant, float importe)
	{
		this->codigoVenta = codVenta;
		this->codigoPro = codPro;
		this->precio = pre;
		this->cantidad = cant;
		this->importe = importe;
	}
	//Set
	void setCodigoVenta(string cod)
	{
		this->codigoVenta = cod;
	}
	void setCodigoPro(int codPro)
	{
		this->codigoPro = codPro;
	}
	void setPrecio(float precio)
	{
		this->precio = precio;
	}
	void setCantidad(float cantidad)
	{
		this->cantidad = cantidad;
	}
	void setImporte(float importe)
	{
		this->importe = importe;
	}
	//Get
	string getCodigoVenta()
	{
		return this->codigoVenta;
	}
	int getCodigoPro()
	{
		return this->codigoPro;
	}
	float getPrecio()
	{
		return this->precio;
	}
	float getCantidad()
	{
		return this->cantidad;
	}
	float getImporte()
	{
		return precio*cantidad;
	}
};
