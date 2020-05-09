#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "user.h"

using namespace std;

int main()
{
    char selec;

    string usuario1,clave1,saldo1;
    cout << "Bienvenido." << endl;
    cout << "\n";
    cout << "Que desea hacer."<< "\n" << endl;
    cout << "A. Ingresar como administrador." << endl;
    cout << "B. Ingresar como usuario." << endl;
    cout << "C. Registrarse." << endl;
    cin>>selec;

    if (selec=='A'){
        User admon;
        cout << "Ingrese el usuario." << endl; cin>>usuario1;
        cout << "Ingrese la clave." << endl; cin>>clave1;
        admon.admin(usuario1,clave1);
        cout << "A. Mostrar invetario." << endl;
        cout << "B. Crear un combo." << endl;
        cout << "C. Crear un reporte de ventas." << endl;
        cin>>selec;
        if(selec=='A'){

        }
    }
    else if(selec=='B'){

    }
    else if(selec=='C'){

    }

    return 0;
}
