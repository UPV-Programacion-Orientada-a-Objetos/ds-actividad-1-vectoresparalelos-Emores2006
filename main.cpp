#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


void ingresar_datos();
void agregar();
void informacion();
void totaloro();
void masoro();
bool guardar_datos(const std::string ruta, const std::string nombre, const std::string pais, const std::string disciplina, const std::string genero, int oros);

const int s= 100;
std::string nombre[s];
std::string pais[s];
std::string disciplina[s];
std::string genero[s];
int oro[s];
int contador =0;

int main() {
    bool res=true;
    char opc;

    ingresar_datos();

    while (true)
    {
        std::cout<<"Menu:"<<std::endl;
        std::cout<<"1.-Agregar nuevo atleta."<<std::endl;
        std::cout<<"2.-Buscar informacion de un atleta."<<std::endl;
        std::cout<<"3.-Calcular el total de medallas de oro de un pais."<<std::endl;
        std::cout<<"4.-Encontrar el atleta con mas medallas de oro."<<std::endl;
        std::cout<<"Ingrese el numero de la opcion del menu que desea realizar"<<std::endl;
        std::cin>>opc;

        switch (opc)
        {
        case '1':
            std::cout<<"\n Agregar nuevo atleta"<<std::endl;
            agregar();

            break;
        
        case '2':
            std::cout<<"\n Buscar informacion de un atleta"<<std::endl;
            informacion();
            break;

        case '3':
            std::cout<<"\n Calcular el total de medallas de oro de un pais."<<std::endl;
            totaloro();

            break;

        case '4':
            std::cout<<"\n Encontrar el atleta con mas medallas de oro"<<std::endl;
            masoro();

            break;

        default:
            std::cout<<"\n Ingrese una opcion valida \n"<<std::endl;
            break;
        }
        


    }
    
    return 0;
}
void ingresar_datos(){

    std::ifstream archivo("data/data1.csv");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo datos.csv\n";
        return;
    }

    std::string linea;
    
    if (std::getline(archivo, linea)) {
        if (linea.find("nombre") == std::string::npos || linea.find(',') == std::string::npos) {
            archivo.clear();
            archivo.seekg(0);
        }
    }

    int agregados = 0;
    while (std::getline(archivo, linea)) {
        if (contador >= s) {
            std::cout << "Se alcanzó el máximo de " << s << " atletas. El resto no se cargará.\n";
            break;
        }
        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string c_nombre, c_pais, c_disc, c_genero, c_oro;

        std::getline(ss, c_nombre, ',');
        std::getline(ss, c_pais, ',');
        std::getline(ss, c_disc, ',');
        std::getline(ss, c_genero, ',');
        std::getline(ss, c_oro, ',');

        // Validar medallas
        int oro_val = 0;
        try {
            oro_val = std::stoi(c_oro);
            if (oro_val < 0) throw std::invalid_argument("negativo");
        } catch (...) {
            std::cout << "Fila ignorada (oro invalido): " << linea << "\n";
            continue;
        }

        // Guardar en arrays
        nombre[contador]     = c_nombre;
        pais[contador]       = c_pais;
        disciplina[contador] = c_disc;
        genero[contador]     = c_genero;
        oro[contador]        = oro_val;

        contador++;
        agregados++;
    }

    archivo.close();
    std::cout << "Carga completada. Atletas agregados: " << agregados<< ". Total almacenados: " << contador << "/" << s << ".\n";

}

void agregar(){

    std::string disciplinas_validas[] = {
    "Atletismo", "Natacion", "Gimnasia", "Judo", "Taekwondo",
    "Boxeo", "Ciclismo", "Esgrima", "Futbol", "Halterofilia",
    "Remo", "Tenis", "Tiro", "Lucha", "Baloncesto"};

    std::string nombre;
    std::string pais;
    std::string disciplina;
    std::string genero;
    int oros;
    bool validad=false;
    bool validg=false;

    std::cout<<"Ingrese el nombre completo de el Atleta a agregar"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout<<"Ingrese EL pais de origen del Atleta"<<std::endl;
    std::getline(std::cin, pais); 

    while(!validad){
        std::cout<<"Ingrese la disciplina del atleta"<<std::endl;
        std::cin>>disciplina;

        for (int i = 0; i <15; i++)
        {
            if (disciplina == disciplinas_validas[i]) {
                validad = true;
                break;
            }
        }
        if (!validad) {
            std::cout << "Disciplina no valida: " << disciplina<< ". Intente de nuevo (ejemplos: Atletismo, Natacion, Judo...)"<<std::endl;
        }
    }

    while (!validg){
        std::cout<<"Ingrese el genero de el/la atleta (M para masculino y F para fememino)"<<std::endl;
        std::cin>>genero;
        if (genero=="M" || genero=="F")
        {
            std::cout<<"Genero valido"<<std::endl;
            validg=true;
        }
        else{
            std::cout<<"Genero invalido. Debe ser M o F."<<std::endl;
        }
    }

    std::cout<<"Ingrese el numero de medallas de oro con las que cuenta"<<std::endl;
    std::cin>>oros;


    if (guardar_datos("data/data1.csv", nombre, pais, disciplina, genero, oros)) {
    std::cout << "Atleta guardado \n" <<std::endl;
    }   
    else {
    std::cout << "Atleta no guadrado vuelva a intentarlo \n"<< std::endl;
    }

    main();
}

bool guardar_datos(const std::string ruta, const std::string nombre, const std::string pais, const std::string disciplina, const std::string genero, int oros){

    std::ofstream out(ruta, std::ios::app);
    if (!out.is_open()) {
    
        return false;
    }

    out << nombre << ","<< pais << ","<< disciplina << ","<< genero << ","<< oros << "\n";
    return true;
}

void informacion(){

    std:: string nombre1;
    std::cout<<"Ingrese el nombre del atleta del que desea conocer sus datos"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre1);

    for (int i = 0; i < s; i++){


        if (nombre1==nombre[i])
        {
            std::cout<<"Datos del Atleta"<<std::endl;
            std::cout<<"Nombre: "<< nombre[i]<<std::endl;
            std::cout<<"Pais: "<< pais[i]<<std::endl;
            std::cout<<"Discipline: "<< disciplina[i]<<std::endl;
            std::cout<<"Genero: "<< genero[i]<<std::endl;
            std::cout<<"Cantidad de medallas de oro: "<< oro[i]<<std::endl;
            std::cout<<" "<<std::endl;

            main();
        }
        
    }
    std::cout<<"No esta registrado el atleta "<< nombre1<<" en el archivo"<<std::endl;
    std::cout<<" "<<std::endl;
            
    main();
    
}

void totaloro(){

    std::string pais1;
    int cantidad = 0;

    std::cout<<"Ingrese el nombre del pais del que busca conocer el total de medallas de oro con las que cuenta"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, pais1);
    for (int i = 0; i < s; i++)
    {
        if (pais1==pais[i]){
            cantidad += oro[i];
        }
    }
    if(cantidad==0){
        std::cout<<"No existe el pais en el documento"<<std::endl;
        std::cout<<" "<<std::endl;
        main();
    }

    std::cout<<"El total de medallas de oro de " << pais1<< " es: "<<cantidad<<std::endl;
    main();
}

void masoro(){

    int pos = 0;

    std::cout<<"Buscando el atleta con mas medallas de oro...."<<std::endl;

    for (int i = 1; i < s; i++)
    {
        if (oro[i]>oro[pos]){
            pos=i;
        }
    }

    int mayor = oro[pos];
    
    for (int i = 0; i < s; i++)
    {
        if (mayor==oro[i]){
            std::cout<<"Datos del Atleta con mas medallas de oro"<<std::endl;
            std::cout<<"Nombre: "<< nombre[i]<<std::endl;
            std::cout<<"Pais: "<< pais[i]<<std::endl;
            std::cout<<"Discipline: "<< disciplina[i]<<std::endl;
            std::cout<<"Genero: "<< genero[i]<<std::endl;
            std::cout<<"Cantidad de medallas de oro: "<< oro[i]<<std::endl;
            std::cout<<" "<<std::endl;
        }
    }
    
    main();


    
}
