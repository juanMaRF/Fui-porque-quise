#include "user.h"

User::User()
{

}

bool User::admin(string usua, string clave_)
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
            return true;
        }
        else{
            cout << "Ingreso denegado, clave incorrecta." << endl;
            return false;
        }
    }
    else{
        cout << "Ingreso denegado, usuario incorrecto." << endl;
        return false;
    }

}

void User::imprimir()
{
    cout<<"+-------------------------------------------------------------------+"<<endl;
    cout<<"| ID |         Producto                |  Cantidad         | Precio |"<<endl;
    cout<<"+-------------------------------------------------------------------+"<<endl;
    ifstream leec;
    string archiv,id,pord,cant,prec;
    conten r;
    int conta=0;
    map<string,conten> invetory;
    leec.open("inventario.txt");
    while(leec.good()){
        char temp=leec.get();
        if(leec.good()){
            if(temp=='\n' || temp==' '){
                if(temp==' '){
                    if(conta==0){
                        id=archiv;

                    }else if(conta==1){
                        //r.nombre=archiv;
                        pord=archiv;
                    }else if(conta==2){
                       // r.cantidad=archiv;
                        cant=archiv;
                    }

                    archiv.clear();
                    conta++;
                }
                 else if(temp=='\n'){
                    conta=0;
                    //r.costo=archiv;
                    prec=archiv;
                    //invetory.insert(pair<string,conten>(id,r));
                    archiv.clear();
                    cout<<"| "<<id<<" |         "<<pord<<"                |  "<<cant<<"         | "<<prec<<" |"<<endl;
                }
            }
            else{
                archiv+=temp;
            }
        }

    }
    leec.close();


}

void User::agreg_invent(string ID_, string nom_, string cant_, string cost_)
{
    ofstream escri;
    escri.open("inventario.txt",ios::app);
    escri<<ID_<<" "<<nom_<<" "<<cant_<<" "<<cost_<<"\n";
}

void User::agregar_user(string cedula_, string clave_)
{
    ofstream registro;
    registro.open("usuarios.txt", ios::app);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<cedula_;
    registro<<" ";
    registro<<clave_;
    registro<<endl;
}
bool User::Desplegar1(string UserName){
    bool flag=false;
    string datos;
    string arreglo[cantidad()][3];
    int contador1=0,contador2=0,contador3=0;
    ifstream registro;
    registro.open("usuarios.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
    if (registro.good()){

        if (tem==' ' || tem=='\n'){                     //la cc y la clave van a estar separados por ' ' y cada '\n' es un usuario diferente
            arreglo[contador2][contador1]=datos;        //guardo el usuario
            contador1=contador1+1;                      //sumo una posicion para guardar la clave
            if (tem=='\n'){
                contador2=contador2+1;                  //sumo para guardar otro usuario
                contador1=0;                            //se pone en 0 para la posicion del usuario
            }
            datos="";
            }
        if (tem!=' '){
            datos+=tem;                             //en datos se guarda la cc o la clave
            }
        }
    }
    string key,user,compararclave;
    for (int t=0;t<(cantidad()-1);t++){
        user=arreglo[contador3][0];
        if (UserName==user){
            flag=true;                      //aqui busco cual es el usuario correcto recorriendo el arreglo
            break;
        }
            contador3+=1;                   //cuando no es el usuario le sumo 1
    }
    compararclave=arreglo[contador3][1];    //ya sabemos cual es la posicion del usuario ahora solo accedemos a la clave
        if (flag==true){
            cout<<"ingrese clave: ";
            cin>>key;
            if(key==compararclave){         //y la comparamos con la ingresada
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
}

int User::cantidad()
{
    int cantidadparaarreglo=1;
    ifstream registro;
    registro.open("usuarios.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();                        //cuento la cantidad de usuarios registrados
    if (registro.good()){
        if (tem=='\n'){
            cantidadparaarreglo+=1;
            }
        }
    }
    return cantidadparaarreglo;
}

void User::desplegar_inventario(map<string,conten> &invetory)      //entro el mapa
{
    ifstream leec;
    string archiv,id,pord,cant,prec;
    conten r;
    int conta=0;
    leec.open("inventario.txt");
    while(leec.good()){
        char temp=leec.get();
        if(leec.good()){
            if(temp=='\n' || temp==' '){
                if(temp==' '){
                    if(conta==0){
                        id=archiv;

                    }else if(conta==1){
                        r.nombre=archiv;
                    }else if(conta==2){
                        r.cantidad=archiv;
                    }

                    archiv.clear();
                    conta++;
                }
                 else if(temp=='\n'){
                    conta=0;
                    r.costo=archiv;
                    invetory.insert(pair<string,conten>(id,r));
                }
            }
            else{
                archiv+=temp;
            }
        }

    }
    leec.close();


}
