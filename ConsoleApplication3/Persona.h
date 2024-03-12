#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    string apellido;
    int celular;
    string correo;
    string nacionalidad;
    int edad;
    char sexo;
    string estudios;
    string descripcion;
    string experiencia;
public:   
    Persona(string pnombre, string papellido, int pcelular, string pcorreo, string pnacionalidad, int pedad, char psexo, string pestudios, string pdescripcion, string pexperiencia);
    ~Persona();
    string getNombre();
    int getEdad();
    void mostrarPerfil();   
};

Persona::Persona(string pnombre, string papellido, int pcelular, string pcorreo, string pnacionalidad, int pedad, char psexo, string pestudios, string pdescripcion, string pexperiencia) {
    nombre = pnombre;
    apellido = papellido;
    celular = pcelular;
    correo = pcorreo;
    nacionalidad = pnacionalidad;
    edad = pedad;
    sexo = psexo;
    estudios = pestudios;
    descripcion = pdescripcion;
    experiencia = pexperiencia;
}

Persona::~Persona() {}

string Persona::getNombre() { return nombre; }

int Persona::getEdad() { return edad; }

void Persona::mostrarPerfil() {
    cout << " Nombre y Apellido: " << this->nombre << " " << this->apellido << endl;
    cout << " Nacionalidad: " << this->nacionalidad << endl;
    cout << " Numero de celular: " << this->celular << endl;
    cout << " Correo: " << this->correo << endl;
    cout << " Edad: " << this->edad << endl;
    cout << " Sexo (M: Masculino || F: Femenino): " << this->sexo << endl;
    cout << " Carrera estudiada: " << this->estudios << endl;
    cout << " Descripcion: " << this->descripcion << endl;
    cout << " Experiencia: " << this->experiencia << endl;
}