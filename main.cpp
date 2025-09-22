#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


void ingresar_datos();
void agregar();
void informacion();
void totaloro();
void masoro();

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

    //inicialiar los vectores en 100 y si el archivo exede el numero de 100 ponerle el arcivo exede la cantidad de personas que puede haber en el archivo
    //hacer validaciones de generos, disciplinas, 
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

            break;
        
        case '2':
            std::cout<<"\n Buscar informacion de un atleta"<<std::endl;

            break;

        case '3':
            std::cout<<"\n Calcular el total de medallas de oro de un pais."<<std::endl;

            break;

        case '4':
            std::cout<<"\n Encontrar el atleta con mas medallas de oro"<<std::endl;

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
    // Saltar encabezado si existe
    if (std::getline(archivo, linea)) {
        if (linea.find("nombre") == std::string::npos || linea.find(',') == std::string::npos) {
            // No era encabezado → volver al inicio
            archivo.clear();
            archivo.seekg(0);
        }
    }

    int agregados = 0;
    while (std::getline(archivo, linea)) {
        if (contador >= s) {
            std::cout << "⚠️ Se alcanzó el máximo de " << s<< " atletas. El resto no se cargará.\n";
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

}

void informacion(){

}

void totaloro(){

}

void masoro(){

}
