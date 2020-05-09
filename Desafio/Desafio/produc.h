#ifndef PRODUC_H
#define PRODUC_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
struct conten                   //creo una estructura para el mapa de inventario que contiene el nombre, la cantidad y el costo del porducto
{
    conten(string nombre,int cantidad,int costo) {}
};

class produc                    //creo la clase para los productos, con la clave que es el ID y la estructura
{
    map<string,conten> productos;
public:
    produc();
};

#endif // PRODUC_H
