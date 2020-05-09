#include "user.h"

User::User()
{

}

User::User(string cedula_, string clave_, string saldo_)//cree un construsctor de usuario que directamente me metiera los usuarios en un txt
{
    cedula=cedula_;
    clave=clave_;
    saldo=saldo_;
    ofstream escri;
    escri.open("usuarios.txt",ios::app);
    escri<<cedula<<" "<<clave<<" "<<saldo<<"\n";
    escri.close();
}

void User::admin(string usua, string clave_)
{
    ifstream leer;
    leer.open("sudo.txt",ios::in);
    string cla;
    while(leer.good()){
        char temp=leer.get();
        if(leer.good()){
            cla+=temp;
        }
    }
    leer.close();                                                               //esta funcion es para ingresar como admin sacando la clave de un txt
    if(usua=="sudo"){
        if(clave_==cla){
            cout << "A ingresado correctamente como administrador." << endl;
            cout << "Bienvenido." << endl;
        }
        else{
            cout << "Ingreso denegado, clave incorrecta." << endl;
        }
    }
    else{
        cout << "Ingreso denegado, usuario incorrecto." << endl;
    }

}

void User::imprimir()
{
    ifstream leec;
    leec.open("inventario.txt");
    cout<<"+-------------------------------------------------------------------+"<<endl;
    cout<<"| ID |         Producto                |  Cantidad         | Precio |"<<endl;
    cout<<"+-------------------------------------------------------------------+"<<endl;
}
