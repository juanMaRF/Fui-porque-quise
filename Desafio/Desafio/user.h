#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
class User
{
    string cedula,clave,saldo;
public:
    User();

    User(string cedula_,string clave_,string saldo_);   //un constructor un poco mas complejo

    void admin(string usua,string clave_);              //ingresar como admin

    void imprimir();                                    //imprimir el inventario

    void agreg_invent();                                //agregar cosas al inventario

    void wombo_combo();                                 //crear un combo
};

#endif // USER_H
