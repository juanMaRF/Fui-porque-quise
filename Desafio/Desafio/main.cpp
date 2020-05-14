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
    bool confirmacion,x=true,y=true;
    string usuario1,clave1,saldo1,cc,clave_client,puesto,UserName1,nom_item,cost,cantidad,ID,nom_item1,cantidad1; //inicializo las variables que voy a usar
    while(y){
    cout << "Bienvenido." << endl;
    cout << "\n";
    cout << "Que desea hacer."<< "\n" << endl;
    cout << "A. Ingresar como administrador." << endl; //usuario sudo y password AbCd
    cout << "B. Ingresar como usuario." << endl;
    cout << "C. Salir." << endl;                        //termina el ciclo
    cout << "***********EVITE COLOCAR ORACIONES O PALABRAS CON ESPACIOS, GRACIAS.***********"<< endl;

    cin>>selec;
    if (selec=='A'){
        User admon;                                 //inicializo el objeto con el nombre admon
        admon.combos.clear();                       //lo hago para evitar problemas al cargar del txt
        cout << "Ingrese el usuario." << endl; cin>>usuario1;
        cout << "Ingrese la clave." << endl; cin>>clave1;
        if(admon.admin(usuario1,clave1)==true){
            cout << "Si desea realizar alguna accion ingrese 1 de lo contrario ingrese otro caracter." << endl; cin>>pp;
            if (pp==1)
                x=true;     //el usuario decide cuando salir de ese menu
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

                    admon.agreg_invent(ID,nom_item,cantidad,cost); //invoco la funcion para agregar al inventario
                }
                else if(selec=='B'){
                    admon.crear_combo();        //invoco la funcion para crear un combo
                    //admon.imprimir_combos();
                }
                else if(selec=='C'){
                    admon.Reg_T();              //si el administrador decide registrar las ventas del dia de hoy se guardaran en el archivo txt
                }
                else if(selec=='D'){
                    cout<<"Inrese la cedula del usuario."<<endl; cin>>cc;
                    cout<<"Ingrese su clave"<<endl; cin>>clave_client;
                    admon.agregar_user(cc,clave_client);  //agrego el usuario

                }
                else if(selec=='E'){
                    admon.actual_txt(); //actualizo toda la informacion creadaa y cambiada de los mapas a los txt
                    x=false;//termino el ciclo
                }
            }
        }
    }
    else if(selec=='B'){
        cout<<"Ingrese su cedula: ";
        cin>>UserName1;
        User Usuario;
        confirmacion=Usuario.Desplegar1(UserName1);
        if (confirmacion==true){                        //ingresa como un usuario prebiamente registrado
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
                Usuario.imprimir_combos();              //imprimo la cartelera de combos para que el usuario pueda comprar
                cout << "Menu:" << "\n" << endl;
                cout << "A. Comprar un combo." << endl;
                cout << "B. Salir." << endl;
                cin>>selec;
                if(selec=='A'){
                    string sala,puesto;
                    Usuario.compra(UserName1);  //meto el usuario en la funcion para que sea mas facil guardar en el registro

                }else if(selec=='B'){
                    x=false;
                }
            }
        }


    }
    else if(selec=='C'){
        y=false;
        remove("registro_temp.txt"); //si el admin no decidio guardar registros se borra el archivo temporal y se deja el anterior
    }
}
    return 0;
}
