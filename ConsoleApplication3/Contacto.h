#pragma once
#include <iostream>
#include "Persona.h"
using namespace std;

class Contacto {
private:
    string nombre;
    string apellido;
    char sexo;
    int celular;
    int edad;
    string correo;
    Persona* persona;
public:
    Contacto(string _nombre, string _apellido, char _sexo, int _celular, string _correo, int edad);
    ~Contacto();
    Persona* getPersona();
    string getNombre();
    int getEdad();
    void mostrarContacto();
};

Contacto::Contacto(string _nombre, string _apellido, char _sexo, int _celular, string _correo, int _edad) {
    nombre = _nombre;
    apellido = _apellido;
    sexo = _sexo;
    celular = _celular;
    correo = _correo;
    edad = _edad;

}

Contacto::~Contacto() {
    if (persona != NULL) delete persona;
}

Persona* Contacto::getPersona() { return persona; }

string Contacto::getNombre() { return nombre; }

int Contacto::getEdad() { return edad; }

void Contacto::mostrarContacto() {
    cout << " Nombre y Apellido: " << this->nombre << " " << this->apellido << endl;
    cout << " Sexo (M: Masculino || F: Femenino): " << this->sexo << endl;
    cout << " Edad:" << this->edad << endl;
    cout << " Numero de celular: " << this->celular << endl;
    cout << " Correo: " << this->correo << endl;
    cout << " =============================================================" << endl;
}