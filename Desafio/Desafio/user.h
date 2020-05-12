#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
struct conten                   //creo una estructura para el mapa de inventario que contiene el nombre, la cantidad y el costo del porducto
{
    string nombre;
    string cantidad;
    string costo;
};
class User
{
    string cedula,clave,saldo;
public:
    User();

    bool admin(string usua,string clave_);              //ingresar como admin

    void imprimir();                                    //imprimir el inventario

    void agreg_invent(string ID_,string nom_,string cant_,string cost_);                                //agregar cosas al inventario

    void wombo_combo();                                 //crear un combo

    void agregar_user(string cedula_,string clave_);    //agrega un usuario

    bool Desplegar1(string UserName);                   //depediendo del usuario ingresado saca una clave del txt para comparar con la ingresada por el usuario

    int cantidad();                                     //la uso para saber el tamaño de la matriz que uso en desplegar1

    void imprimir_combos();                             //la uso para que el usuario vea el menu de combos

    void desplegar_inventario(map<string,conten> &invetory); //la uso para la funcion imprimir y para poder manejar los productos mas facilmente
};


#endif // USER_H
