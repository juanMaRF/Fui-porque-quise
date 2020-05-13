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
    desplegar_inventario(invent);           //meto lo que hay en el txt en el mapa global del inventario
    map<string,conten>::iterator it;        //creo el iterador para recorrer el mapa para imprimirlo
    for(it=invent.begin();it!=invent.end();*it++){  //creo el ciclo para recorrer el mapa
        cout<<"| "<<it->first<<" |         "<<it->second.nombre<<"                |  "<<it->second.cantidad<<"         | "<<it->second.costo<<" |"<<endl;
        cout<<"+-------------------------------------------------------------------+"<<endl;
    }
}

void User::agreg_invent(string ID_, string nom_, string cant_, string cost_)
{
    ofstream escri;
    escri.open("inventario.txt",ios::app); //abro el archivo para escribir en el desde la ultima posicion que encuentre
    escri<<ID_<<";"<<nom_<<";"<<cant_<<";"<<cost_<<"\n";  //separo las variables por ; para que sea facil separarlas al cargar el archivo
}

void User::crear_combo()
{
    bool x=true;
    int y,cant_menos,cant1,num_com=num_combo(),precio;
    string item,nom_com,cant2,cant3;
    conten p;
    desplegar_combos(combos);
    do{
        cout << "Ingrese el ID del producto." << endl; cin>>item;
        cout << "Ingrese la cantidad." << endl; cin>>cant_menos;
        map<string,conten>::iterator it;
        for(it=invent.begin();it!=invent.end();*it++){
            if(item==it->first){
                cant1=stoi(it->second.cantidad);
                cant1=cant1-cant_menos;
                cant2=to_string(cant_menos);
                nom_com=nom_com+cant2;
                nom_com=nom_com+' ';
                nom_com=nom_com+it->second.nombre;
                cant3=to_string(cant1);
                it->second.cantidad=cant3;
            }
        }


        cout << "Desea seguir agregando productos a este combo? (ingrese 1 si lo desea)" << endl; cin>>y;
        if (y!=1){
            x=false;
        }else{
            nom_com=nom_com+'+';
        }
    }while(x);
    cout<<"Ingrese el precio de este combo."<<endl; cin>>precio;
    ofstream escri;
    escri.open("combos.txt",ios::app);
    escri<<num_com<<';'<<nom_com<<';'<<precio<<'\n';
    escri.close();
    p.nombre=nom_com;
    p.costo=to_string(precio);
    combos.insert(pair<string,conten>(to_string(num_com),p));
    cout<<"SE AGREGO A LA LISTA DE COMBOS." << endl;
}

void User::agregar_user(string cedula_, string clave_)
{
    ofstream registro;
    registro.open("usuarios.txt", ios::app); //abro el archivo para escribir en el desde la ultima posicion que encuentre
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

void User::imprimir_combos()
{
    cout<<"+----------------------------------------------+"<<endl;
    cout<<"| # |         Producto                | Precio |"<<endl;
    cout<<"+----------------------------------------------+"<<endl;
    desplegar_combos(combos);
    map<string,conten>::iterator it;        //creo el iterador para recorrer el mapa para imprimirlo
    for(it=combos.begin();it!=combos.end();*it++){  //creo el ciclo para recorrer el mapa
        cout<<"| "<<it->first<<" | "<<it->second.nombre<<" | "<<it->second.costo<<" |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
    }
}

void User::desplegar_inventario(map<string,conten> &invetory)      //meto el mapa por refernecia
{
    ifstream leec;
    string archiv,id,pord,cant,prec;
    conten r;
    int conta=0;
    leec.open("inventario.txt");
    while(leec.good()){
        char temp=leec.get();
        if(leec.good()){
            if(temp=='\n' || temp==';'){
                if(temp==';'){
                    if(conta==0){
                        id=archiv;//este no lo meto en la estructura ya que es la clave en el mapa

                    }else if(conta==1){
                        r.nombre=archiv; //doy valores a la estructura
                    }else if(conta==2){
                        r.cantidad=archiv;//doy valores a la estructura
                    }

                    archiv.clear();             //cargo los archivos del txt a un mapa
                    conta++;
                }
                 else if(temp=='\n'){
                    conta=0;
                    r.costo=archiv;//doy valores a la estructura
                    invetory.insert(pair<string,conten>(id,r)); //guardo las variables en el mapa
                    archiv.clear();
                }
            }
            else{
                archiv+=temp;
            }
        }

    }
    leec.close();  
}

int User::num_combo()
{
    int num=1;
    ifstream lee;
    lee.open("combos.txt");
    while(lee.good()){
        char temp=lee.get();
        if(lee.good()){
            if (temp=='\n'){
                num++;
            }
        }
    }
    return num;
}

void User::compra()
{
    bool c=true;
    string id_,nombre;
    cout << "Por favor, seleccione el numero del combo." << endl; cin>>id_;
    map<string,conten>::iterator it;
    for(it=combos.begin();it!=combos.end();*it++){
        if(id_==it->first){
            nombre=it->second.nombre;

            c=false;
        }
        if(c)
            cout<<"Este combo no existe."<<endl;
    }
}

void User::desplegar_combos(map<string, conten> &combs_)
{
    ifstream leec;
    string archiv,id,pord,prec;
    conten r;
    int conta=0;
    leec.open("combos.txt");
    while(leec.good()){
        char temp=leec.get();
        if(leec.good()){
            if(temp=='\n' || temp==';'){
                if(temp==';'){
                    if(conta==0){
                        id=archiv;//este no lo meto en la estructura ya que es la clave en el mapa

                    }else if(conta==1){
                        r.nombre=archiv; //doy valores a la estructura
                    }
                    archiv.clear();             //cargo los archivos del txt a un mapa
                    conta++;
                }
                 else if(temp=='\n'){
                    conta=0;
                    r.costo=archiv;//doy valores a la estructura
                    combs_.insert(pair<string,conten>(id,r)); //guardo las variables en el mapa
                    archiv.clear();
                }
            }
            else{
                archiv+=temp;
            }
        }

    }
    leec.close();
}

void User::actual_txt()
{
    ofstream escri;
    escri.open("inventario.txt");
    map<string,conten>::iterator it;
    for(it=invent.begin();it!=invent.end();*it++){
        escri<<it->first<<';'<<it->second.nombre<<';'<<it->second.cantidad<<';'<<it->second.costo<<'\n';
    }
}

bool User::existencias(string id_)
{
    string nombre,prod;
    cout << "Por favor, seleccione el numero del combo." << endl; cin>>id_;
    map<string,conten>::iterator it;
    for(it=combos.begin();it!=combos.end();*it++){
        if(id_==it->first){
            nombre=it->second.nombre;
        }
    }
    for(int i=nombre.find(' ');nombre.at(i)!='+';i++){
        prod=prod+nombre.at(i);
    }
    desplegar_inventario(invent);
    map<string,conten>::iterator itera;
    for(itera=invent.begin();itera!=invent.end();*itera++){
        if(prod==itera->second.nombre){

        }
    }
}
