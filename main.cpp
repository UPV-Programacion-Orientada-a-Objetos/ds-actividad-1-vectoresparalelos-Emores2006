#include <iostream>
#include <fstream>
#include <string>


void ingresar_datos();
int main() {
    bool res=true;
    char opc;
    int s= 100;
    std::string nombre[s];
    std::string pais[s];
    std::string disciplina[s];
    std::string genero[s];
    std::string oro[s];

    //inicialiar los vectores en 100 y si el archivo exede el numero de 100 ponerle el arcivo exede la cantidad de personas que puede haber en el archivo
    //hacer validaciones de generos, disciplinas, 

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

}