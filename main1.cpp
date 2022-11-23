#include <iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include"controller/clienteController.h"
#include"controller/personalController.h"
#include"controller/tipoPersonalController.h"
#include"controller/productoController.h"
#include"controller/categoriaController.h"
#include"controller/ventaController.h"
#include"controller/detalleVentaController.h"
using namespace std;
//Variables globales
ClienteController* cliController = new ClienteController();
PersonalController* perController = new PersonalController();
TipoPersonalController* tipController = new TipoPersonalController();
ProductoController* proController = new ProductoController();
CategoriaController* catController = new CategoriaController();
VentaController* venController = new VentaController();
DetalleVentaController* detController = new DetalleVentaController();
//Prototipos
//Sistema principal
void menuDeBienvenida();
void menuDeOpciones();
void menuDeOpciones2();
bool verificarDatos();
//Cliente
void menuCli();
void agregarCli();
void modificarCli();
void eliminarCli();
void buscarCli();
void listarCli();
//Personal
void menuPer();
void agregarPer();
void modificarPer();
void eliminarPer();
void buscarPer();
void listarPer();
//Tipo personal
void menuTipPer();
void agregarTipPer();
void modificarTipPer();
void eliminarTipPer();
void buscarTipPer();
void listarTipPer();
//Producto
void menuPro();
void agregarPro();
void modificarPro();
void eliminarPro();
void buscarPro();
void listarPro();
//Categoria
void menuCat();
void agregarCat();
void modificarCat();
void eliminarCat();
void buscarCat();
void listarCat();
//Venta
void menuVen();
void agregarVen();
void anularVen();
void modificarVen();
void eliminarVen();
void buscarVen();
void listarVen();
int main(int argc, char *argv[]) {
	menuDeOpciones();
	return 0;
}
//Implementacion
void menuDeOpciones()
{
	int opt;
	do
	{
		cout<<"=====================================================\n";
		cout<<"\t   Bienvenido al sistema de ventas\n\n";
		cout<<"	 	     VentaMas								\n"<<endl;
		cout<<"=====================================================\n";
		cout<< endl<<endl;
		cout<<"\t  \t Iniciar sesion  [1]\n";
		cout<<"\t  \t Salir  \t [2]\n";
		cout<<"\t  \t Ingrese una opcion:";
		
		cin>>opt;
		switch(opt)
		{
			case 1:system("cls"); 
			if(verificarDatos() == true)
			{
				system("cls");
				menuDeOpciones2(); 
				break;
			}
			else
			{
				cout<<"Demasiados intentos fallidos\n";
				opt = 9;
				break;
			}
			case 2:cout<<"Gracias por usar nuestro programa\n"; break; 
			default:system("cls"); cout<<"Ingrese una opcion correcta[1-2].\n";
		}
	} while(opt!=2);
}
bool verificarDatos()
{
	int contador = 0;
	bool bandera;
	string user, contra;
	cin.ignore();
	do
	{
		cout<<"Ingresar usuario:";//"pepito"
		getline(cin, user);
		cout<<"Ingresar contraseña:";//"xd" 
		contra = "";
		char caracter;
		caracter = getch(); //getch() = funcion para leer caracter uno por uno
		while(caracter != 13) //mientras caracter sea diferente de enter 
		{
			if(caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contra.push_back(caracter); //mete el caracter al string contra
				cout<<"*"; //muestra los * en la consola
			}
			else //caracter = 8
			{
				if(contra.length() > 0) // si el contra.length es mayor a 0
				{
					cout<<"\b \b"; //muestra como si borrara un caracter en la consola 
					contra = contra.substr(0, contra.length() - 1); //borra de verdad el dato en el string contra; contra = (0, 6-1); 
				}
			}
			caracter = getch(); //vuelve a leer el siguiente caracter
		}
		cout<<"\n";
		bandera = perController->verificarDatos(user, contra);
		if(bandera == true)
		{
			system("pause");
			system("cls");
		}
		else
		{
			cout<<"Usuario o contraseña incorrectos.\n";
			system("pause");
			system("cls");
		}
		contador++;
	}while(bandera == false && contador<3);
	if(bandera == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void menuDeOpciones2()
{
	int opt;
	do
	{
		cout<<"\t \t REGISTROS DE VENTAMAS\n";
		cout<<"Cliente\t \t \t[1]\n";
		cout<<"Personal\t \t[2]\n";
		cout<<"Tipo de personal\t[3]\n";
		cout<<"Producto\t \t[4]\n";
		cout<<"Categoria de producto\t[5]\n";
		cout<<"Venta\t \t \t[6]\n";
		cout<<"Cierre de sesion\t[7]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); menuCli(); break;
		case 2:system("cls"); menuPer(); break;
		case 3:system("cls"); menuTipPer(); break;
		case 4:system("cls"); menuPro(); break;
		case 5:system("cls"); menuCat(); break;
		case 6:system("cls"); menuVen(); break;
		case 7:cout<<"Volviendo a la pagina principal...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-7].\n";
		}
	} while(opt!=7);
}
//CLIENTE
void menuCli()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DEL CLIENTE\n";
		cout<<"agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Modificar\t[3]\n";
		cout<<"Eliminar\t[4]\n";
		cout<<"Listar\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); agregarCli(); break;
		case 2:system("cls"); buscarCli(); break;
		case 3:system("cls"); modificarCli(); break;
		case 4:system("cls"); eliminarCli(); break;
		case 5:system("cls"); listarCli(); break;
		case 6:cout<<"Volviendo a la pagina anterior...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
		}
	} while(opt!=6);
}
void agregarCli()
{
	string bandera;
	int codCli;
	string nom;
	string dir;
	string ruc;
	do
	{
		codCli = cliController->getCorrelativo();
		cout<<"************("<<codCli<<")************\n";
		cin.ignore();
		cout<<"Ingresar nombre y apellido del cliente:";
		getline(cin, nom);
		cout<<"Ingresar direccion del cliente:";
		getline(cin, dir);
		cout<<"Ingresar Ruc del cliente:";
		cin>>ruc;
		cout<<"Continuar(S/s):";
		cin>>bandera;
		/*Creando el objeto de tipo Usuario*/
		Cliente objCli(codCli, nom, dir, ruc); //cod = 1, usuario = "Pepito", contra = "xd";
		//Agregando el objeto al arreglo
		cliController->add(objCli);
		//grabar en archivo
		cliController->grabarEnArchivo(objCli);
		system("cls");
	} while(bandera == "S" || bandera == "s");
}
void buscarCli()
{
	int cod;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;
	Cliente objEncontrado = cliController->buscar(cod);
	if(objEncontrado.getNomApeCli() != "Error")
	{
		cout<<"Cliente encontrado\n";
		cout<<"Nombres y Apellidos:"<<objEncontrado.getNomApeCli()<<endl;
		cout<<"Direccion:"<<objEncontrado.getDirCli()<<endl;
		cout<<"RUC:"<<objEncontrado.getRucCli()<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void modificarCli()
{
	int cod;
	cout<<"Ingrese codigo a modificar:";
	cin>>cod;
	Cliente objEncontrado = cliController->buscar(cod);
	if(objEncontrado.getNomApeCli() != "Error")
	{
		cout<<"Cliente encontrado\n";
		cout<<"Nombres y Apellidos:"<<objEncontrado.getNomApeCli()<<endl;
		cout<<"Direccion:"<<objEncontrado.getDirCli()<<endl;
		cout<<"RUC:"<<objEncontrado.getRucCli()<<endl;
		cin.ignore();
		//Modificación
		string nomApe;
		string dir;
		string ruc;
		cout<<"Ingresar nombre y apellido del cliente:";
		getline(cin, nomApe);
		cout<<"Ingresar direccion del cliente:";
		getline(cin, dir);
		cout<<"Ingresar RUC del cliente:";
		cin>>ruc;
		Cliente objNew(objEncontrado.getCodCli(), nomApe, dir, ruc);
		bool estado = cliController->modificar(objEncontrado,objNew);
		if(estado = true)
		{
			cout<<"Registro modificado satisfactoriamente\n";	
			//grabar en archivo
			cliController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se Modifico el registro\n";	
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void eliminarCli()
{
	int cod;
	cout<<"Ingrese codigo a eliminar:";
	cin>>cod;
	Cliente objEliminar = cliController->buscar(cod);
	if(objEliminar.getNomApeCli() != "Error")
	{
		cliController->eliminar(objEliminar);	
		cout<<"Registro Eliminado Satisfactoriamente!\n";
		//Grabar en archivo
		cliController->grabarModificarEliminar();
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void listarCli()
{
	cliController->listar();
	system("pause");
	system("cls");
}
//PERSONAL
void menuPer()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DEL PERSONAL\n";
		cout<<"Agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Modificar\t[3]\n";
		cout<<"Eliminar\t[4]\n";
		cout<<"Listar\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); agregarPer(); break;	
		case 2:system("cls"); buscarPer(); break;
		case 3:system("cls"); modificarPer(); break;
		case 4:system("cls"); eliminarPer(); break;
		case 5:system("cls"); listarPer(); break;
		case 6:cout<<"Volviendo a la pagina anterior...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
		}
	} while(opt!=6);
}
void agregarPer()
{
	string bandera;
	int codPer;
	string nomApe;
	string dni;
	int sue;
	int codTipPer;
	string usuario;
	string contra;
	do
	{
		codPer = perController->getCorrelativo();
		cout<<"************("<<codPer<<")************\n";
		cin.ignore();
		cout<<"Ingresar nombre y apellido:";
		getline(cin, nomApe);
		cout<<"Ingresar dni:";
		cin>>dni;
		cout<<"Ingresar sueldo:";
		cin>>sue;
		tipController->listar();
		cin>>codTipPer;
		cin.ignore();
		cout<<"Registrar usuario:";
		getline(cin, usuario);
		cout<<"Registrar contraseña:";
		char caracter;
		caracter = getch(); //getch() = funcion para leer caracter uno por uno caracter = a
		while(caracter != 13) //mientras caracter sea diferente de enter
		{
			if(caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contra.push_back(caracter); //mete el caracter al string contra || contra = adolf
				cout<<"*"; //muestra los * en la consola
			}
			else
			{
				if(contra.length() > 0) // si el contra.length es mayor a 0
				{
					cout<<"\b \b"; //muestra como si borrara un caracter en la consola
					contra = contra.substr(0, contra.length() - 1); //borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); //vuelve a leer el siguiente caracter
		}
		cout<<"\n";
		cout<<"Continuar(S/s):";
		cin>>bandera;
		/*Creando el objeto de tipo Usuario*/
		Personal objPer(codPer, nomApe, dni, sue, codTipPer, usuario, contra); //cod = 1, usuario = "Pepito", contra = "xd";
		//Agregando el objeto al arreglo
		perController->add(objPer);
		//grabar en archivo
		perController->grabarEnArchivo(objPer);
		system("cls");
	} while(bandera == "S" || bandera == "s");
}
void buscarPer()
{
	int cod;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;
	Personal objEncontrado = perController->buscar(cod);
	if(objEncontrado.getUser() != "Error")
	{
		cout<<"Personal encontrado\n";
		cout<<"Nombres y Apellidos:"<<objEncontrado.getNomApe()<<endl;
		cout<<"DNI:"<<objEncontrado.getDni()<<endl;
		cout<<"Sueldo:"<<objEncontrado.getSue()<<endl;
		cout<<"Tipo de personal:"<<tipController->listarTipo(objEncontrado)<<endl;
		cout<<"Usuario:"<<objEncontrado.getUser()<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void modificarPer()
{
	int cod;
	cout<<"Ingrese codigo a modificar:";
	cin>>cod;
	Personal objEncontrado = perController->buscar(cod);
	if(objEncontrado.getUser() != "Error")
	{
		cout<<"Personal encontrado\n";
		cout<<"Nombres y Apellidos:"<<objEncontrado.getNomApe()<<endl;
		cout<<"DNI:"<<objEncontrado.getDni()<<endl;
		cout<<"Sueldo:"<<objEncontrado.getSue()<<endl;
		cout<<"Tipo de personal:"<<tipController->listarTipo(objEncontrado)<<endl;
		cout<<"Usuario:"<<objEncontrado.getUser()<<endl;
		cout<<"Contraseña:"<<objEncontrado.getContra()<<endl;
		cin.ignore();
		//Modificación
		string nomApe;
		string dni;
		int sue;
		int codTipPer;
		string usuario;
		string contra;
		cout<<"Ingresar nombre y apellido:";
		getline(cin, nomApe);
		cout<<"Ingresar dni:";
		cin>>dni;
		cout<<"Ingresar sueldo:";
		cin>>sue;
		tipController->listar();
		cin>>codTipPer;
		cin.ignore();
		cout<<"Ingresar usuario:";
		getline(cin, usuario);
		cout<<"Ingresar contraseña:";
		char caracter;
		caracter = getch(); //getch() = funcion para leer caracter uno por uno
		while(caracter != 13) //mientras caracter sea diferente de enter
		{
			if(caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contra.push_back(caracter); //mete el caracter al string contra
				cout<<"*"; //muestra los * en la consola
			}
			else
			{
				if(contra.length() > 0) // si el contra.length es mayor a 0
				{
					cout<<"\b \b"; //muestra como si borrara un caracter en la consola
					contra = contra.substr(0, contra.length() - 1); //borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); //vuelve a leer el siguiente caracter
		}
		cout<<"\n";
		Personal objNew(objEncontrado.getCodPer(), nomApe, dni, sue, codTipPer, usuario, contra);
		bool estado = perController->modificar(objEncontrado,objNew);
		if(estado = true)
		{
			cout<<"Registro modificado satisfactoriamente\n";	
			//grabar en archivo
			perController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se Modifico el registro\n";	
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void eliminarPer()
{
		int cod;
		cout<<"Ingrese codigo a eliminar:";
		cin>>cod;
		Personal objEliminar = perController->buscar(cod);
		if(objEliminar.getUser() != "Error")
		{
			perController->eliminar(objEliminar);	
			cout<<"Registro Eliminado Satisfactoriamente!\n";
			//Grabar en archivo
			perController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se encontro el codigo ingresado\n";	
		}
		system("pause");
		system("cls");
}
void listarPer()
{
	perController->listar();
	system("pause");
	system("cls");
}
//TIPO PERSONAL
void menuTipPer()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DEL TIPO DE PERSONAL\n";
		cout<<"Agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Modificar\t[3]\n";
		cout<<"Eliminar\t[4]\n";
		cout<<"Listar\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); agregarTipPer(); break;
		case 2:system("cls"); buscarTipPer(); break;
		case 3:system("cls"); modificarTipPer(); break;
		case 4:system("cls"); eliminarTipPer(); break;
		case 5:system("cls"); listarTipPer(); break;
		case 6:cout<<"Volviendo a la pagina anterior...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
		}
	} while(opt!=6);
}
void agregarTipPer()
{
	int codTip;
	string tipoPer;
	string bandera;
	do
	{
		codTip = tipController->getCorrelativo();
		cout<<"************("<<codTip<<")************\n";
		cin.ignore();
		cout<<"Ingrese Tipo de Personal:";
		getline(cin, tipoPer);
		cout<<"Continuar(S/s):";
		cin>>bandera;
		/*Creando el objeto de tipo Usuario*/
		TipoPersonal objTip(codTip, tipoPer); //cod = 1, usuario = "Pepito", contra = "xd";
		//Agregando el objeto al arreglo
		tipController->add(objTip);
		//grabar en archivo
		tipController->grabarEnArchivo(objTip);
		system("cls");
	} while(bandera == "S" || bandera == "s");
}
void buscarTipPer()
{
	int cod;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if(objEncontrado.getNomTip() != "Error")
	{
		cout<<"Tipo de personal encontrado\n";
		cout<<"Tipo de personal:"<<objEncontrado.getNomTip()<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void modificarTipPer()
{
	int cod;
	cout<<"Ingrese codigo a modificar:";
	cin>>cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if(objEncontrado.getNomTip() != "Error")
	{
		cout<<"Tipo de personal encontrado\n";
		cout<<"Tipo de personal:"<<objEncontrado.getNomTip()<<endl;
		cin.ignore();
		//Modificación
		string nomTip;
		cout<<"Ingresar tipo de personal:";
		getline(cin, nomTip);
		TipoPersonal objNew(objEncontrado.getCodTip(), nomTip);
		bool estado = tipController->modificar(objEncontrado,objNew);
		if(estado = true)
		{
			cout<<"Registro modificado satisfactoriamente\n";	
			//grabar en archivo
			tipController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se Modifico el registro\n";	
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void eliminarTipPer()
{
	int cod;
	cout<<"Ingrese codigo a eliminar:";
	cin>>cod;
	TipoPersonal objEliminar = tipController->buscar(cod);
	if(objEliminar.getNomTip() != "Error")
	{
		tipController->eliminar(objEliminar);	
		cout<<"Registro Eliminado Satisfactoriamente!\n";
		//Grabar en archivo
		tipController->grabarModificarEliminar();
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void listarTipPer()
{
	tipController->listar2();
	system("pause");
	system("cls");
}
//PRODUCTO
void menuPro()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DE LOS PRODUCTOS\n";
		cout<<"Agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Modificar\t[3]\n";
		cout<<"Eliminar\t[4]\n";
		cout<<"Listar\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); agregarPro(); break;
		case 2:system("cls"); buscarPro(); break;
		case 3:system("cls"); modificarPro(); break;
		case 4:system("cls"); eliminarPro(); break;
		case 5:system("cls"); listarPro(); break;
		case 6:cout<<"Volviendo a la pagina anterior...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
		}
	} while(opt!=6);
}
void agregarPro()
{
	string bandera;
	int codPro;
	string nom;
	float pre;
	int stock;
	int codCat;
	do
	{
		codPro = proController->getCorrelativo();
		cout<<"************("<<codPro<<")************\n";
		cin.ignore();
		cout<<"Ingresar nombre del producto:";
		getline(cin, nom);
		cout<<"Ingresar precio del producto:";
		cin>>pre;
		cout<<"Ingresar stock del producto:";
		cin>>stock;
		catController->listar();
		cin>>codCat;
		cout<<"Continuar(S/s):";
		cin>>bandera;
		/*Creando el objeto de tipo Usuario*/
		Producto objPro(codPro, nom, pre, stock, codCat); //cod = 1, usuario = "Pepito", contra = "xd";
		//Agregando el objeto al arreglo
		proController->add(objPro);
		//grabar en archivo
		proController->grabarEnArchivo(objPro);
		system("cls");
	} while(bandera == "S" || bandera == "s");
}
void buscarPro()
{
	int cod;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;
	Producto objEncontrado = proController->buscar(cod);
	if(objEncontrado.getNomApePro() != "Error")
	{
		cout<<"Producto encontrado\n";
		cout<<"Nombre del producto:"<<objEncontrado.getNomApePro()<<endl;
		cout<<"Precio:"<<objEncontrado.getPrePro()<<endl;
		cout<<"Stock:"<<objEncontrado.getStockPro()<<endl;
		cout<<"Categoria del producto:"<<catController->listarCategoria(objEncontrado)<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
	
}
void modificarPro()
{
	int cod;
	cout<<"Ingrese codigo a modificar:";
	cin>>cod;
	Producto objEncontrado = proController->buscar(cod);
	if(objEncontrado.getNomApePro() != "Error")
	{
		cout<<"Producto encontrado\n";
		cout<<"Nombre del producto:"<<objEncontrado.getNomApePro()<<endl;
		cout<<"Precio:"<<objEncontrado.getPrePro()<<endl;
		cout<<"Stock:"<<objEncontrado.getStockPro()<<endl;
		cout<<"Categoria del producto:"<<catController->listarCategoria(objEncontrado)<<endl;
		cin.ignore();
		//Modificación
		string nomPro;
		float precio;
		int stock;
		int codCat;
		cout<<"Ingresar nombre del producto:";
		getline(cin, nomPro);
		cout<<"Ingresar precio del producto:";
		cin>>precio;
		cout<<"Ingresar stock del producto:";
		cin>>stock;
		catController->listar();
		cin>>codCat;
		Producto objNew(objEncontrado.getCodPro(), nomPro, precio, stock, codCat);
		bool estado = proController->modificar(objEncontrado,objNew);
		if(estado = true)
		{
			cout<<"Registro modificado satisfactoriamente\n";	
			//grabar en archivo
			proController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se Modifico el registro\n";	
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void eliminarPro()
{
	int cod;
	cout<<"Ingrese codigo a eliminar:";
	cin>>cod;
	Producto objEliminar = proController->buscar(cod);
	if(objEliminar.getNomApePro() != "Error")
	{
		proController->eliminar(objEliminar);	
		cout<<"Registro Eliminado Satisfactoriamente!\n";
		//Grabar en archivo
		proController->grabarModificarEliminar();
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void listarPro()
{
	proController->listar();
	system("pause");
	system("cls");
}
//CATEGORIA
void menuCat()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DE LAS CATEGORIAS\n";
		cout<<"Agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Modificar\t[3]\n";
		cout<<"Eliminar\t[4]\n";
		cout<<"Listar\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls"); agregarCat(); break;
		case 2:system("cls"); buscarCat(); break;
		case 3:system("cls"); modificarCat(); break;
		case 4:system("cls"); eliminarCat(); break;
		case 5:system("cls"); listarCat(); break;
		case 6:cout<<"Volviendo a la pagina anterior...\n"; 
		system("pause");
		system("cls");
		break;
		default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
		}
	} while(opt!=6);
}
void agregarCat()
{
	int codCat;
	string nomCat;
	string bandera;
	do
	{
		codCat = catController->getCorrelativo();
		cout<<"************("<<codCat<<")************\n";
		cin.ignore();
		cout<<"Ingrese la nueva categoria de producto:";
		getline(cin, nomCat);
		cout<<"Continuar(S/s):";
		cin>>bandera;
		/*Creando el objeto de tipo Usuario*/
		Categoria objCat(codCat, nomCat); //cod = 1, usuario = "Pepito", contra = "xd";
		//Agregando el objeto al arreglo
		catController->add(objCat);
		//grabar en archivo
		catController->grabarEnArchivo(objCat);
		system("cls");
	} while(bandera == "S" || bandera == "s");
}
void buscarCat()
{
	int cod;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;
	Categoria objEncontrado = catController->buscar(cod);
	if(objEncontrado.getNomCat() != "Error")
	{
		cout<<"Categoria encontrada\n";
		cout<<"Categoria:"<<objEncontrado.getNomCat()<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void modificarCat()
{
	int cod;
	cout<<"Ingrese codigo a modificar:";
	cin>>cod;
	Categoria objEncontrado = catController->buscar(cod);
	if(objEncontrado.getNomCat() != "Error")
	{
		cout<<"Categoria encontrada\n";
		cout<<"Categoria:"<<objEncontrado.getNomCat()<<endl;
		cin.ignore();
		//Modificación
		string nomCat;
		cout<<"Ingresar categoria de producto:";
		getline(cin, nomCat);
		Categoria objNew(objEncontrado.getCodCategoria(), nomCat);
		bool estado = catController->modificar(objEncontrado,objNew);
		if(estado = true)
		{
			cout<<"Registro modificado satisfactoriamente\n";	
			//grabar en archivo
			catController->grabarModificarEliminar();
		}
		else
		{
			cout<<"No se Modifico el registro\n";	
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void eliminarCat()
{
	int cod;
	cout<<"Ingrese codigo a eliminar:";
	cin>>cod;
	Categoria objEliminar = catController->buscar(cod);
	if(objEliminar.getNomCat() != "Error")
	{
		catController->eliminar(objEliminar);	
		cout<<"Registro Eliminado Satisfactoriamente!\n";
		//Grabar en archivo
		catController->grabarModificarEliminar();
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void listarCat()
{
	catController->listar2();
	system("pause");
	system("cls");
}
//VENTA
void menuVen()
{
	int opt;
	do
	{
		cout<<"\t \t OPCIONES DE LA VENTA\n";
		cout<<"Agregar\t\t[1]\n";
		cout<<"Buscar\t\t[2]\n";
		cout<<"Eliminar\t[3]\n";
		cout<<"Listar\t\t[4]\n";
		cout<<"Anular\t\t[5]\n";
		cout<<"Salir\t\t[6]\n";
		cout<<"Ingrese una opcion:";
		cin>>opt;
		switch(opt)
		{
			case 1:system("cls"); agregarVen(); break;
			case 2:system("cls"); buscarVen(); break;
			case 3:system("cls"); eliminarVen(); break;
			case 4:system("cls"); listarVen(); break;
			case 5:system("cls"); anularVen(); break;
			case 6:cout<<"Volviendo a la pagina anterior...\n"; 
			system("pause");
			system("cls");
			break;
			default:system("cls"); cout<<"Ingrese una opcion correcta[1-6].\n";
			
		} 
	}while(opt!=6);
}
void agregarVen()
{
	//fecha
	time_t t = time(nullptr);
	tm* objT = localtime(&t);
	//variables venta
	string codVen;
	int numVen;
	int codCli;
	string estado = "Registrado";
	string fecha;
	string producto;
	string cliente;
	//variables detalle venta
	int codPro;
	float precio;
	float cantidad;
	float importe;
	vector<Venta> vectorTempVen;
	vector<DetalleVenta> vectorTempDet;
	string bandera;
	float pre;
	int stock;
	int codCat;
	int newStock;
	//Verificaciones
	bool bandera1;
	bool bandera2;
	string temporal;
	string banderacli;
	string banderapro;
	bool bandera3;
	string respuesta;
	do
	{
		float totVen = 0;
		codVen = venController->getCorrelativo();
		cout<<"************("<<codVen<<")************\n";
		cin.ignore();
		cout<<"Fecha:"<<objT->tm_mday<<"/"<<(objT->tm_mon+1)<<"/"<<(objT->tm_year+1900)<<endl;
		cout<<"Ingresar fecha(DD/MM/AAAA):";
		cin>>fecha;
		numVen = venController->getCorrelativo2();
		cout<<"Numero de venta:"<<numVen<<endl;
		system("pause");
		cin.ignore();
		do
		{
			system("cls");
			cout<<"Buscar nombre del cliente:";
			getline(cin, cliente);
			cliController->buscarString(cliente);
			cout<<"El cliente ingresado es correcto?(S/s/N/n):";
			cin>>banderacli;
			cin.ignore();
		}while(banderacli == "N" || banderacli == "n");
		do
		{
			cout<<"Ingresar codigo de cliente:";
			cin>>codCli;
			Cliente objEncontrado = cliController->buscar(codCli);
			if(objEncontrado.getNomApeCli() != "Error")
			{
				cout<<"Cliente encontrado\n";
				cout<<"Codigo cliente:"<<objEncontrado.getCodCli()<<endl;
				cout<<"Nombres y Apellidos:"<<objEncontrado.getNomApeCli()<<endl;
				cout<<"Direccion:"<<objEncontrado.getDirCli()<<endl;
				cout<<"RUC:"<<objEncontrado.getRucCli()<<endl;
				bandera1 = true;
			}
			else
			{
				cout<<"No se encontro el codigo ingresado\n";
				bandera1 = false;
			}
			system("pause");
		}while(bandera1 == false);
		cin.ignore();
		do
		{
			do
			{
				system("cls");
				cout<<"Buscar nombre del producto:";
				getline(cin, producto);
				proController->buscarString(producto);
				cout<<"El producto ingresado es correcto?(S/s/N/n):";
				cin>>banderapro;
				cin.ignore();
			}while(banderapro == "N" || banderapro == "n");
			do
			{
				cout<<"Ingresar codigo del producto:";
				cin>>codPro;
				Producto objEncontrado = proController->buscar(codPro);
				if(objEncontrado.getNomApePro() != "Error")
				{
					cout<<"Producto encontrado\n";
					cout<<"Codigo del producto:"<<objEncontrado.getCodPro()<<endl;
					cout<<"Nombre del producto:"<<objEncontrado.getNomApePro()<<endl;
					cout<<"Precio:"<<objEncontrado.getPrePro()<<endl;
					cout<<"Stock:"<<objEncontrado.getStockPro()<<endl;
					cout<<"Categoria del producto:"<<catController->listarCategoria(objEncontrado)<<endl;
					bandera2 = true;
					precio = objEncontrado.getPrePro();
					stock = objEncontrado.getStockPro();
				}
				else
				{
					cout<<"No se encontro el codigo ingresado\n";
					bandera2 = false;
				}
				if(stock == 0)
				{
					cout<<"No hay stock del producto seleccionado.\n";
					cout<<"Seleccionar otro producto...\n";
					system("pause");
					cin.ignore();
					do
					{
						system("cls");
						cout<<"Buscar nombre del producto:";
						getline(cin, producto);
						proController->buscarString(producto);
						cout<<"El producto ingresado es correcto?(S/s/N/n):";
						cin>>banderapro;
						cin.ignore();
					}while(banderapro == "N" || banderapro == "n");
					bandera2 = false;
				}
			}while(bandera2 == false);
			do
			{
				cout<<"Ingresar cantidad de productos a comprar:";
				cin>>cantidad;
				if(cantidad>stock || cantidad<0)
				{
					cout<<"Ingresar cantidad valida(0-"<<stock<<").\n";
					cout<<"Se encuentran en stock "<<stock<<" de los productos seleccionados.\n";
					bandera3 = false;
				}
				else
				{
					bandera3 = true;
				}
			}while(bandera3 == false);
			newStock = stock - cantidad;
			Producto objOld = proController->buscar(codPro);
			Producto objNew(objOld.getCodPro(), objOld.getNomApePro(), objOld.getPrePro(), newStock, objOld.getCodCat());
			proController->modificar(objOld, objNew);
			importe = cantidad*precio;
			cout<<"Desea agregar otro producto(S/s):";
			cin>>temporal;
			DetalleVenta objDet(codVen, codPro, precio, cantidad, importe);
			vectorTempDet.push_back(objDet);
			cout<<"Codigo de venta\t Codigo de producto\t Precio\t Cantidad\t Importe\n";
			for(int i = 0; i<vectorTempDet.size(); i++)
			{
				cout<<vectorTempDet[i].getCodigoVenta()<<"\t \t"<<" "<<vectorTempDet[i].getCodigoPro()<<"\t \t \t"<<" "<<vectorTempDet[i].getPrecio()<<"\t"<<" "<<vectorTempDet[i].getCantidad()<<"\t \t"<<" "<<vectorTempDet[i].getImporte()<<endl;
			}
			cin.ignore();
			system("pause");
		}while(temporal == "S" || temporal == "s");
		for(int i = 0; i<vectorTempDet.size(); i++)
		{
			if(codVen == vectorTempDet[i].getCodigoVenta())
			{
				totVen = totVen + vectorTempDet[i].getImporte();
			}
		}
		cout<<"Desea agregar otra venta?(S/s):";
		cin>>bandera;
		Venta objVen(codVen, numVen, codCli, fecha, estado, totVen);
		vectorTempVen.push_back(objVen);
		cout<<"Codigo\t Descripcion\t Precio\t Cantidad\t Importe\n";
		for(int i = 0; i<vectorTempDet.size(); i++)
		{
			Producto objFound = proController->buscar(vectorTempDet[i].getCodigoPro());
			cout<<vectorTempDet[i].getCodigoVenta()<<"\t"<<" "<<catController->listarCategoria(objFound)<<"\t"<<" "<<vectorTempDet[i].getPrecio()<<"\t"<<" "<<vectorTempDet[i].getCantidad()<<"\t \t"<<vectorTempDet[i].getImporte()<<endl;
		}
		for(int i = 0; i<vectorTempVen.size(); i++)
		{
			cout<<"Total "<<vectorTempVen[i].getCodVenta()<<":"<<vectorTempVen[i].getTotVenta()<<endl;
		}
		for(int i = 0; i<vectorTempDet.size(); i++)
		{
			detController->add(vectorTempDet[i]);
		}
		for(int i = 0; i<vectorTempVen.size(); i++)
		{
			venController->add(vectorTempVen[i]);
		}
		system("pause");
		system("cls");
	} while(bandera == "S" || bandera == "s");
	cout<<"Desea grabar todo?(S/s):";
	cin>>respuesta;
	if(respuesta == "S" || respuesta == "s")
	{
		for(int i = 0; i<vectorTempDet.size(); i++)
		{
			detController->grabarEnArchivo(vectorTempDet[i]);
		}
		for(int i = 0; i<vectorTempVen.size(); i++)
		{
			venController->grabarEnArchivo(vectorTempVen[i]);
		}
		proController->grabarModificarEliminar();
	}
	else
	{
		cout<<"Regresando a la pagina principal...\n";
	}
}
void eliminarVen()
{
	string cod;
	cout<<"Ingrese codigo de la venta a eliminar:";
	cin>>cod;
	Venta objEliminar = venController->buscar(cod);
	if(objEliminar.getCodVenta() != "Error")
	{
		venController->eliminar(objEliminar);	
		cout<<"Registro Eliminado Satisfactoriamente!\n";
		//Grabar en archivo
		venController->grabarModificarEliminar();
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void listarVen()
{
	venController->listar();
	system("pause");
	system("cls");
}
void buscarVen()
{
	string cod;
	cout<<"Ingrese codigo de venta a buscar (recuerde que el codigo de venta empieza con f):";
	cin>>cod;
	Venta objEncontrado = venController->buscar(cod);
	if(objEncontrado.getCodVenta() != "Error")
	{
		cout<<"Registro de venta encontrado\n";
		cout<<"Numero de venta:"<<objEncontrado.getNumVenta()<<endl;
		cout<<"Codigo de cliente:"<<objEncontrado.getCodCliente()<<endl;
		cout<<"Estado de venta:"<<objEncontrado.getEstadoVenta()<<endl;
		cout<<"Total de venta:"<<objEncontrado.getTotVenta()<<endl;
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
void anularVen()
{
	string cod;
	string estado = "Anulado";
	cout<<"Ingrese codigo de venta a anular (recuerde que el codigo de venta empieza con f):";
	cin>>cod;
	Venta objAnular = venController->buscar(cod);
	if(objAnular.getCodVenta() != "Error")
	{
		Venta objNew(objAnular.getCodVenta(), objAnular.getNumVenta(), objAnular.getCodCliente(), objAnular.getFechaVenta(), estado, objAnular.getTotVenta());
		bool bandera = venController->modificar(objAnular, objNew);
		if(bandera == true)
		{
			cout<<"Registro Anulado Satisfactoriamente!\n";
			//Grabar en archivo
			venController->grabarModificarEliminar();
		}
	}
	else
	{
		cout<<"No se encontro el codigo ingresado\n";	
	}
	system("pause");
	system("cls");
}
