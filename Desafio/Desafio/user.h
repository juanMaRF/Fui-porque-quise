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
    map<string,conten> invent;

    map<string,conten> combos;

    map<int,map<string,int>> combs;

    User();

    bool admin(string usua,string clave_);              //ingresar como admin

    void imprimir();                                    //imprimir el inventario

    void agreg_invent(string ID_,string nom_,string cant_,string cost_);//agregar cosas al inventario

    void crear_combo();                                 //crear un combo

    void agregar_user(string cedula_,string clave_);    //agrega un usuario

    bool Desplegar1(string UserName);                   //depediendo del usuario ingresado saca una clave del txt para comparar con la ingresada por el usuario

    int cantidad();                                     //la uso para saber el tamaño de la matriz que uso en desplegar1

    void imprimir_combos();                             //la uso para que el usuario vea el menu de combos

    void desplegar_inventario(map<string,conten> &invetory); //la uso para la funcion imprimir y para poder manejar los productos mas facilmente

    int num_combo();                                    //retorna el numero de combos que hay en el txt contando los \n

    void compra(string user);                                      //permite al usuario comprar combos

    void desplegar_combos(map<string,conten> &combs_);  //saca del txt los combos y los guarda en un mapa para mejor uso al imprimir

    void actual_txt();                                  //actualizo los txt

    void Registro(string x_,string puesto_,string user); //guardo las compras recientes

    void Reg_T();                                        //si el admin decide guardar registros se agregaran de lo contrario no

    void mpa_cargar(map<int,map<string,int>> &combs1_);  //cargo un mapa con los combos mas organizados para su implementacion
};


#endif // USER_H
