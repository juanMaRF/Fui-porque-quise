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
    int pp;
    bool confirmacion,x=true;
    string usuario1,clave1,saldo1,cc,clave_client,puesto,UserName1;
    cout << "Bienvenido." << endl;
    cout << "\n";
    cout << "Que desea hacer."<< "\n" << endl;
    cout << "A. Ingresar como administrador." << endl;
    cout << "B. Ingresar como usuario." << endl;

    cin>>selec;
    if (selec=='A'){
        User admon;
        cout << "Ingrese el usuario." << endl; cin>>usuario1;
        cout << "Ingrese la clave." << endl; cin>>clave1;
        if(admon.admin(usuario1,clave1)==true){
            cout << "Si desea realizar alguna accion ingrese 1 de lo contrario ingrese otro caracter." << endl; cin>>pp;
            if (pp==1)
                x=true;
            while(x==true){
                cout<<"MENU"<<endl;
                cout << "A. Mostrar invetario." << endl;
                cout << "B. Crear un combo." << endl;
                cout << "C. Crear un reporte de ventas." << endl;
                cout << "D. Registrar usuario." << endl;
                cout << "E. Salir." << endl;
                cin>>selec;
                if(selec=='A'){
                    admon.imprimir();
                }
                else if(selec=='B'){

                }
                else if(selec=='C'){

                }
                else if(selec=='D'){
                    cout<<"Inrese la cedula del usuario."<<endl; cin>>cc;
                    cout<<"Ingrese su clave"<<endl; cin>>clave_client;
                    admon.agregar_user(cc,clave_client);

                }
                else if(selec=='E'){
                    x=false;
                }
            }
        }
    }
    else if(selec=='B'){
        cout<<"Ingrese su cedula: ";
        cin>>UserName1;
        User Usuario;
        confirmacion=Usuario.Desplegar1(UserName1);
        if (confirmacion==true){
            cout<< "acceso permitido"<<endl;
        }
        else {
            cout << "acceso denegado"<<endl;
        }
        if (confirmacion==true){
            cout << "Si desea realizar alguna accion ingrese 1 de lo contrario ingrese otro caracter." << endl; cin>>pp;
            if(pp==1)
                x=true;
            while(x==true){
                cout << "Menu:" << "\n" << endl;

                cout << "" << endl;
            }
        }

    }

    return 0;
}
