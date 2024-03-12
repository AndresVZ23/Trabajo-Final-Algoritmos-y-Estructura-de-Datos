#pragma once
#include <iostream>
#include <vector>
#include "Persona.h"
#include "Contacto.h"
#include "HashTable.h"
#include "Lista.h"
#include "Grafo.h"
using namespace std;

template<typename T>
T nCont(T _ncontactos) {
    return _ncontactos;
}

class Usuario {
private:
    HashTablaA ht = HashTablaA();   
    Lista<Contacto*>* listaContacto;
    Lista<Persona*>* listaPersona;
    vector <Contacto*> vecContacto;
    CGrafo<int>* grafoedad = new CGrafo<int>();
    int nContactos, nPersonas;

public:
    Usuario();
    ~Usuario();
    void opMostrarPerfil();
    void opMostrarContactos();
    void agregarContacto();
    void opEditarPerfil();
    void funcionCrearPersona(Persona* c);
    void funcionCrearContacto(Contacto* c);
    vector<Contacto*> getVecContacto();
    void opAgregarContacto();
    void mostrarHTContacto();
    void GrafosEdadesContactos();
};

Usuario::Usuario() {    
    listaContacto = new Lista<Contacto*>();
    listaPersona = new Lista<Persona*>();
    nContactos = 0;
    nPersonas = 0;
}

Usuario::~Usuario() {}

void Usuario::opMostrarPerfil() {
    system("cls");
    cout << "===========================================";
    cout << "\n================ MI PERFIL ================";
    cout << "\n===========================================\n";
    if (listaPersona == nullptr) {
        cout << "No hay perfiles para mostrar." << endl;
    }
    else {        
        listaPersona->print([](Persona* u) {u->mostrarPerfil(); });      
    }
    cout << "===========================================\n";
}

void Usuario::opMostrarContactos() {
    system("cls");
    cout << "========================================================================";
    cout << "\n========== CONTACTOS ==========\t" << " Cantidad de Contactos Agregados:  " << nCont(nContactos) << endl;
    cout << "========================================================================\n";
   
    if (listaContacto == nullptr) {
        cout << "No hay contactos aniadidos para mostrar." << endl;
    }
    else {        
        listaContacto->print([](Contacto* u) {u->mostrarContacto(); });        
    }
}

void Usuario::funcionCrearPersona(Persona* c) {
    listaPersona->push(c);
}

void Usuario::funcionCrearContacto(Contacto* c) {
    listaContacto->push(c);
    vecContacto.push_back(c);
}

vector<Contacto*> Usuario::getVecContacto() {
    return vecContacto;
}

void Usuario::agregarContacto() {
    system("cls");
    cout << "============================================";
    cout << "\n============= AGREGAR CONTACTO =============\n";
    cout << "============================================";
    string _nombre;
    string _apellido;
    char _sexo;
    int _edad;
    int _celular;
    string _correo;
    cout << "\n DATOS DEL CONTACTO\n";
    cin.clear();
    cin.ignore();
    cout << " Nombre: ";
    getline(cin, _nombre);
    cout << " Apellido: ";
    getline(cin, _apellido);
    cout << " Sexo (M: Masculino || F: Femenino): ";
    cin >> _sexo;
    cout << " Numero de celular: ";
    cin >> _celular;
    cout << " Correo: ";
    cin >> _correo;
    cout << " Edad: ";
    cin >> _edad;
    cout << "\n\nPresionar cualquier tecla\n";
    Contacto* _nodo = new Contacto(_nombre, _apellido, _sexo, _celular, _correo, _edad);    
    funcionCrearContacto(_nodo);
    ht.insert(HashEntidad(_nombre, _edad));
    nContactos++;
}

void Usuario::opEditarPerfil() {
    system("cls");
    cout << "============================================";
    cout << "\n============= REGISTRAR PERFIL =============\n";
    cout << "============================================";
    Persona* _persona;
    string _nombre;
    string _apellido;
    int _celular;
    string _correo;
    string _nacionalidad;
    int _edad;
    char _sexo;
    string _estudios;
    string _descripcion;
    string _experiencia;
    cout << "\n REGISTRE SUS DATOS\n";
    cin.clear();
    cin.ignore();
    cout << " Nombre: ";
    getline(cin, _nombre);
    cout << " Apellido: ";
    getline(cin, _apellido);
    cout << " Carrera Estudiada: ";
    getline(cin, _estudios);
    cout << " Descripcion: ";
    getline(cin, _descripcion);
    cout << " Experiencia: ";
    getline(cin, _experiencia);
    cout << " Numero de celular: ";
    cin >> _celular;
    cout << " Correo: ";
    cin >> _correo;
    cout << " Pais: ";
    cin >> _nacionalidad;
    cout << " Edad: ";
    cin >> _edad;
    cout << " Sexo (M: Masculino || F: Femenino): ";
    cin >> _sexo;
    cout << "\n\nPresionar cualquier tecla\n";
    Persona* _nodo = new Persona(_nombre, _apellido, _celular, _correo, _nacionalidad, _edad, _sexo, _estudios, _descripcion, _experiencia);
    funcionCrearPersona(_nodo);
}

void Usuario::mostrarHTContacto() {
    ht.DispAll();
}

void Usuario::GrafosEdadesContactos() {
    system("cls");
    cout << "========================================" << endl;
    cout << "  Contactos que se relacionan por Edad" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < vecContacto.size(); i++) {
        cout << "\t" << i << " -> ";
        cout << vecContacto[i]->getNombre();
        cout << endl;
        grafoedad->adicionarVertice(i);
    }

    for (int i = 0; i < vecContacto.size(); i++) {
        int cArcos = 0;
        for (int j = 0; j < vecContacto.size(); j++) {
            if (i != j && vecContacto[i]->getEdad() == vecContacto[j]->getEdad()) {
                grafoedad->adicionarArco(i, j);
                grafoedad->modificarArco(i, cArcos, j);
                cArcos++;
            }
        }
    }

    for (int i = 0; i < grafoedad->cantidadVertices(); ++i) {
        cout << "\t" << "Contacto " << grafoedad->obtenerVertice(i) << ": ";
        for (int j = 0; j < grafoedad->cantidadArcos(i); j++) {
            cout << grafoedad->obtenerArco(i, j) << "->";
        }
        cout << " ";
        cout << endl;
    }
    cout << "========================================" << endl;
}