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
            cla+=temp;                      //meto la clave en un string
        }
    }
    leer.close();                                                               //esta funcion es para ingresar como admin sacando la clave de un txt
    if(usua=="sudo"){
        if(clave_==cla){
            cout << "A ingresado correctamente como administrador." << endl;
            cout << "Bienvenido." << endl;
            return true;            //true si el ingreso fue correcto
        }
        else{
            cout << "Ingreso denegado, clave incorrecta." << endl;
            return false;               //false si el ingreso es malo
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
    cout<<"| ID |         Producto                |  Cantidad         | Precio |"<<endl;            //imprimo la cabecera de l cartelera
    cout<<"+-------------------------------------------------------------------+"<<endl;
    desplegar_inventario(invent);           //meto lo que hay en el txt en el mapa global del inventario
    map<string,conten>::iterator it;        //creo el iterador para recorrer el mapa para imprimirlo
    for(it=invent.begin();it!=invent.end();*it++){  //creo el ciclo para recorrer el mapa
        cout<<"| "<<it->first<<" |         "<<it->second.nombre<<"                |  "<<it->second.cantidad<<"         | "<<it->second.costo<<" |"<<endl; //e imprimo cada cosa del mapa
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
    int y,cant_menos,cant1,num_com=num_combo(),precio; //inicializo las variables y establesco el numero del siguiente combo
    string item,nom_com,cant2,cant3;
    conten p;
    map<string,int> parte;    //creo el mapa que va a estar dentro de otro mapa

    desplegar_combos(combos);  //meto todos los combos en el mapa
    do{
        cout << "Ingrese el ID del producto." << endl; cin>>item;
        cout << "Ingrese la cantidad." << endl; cin>>cant_menos;
        map<string,conten>::iterator it;
        for(it=invent.begin();it!=invent.end();*it++){
            if(item==it->first){                        //itero en el inventarioy busco en el la id ingresada
                cant1=stoi(it->second.cantidad);
                cant1=cant1-cant_menos;
                cant2=to_string(cant_menos);
                nom_com=nom_com+cant2;                  //luego la concateno todo conta cantidad ingresada para crear el nombre
                nom_com=nom_com+' ';
                nom_com=nom_com+it->second.nombre;
                //cant3=to_string(cant1);
                //it->second.cantidad=cant3;
                parte.insert(pair<string,int>(it->second.nombre,cant_menos));  //y lo añado en el mapa interno
            }
        }


        cout << "Desea seguir agregando productos a este combo? (ingrese 1 si lo desea)" << endl; cin>>y; //es el loop para ingresar los productos que quiera hasta que quiera
        if (y!=1){
            x=false;
            combs.insert(pair<int,map<string,int>>(num_com,parte));  //cuado ya no va a ingresar mas productos lo mete a un mapa con el mapa interno y su clave es el numero del combo
        }else{
            nom_com=nom_com+'+'; //si desea seguir agregando mas le concatena un mas en el nombre, es estetico
        }
    }while(x);
    cout<<"Ingrese el precio de este combo."<<endl; cin>>precio;
    ofstream escri;
    escri.open("combos.txt",ios::app);      //abro el archivo para escribir en el los combos
    escri<<num_com<<';'<<nom_com<<';'<<precio<<'\n';
    escri.close();
    p.nombre=nom_com;
    p.costo=to_string(precio);//le doy valores a la estructura solo que en esta ocacion no va a tener cantidad
    combos.insert(pair<string,conten>(to_string(num_com),p)); //lo meto en un mapa que uso para imprimir el combo
    cout<<"SE AGREGO A LA LISTA DE COMBOS." << endl;
    ofstream es;
    es.open("combs_cod.txt",ios::app);//abro otro archivo txt para el manipular los combos mas facilmente
    map<int,map<string,int>>::iterator itera;
    map<string,int>::iterator iter; //creo dos iteradores para iterar en el mapa exterior y en el interior
    for(itera=combs.begin();itera!=combs.end();*itera++){//recorro el mapa exterio
        es<<itera->first;
        for(iter=itera->second.begin();iter!=itera->second.end();*iter++){//recorro el mapa interior
            es<<';'<<iter->second<<';'<<iter->first;//lo escribo en el txt
        }
        es<<'\n';
    }
    es.close();

}

void User::agregar_user(string cedula_, string clave_)
{
    ofstream registro;
    registro.open("usuarios.txt", ios::app); //abro el archivo para escribir en el desde la ultima posicion que encuentre
    if (registro.fail())
        cerr << "Error" << endl;//si falla en abrir salta este error
    registro<<cedula_;
    registro<<" ";
    registro<<clave_;//escribo en el txt
    registro<<endl;
}
bool User::Desplegar1(string UserName){
    bool flag=false;
    string datos;
    string arreglo[cantidad()][3];//en esta ocacion uso un arreglo bidimencional ya que asi lo tenia en la anterior practica
    int contador1=0,contador2=0,contador3=0;
    ifstream registro;
    registro.open("usuarios.txt", ios::in);//abro el archivo
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
        if (tem!=' ' and tem!='\n'){
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
    registro.open("usuarios.txt", ios::in);//abro el txt de usuarios
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();                        //cuento la cantidad de usuarios registrados
    if (registro.good()){
        if (tem=='\n'){         //se sabe cuantos usuarios hay dependiendo de la cantidad de \n
            cantidadparaarreglo+=1;
            }
        }
    }
    return cantidadparaarreglo;
}

void User::imprimir_combos()
{
    cout<<"+----------------------------------------------+"<<endl;
    cout<<"| # |         Producto                | Precio |"<<endl;//imprimo la cabecera de los combos
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
                    //invetory.insert(pair<string,conten>(id,r)); //guardo las variables en el mapa
                    invetory[id]=r;
                    archiv.clear();
                }
            }
            else{
                archiv+=temp; //meto el temp en un string
            }
        }

    }
    leec.close();  
}

int User::num_combo() //ve retorna el numero del combo siguiente
{
    int num=1;
    ifstream lee;
    lee.open("combos.txt"); //abro el txt de los combos
    while(lee.good()){
        char temp=lee.get();//mientras abra el while seguira iterando
        if(lee.good()){
            if (temp=='\n'){        //se cuantos combos hay dependiendo de la cantidad de \n
                num++; //variable a retornar
            }
        }
    }
    return num;
}

void User::compra(string user)
{
    bool c=true; //la uso para un ciclo
    string id_,nombre,puesto; //inicializo las variables a usar
    int id,Dinero,dine=Dinero;
    cout << "Por favor, seleccione el numero del combo." << endl; cin>>id_;
    map<string,conten>::iterator iter; //creo el iterador del mapa de los combos que tiene el precio
    for(iter=combos.begin();iter!=combos.end();*iter++){
        if(id_==iter->first){
            int div[]={50000,20000,10000,5000,2000,1000,500,200,100,50}; //doy uso al problema de la practica 2, creando arreglos
            int res[10]={0};
            int din=stoi(iter->second.costo); //establesco el costo del combo
            cout<<"ingrese la cantidad de dinero: "<<endl;
            cin>>Dinero; //el dinero del usuario
            if(Dinero<din){
                cout<<"cantidad insuficiente."<<endl;//si el dinero del usuario es menor que el del combo se sale de este ciclo
                break;
            }else{
                Dinero=Dinero-din;     //si es mayor procede a dar el residuo
                cout<<"DEVUELTAS:"<<endl;
            for(int i=0;i<10;i++)
            {
                res[i]=Dinero/ div[i]; //divido el dinero por las cifras establecidas
                Dinero=Dinero% div[i]; //saco el residuo

                if(res[i]!=0){   //imprimo solo las posisiones en las que el residuo no es 0
                cout<<div[i]<<" : "<<res[i]<<endl;
                }

            }

            cout<<"Faltante: "<<Dinero<<endl; //imprime si le queda un valor menor que 50

            c=false; //la uso para confirmar que estro a esta parte y si no entro es porque no encontro el combo
            }
        }
        if(c)
            cout<<"Este combo no existe."<<endl; //al no encontrar el combo imprime esto
    }
    if(!c){//si no encuentra el combo no entra aqui
    id=stoi(id_);
    mpa_cargar(combs);
    desplegar_inventario(invent); //cargo los mapas en caso de que no se ingrese como admin anteriormente
    map<int,map<string,int>>::iterator i;
    map<string,int>::iterator itera;
    map<string,conten>::iterator repe;//creo los tres iteradores para el mapa grande y el de su interior y el del inventario para restar las existencias
    bool pre=true; //lo creo en caso de que el producto no tenga existencias
    for(i=combs.begin();i!=combs.end();*i++){//itero en el mapa grande
        if(id==i->first){ //si comparo el numero deel combo para ingresar en el debido
            for(itera=i->second.begin();itera!=i->second.end();*itera++){//itero en el mapa pequeño que hay en el mapa grande, perdon por no saber como expresarme
                for(repe=invent.begin();repe!=invent.end();*repe++){//itero en el mapa del inventario
                    if(itera->first==repe->second.nombre){//comparo los nombres para quitarle existencias al correcto
                        int temp=stoi(repe->second.cantidad);//en temp guardo las existencias del producto
                        if(temp<itera->second){//compara si las existencias son menores a lo que ofrece el combo
                            cout<<"Este combo no tiene existencias, porfavor informar al administrador."<<endl;
                            cout<<"Se le devuelven los: "<<dine<<endl; //si es asi se le devuelve el dinero y no queda ningun registro
                            pre=false;
                            break;
                        }
                        repe->second.cantidad=to_string(temp-itera->second);//si llega aqui se resta lo del combo a las existencias
                        if(!pre)
                            break;//cuando no hay existencias rompe los ciclos
                }
                    if(!pre)
                        break;//rompe el ciclo
            }
                if(!pre)
                    break;//rompe el ciclo
            }
            if(!pre)
                break;//rompe el ciclo
        }
        if(!pre)
            break;//rompe el ciclo

    }
    if(pre){//si hay existencias entra aqui
    string sala,puesto;
    cout<< "su compra se a realizado con exito."<<endl;
    actual_txt(); //actualizo todo los cambiado en los mapas
    cout<<"Ingrese su sala."<<endl; cin>>sala;//le pido al usuario que ingrese sus datos para que quede evidencia en el registro
    cout<<"Ingrese su puesto."<<endl; cin>>puesto;
    Registro(sala,puesto,user);//realizo el registro
    }
    }
}

void User::desplegar_combos(map<string,conten> &combs_)
{
    ifstream leec;
    string archiv,id,pord,prec;
    conten r;
    int conta=0;
    leec.open("combos.txt");//abro el archivo que tiene los precios de los combos
    while(leec.good()){
        char temp=leec.get();//cada char  lo guardo en un string exeptuando si es ; o \n
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
                 else if(temp=='\n'){//cada \n es un combo diferente
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

}

void User::actual_txt()  //cuando edito algo del invenatrio se actualiza en el txt por medio de un iterador y un ciclo for
{
    ofstream escri;
    escri.open("inventario.txt");
    map<string,conten>::iterator it;
    for(it=invent.begin();it!=invent.end();*it++){
        escri<<it->first<<';'<<it->second.nombre<<';'<<it->second.cantidad<<';'<<it->second.costo<<'\n';//simplemente escribo en los txt lo que hay en los mapas
    }
}

void User::Registro(string x_, string puesto_, string user)
{
    ifstream leec;
    string regis;
    leec.open("registro.txt");      //abro el archivo de registros original
    while (leec.good()) {
        char tem=leec.get();
        if (leec.good()){
            regis+=tem;             //lo meto en un string
        }
    }
    ofstream escri;
    escri.open("registro_temp.txt",ios::app);
    escri<<regis;                       //escribo el original en una copia
    escri<<"Sala "<<x_<<" puesto "<<puesto_<<" por el usuario con la cedula: "<<user<<'\n'; //escribo los datos de compras recientes
    escri.close();
}

void User::Reg_T() //cuando el administrador decide actualizar el registro se cambia el temporal por el original y el original se borra
{
    remove("registro.txt");
    rename("registro_temp.txt","registro.txt");
}

void User::mpa_cargar(map<int, map<string, int> > &combs1_)
{
    ifstream lee;
    string archiv1,id_,pord_,can;
    map<string,int> parte;
    int conta_=0,can1,id1;
    lee.open("combs_cod.txt"); //guardo de forma mas ordenada los combos para poder usarlos mas facil
    while(lee.good()){
        char temp=lee.get();
        if(lee.good()){
            if(temp=='\n' || temp==';'){
                if(temp==';'){
                    if(conta_==0){
                        id_=archiv1;//este no lo meto en la estructura ya que es la clave en el mapa
                        id1=stoi(id_);
                        conta_++;
                    }else if(conta_==1){
                        can=archiv1;//c¿guardo la cantidad que se ofrece en cada combo y  la combierto en un int
                        can1=stoi(can);
                        conta_++; //el contador me sirve para diferenciar entre el numero del combo la cantidad del combo y su nombre
                    }else if(conta_==2){
                        pord_=archiv1;
                        conta_++;
                    }
                    else if(conta_==3){
                    parte[pord_]=can1;//guardo cada producto que tiene el combo
                    conta_=2; //lo reinicio en 2 ya que no necesita pasar otra ves por el numero del combo o la cantidad
                    can=archiv1;
                    can1=stoi(can);
                    }
                    archiv1.clear();//tengo que vaciar el string despues de darle el valor a algo


                }
                 else if(temp=='\n'){//cambia de combo pero antes tengo que guardar todo lo hecho
                    conta_=0;
                    pord_=archiv1;
                    parte[pord_]=can1;
                    combs1_.insert(pair<int, map<string, int>>(id1,parte));//y los guardo por medio de el numero del combo
                    archiv1.clear();//vacio el string para su uso
                    parte.clear();//vacio el mapa que esta adrentro para que no se me acumulen
                }
            }
            else{
                archiv1+=temp; //voy guardando en el string las palabras
            }
        }

    }
}

