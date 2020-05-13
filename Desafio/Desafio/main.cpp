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
    string usuario1,clave1,saldo1,cc,clave_client,puesto,UserName1,nom_item,cost,cantidad,ID,nom_item1,cantidad1;
    cout << "Bienvenido." << endl;
    cout << "\n";
    cout << "Que desea hacer."<< "\n" << endl;
    cout << "A. Ingresar como administrador." << endl;
    cout << "B. Ingresar como usuario." << endl;

    cin>>selec;
    if (selec=='A'){
        User admon;
        admon.combos.clear();
        cout << "Ingrese el usuario." << endl; cin>>usuario1;
        cout << "Ingrese la clave." << endl; cin>>clave1;
        if(admon.admin(usuario1,clave1)==true){
            cout << "Si desea realizar alguna accion ingrese 1 de lo contrario ingrese otro caracter." << endl; cin>>pp;
            if (pp==1)
                x=true;
            while(x==true){
                cout << "INVETARIO." << endl;
                admon.imprimir(); cout<<'\n';
                cout<<"MENU"<<endl;
                cout << "A. Agregar algo al inventario." << endl;
                cout << "B. Crear un combo." << endl;
                cout << "C. Registrar ventas del dia." << endl;
                cout << "D. Registrar usuario." << endl;
                cout << "E. Salir." << endl;
                cin>>selec;
                if(selec=='A'){
                    cout << "Ingrese el ID del producto." << endl; cin>>ID;
                    cout << "Ingrese el nombre del producto.(cambie los espacios por '_')" << endl; cin>>nom_item; //hay un problema al agregar un string que contenga espacios
                    cout << "Ingrese la cantidad de este producto." << endl; cin>>cantidad;
                    cout << "Ingrese el costo de este producto." << endl; cin>>cost;

                    admon.agreg_invent(ID,nom_item,cantidad,cost);
                }
                else if(selec=='B'){
                    admon.crear_combo();
                    //admon.imprimir_combos();
                }
                else if(selec=='C'){

                }
                else if(selec=='D'){
                    cout<<"Inrese la cedula del usuario."<<endl; cin>>cc;
                    cout<<"Ingrese su clave"<<endl; cin>>clave_client;
                    admon.agregar_user(cc,clave_client);

                }
                else if(selec=='E'){
                    admon.actual_txt();
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
                cout << "COMBOS." << endl;
                Usuario.imprimir_combos();
                cout << "Menu:" << "\n" << endl;
                cout << "A. Comprar un combo." << endl;
                cout << "B. Salir." << endl;
                cin>>selec;
                if(selec=='A'){

                }else if(selec=='B'){
                    x=false;
                }
            }
        }

    }

    return 0;
}
