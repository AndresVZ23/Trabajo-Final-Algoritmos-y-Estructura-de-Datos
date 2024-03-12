#include "pch.h"
#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "ArbolBB.h"
#include "Registro.h"
#include "MergeSort.h"
#include "HashEntidad.h"
#include "HashTable.h"
#include "Usuario.h"
using namespace std;

string producto[9] = { "Laptop ", "Polo ","Lavadora ","Televisor ", "Camiseta ","Zapatilla ","Computadora ", "Pizarra ", "Pelota " };
string marca[9] = { " Sony", " Apple"," Windows"," Xbox", " Puma"," Adidas"," Nike", " Marvel", " DC" };

void Menu() {
    cout << " ===========================================================" << endl;
    cout << "|                       CONNECTIFY UPC                      |" << endl;
    cout << " ===========================================================" << endl;
    cout << "| Registrar Perfil .....................................(1) |" << endl;
    cout << "| Mostrar Perfil .......................................(2) |" << endl;
    cout << "| Agregar Contacto .....................................(3) |" << endl;
    cout << "| Mostrar Contacto .....................................(4) |" << endl;
    cout << "| Hash Table de Edades de los Contactos ................(5) |" << endl;
    cout << "| Grafos de Relaciones por Edades ......................(6) |" << endl;
    cout << "| Busqueda Binaria por Nombre de Contacto ..............(7) |" << endl;
    cout << "| Productos Recomendados para el Usuario ...............(8) |" << endl;
    cout << "| Productos Recomendados Ordenados por Precio ..........(9) |" << endl;
    cout << "| Salir de la aplicacion ..............................(10) |" << endl;
    cout << " ===========================================================" << endl;
}

void imp(Registro* reg) {
    cout << " " << reg->getId() << endl;
}

bool compId(const Registro* primreg, const Registro* secreg) {
    return primreg->getId() < secreg->getId();
}

void BBporNombre(const vector<Contacto*>& rgs, string nombre) {
    int bajo = 0;
    int alto = rgs.size() - 1;
    bool encontrado = false;    
    for (int i = 0; i < rgs.size(); i++) {
        if (rgs[i]->getNombre() == nombre) {
            rgs[i]->mostrarContacto();
            encontrado = true;
            break;
        }          
    }
    if (encontrado == false) {
        cout << " Contacto no encontrado :(\n\n";
    }
}

int main() {
    int opcion;
    int n = 150;
    int size = 1500;
    int* llaves = new int[size];
    int idIncog;
    Registro* res;
    Usuario* oUsuario = new Usuario();

    vector<Registro*> objReg;

    ArbolBB<Registro*>* arbol = new ArbolBB<Registro*>(imp);

    string nombreabuscar;
    vector<Contacto*> veccontacto;
    
    while (true) {
        Menu();
        cout << "  Opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            oUsuario->opEditarPerfil();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            oUsuario->opMostrarPerfil();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            oUsuario->agregarContacto();            
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            oUsuario->opMostrarContactos();                        
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << " ===================================================" << endl;
            cout << "|       Hash Table de Edades de los Contactos       |" << endl;
            cout << " ===================================================" << endl;
            oUsuario->mostrarHTContacto();
            cout << " ===================================================" << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            oUsuario->GrafosEdadesContactos();
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            veccontacto = oUsuario->getVecContacto();
            cout << " =============================================================" << endl;
            cout << "|           Realizar la busqueda binaria por Nombre           |" << endl;
            cout << " =============================================================" << endl;
            cout << "  Ingrese el nombre del contacto que desea buscar: ";
            cin >> nombreabuscar;
            cout << " =============================================================" << endl;
            BBporNombre(veccontacto, nombreabuscar);
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            cout << " ====================================================" << endl;
            cout << "|       Productos Recomendados para el Usuario       |" << endl;
            cout << " ====================================================" << endl;
            for (int i = 0; i < 10; i++) {
                objReg.push_back(new Registro(producto[rand() % 9], marca[rand() % 9]));
            }
            for (int i = 0; i < 10; i++) {
                cout << " Posicion " << i + 1 << " :" << endl;
                objReg[i]->ToString();
                cout << endl;
            }
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            cout << " ===================================================" << endl;
            cout << "|             Ordenamiento por Precios              |" << endl;
            cout << " ===================================================" << endl;
            mergeSort(objReg, n);
            for (int i = 0; i < n; i++) {
                cout << "| Posicion " << i + 1 << endl;
                cout << "| --------------------------------------------------\n";
                cout << "| Producto: " << objReg[i]->getproducto() << endl;
                cout << "| Marca: " << objReg[i]->getmarcas() << endl;
                cout << "| Precio: " << objReg[i]->getprecio() << endl;
                cout << "| ID: " << objReg[i]->getId() << "\t";
                cout << endl;
                cout << " ===================================================\n";
            }
            system("pause");
            system("cls");
            break;        
        case 10:
            cout << "\n\n==============================================================";
            cout << "\n====== GRACIAS POR UTILIZAR CONNECTIFY UPC, HASTA LUEGO ======\n";
            cout << "==============================================================\n\n";
            exit(0);
            break;
        default:
            break;
        }
    }

    delete[] llaves;
    delete arbol;
    for (int i = 0; i < objReg.size(); i++) {
        delete objReg[i];
    }
    objReg.clear();
    cin.get();
    return 0;
}