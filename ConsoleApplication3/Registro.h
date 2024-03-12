#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;

class Registro {
private:
    string productos;
    string marcas;
    int precio;
    int id;

public:
    Registro(string _producto, string _marcas) {
        productos = _producto;
        marcas = _marcas;
        precio = rand() % 420 + 15;
        id = 0 + rand() % 999;
    }
    ~Registro() {}

    void setId(int id) { this->id = id; }
    string getproducto() { return productos; }
    string getmarcas() { return marcas; }
    int getprecio() { return precio; }
    int getId() const {
        return id;
    }

    void ToString() {
        cout << "  Producto: " << getproducto() << endl;
        cout << "  Marca: " << getmarcas() << endl;
        cout << "  Precio: " << getprecio() << endl;
        cout << "  ID: " << getId() << "\t" << endl;
    }
};
