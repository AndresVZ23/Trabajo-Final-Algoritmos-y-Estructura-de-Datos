#pragma once
#include <functional>
using namespace std;

template <class T>
class ArbolBB {

    template <class T>
    class Nodo {
    public:
        T elem;
        Nodo* izquierdo;
        Nodo* derecha;
    };

    typedef function<int(T, T)> Comp;
    Nodo<T>* rz;
    void(*desarrollo)(T);
    Comp cotejar;
private:
    bool Buscar(Nodo<T>* nodo, T e) {
        if (nodo == nullptr) {
            return false;
        }
        else {
            int r = cotejar(nodo->elem, e);
            if (r == 0) {
                return true;
            }
            else if (r < 0) {
                return Buscar(nodo->derecha, e);
            }
            else {
                return Buscar(nodo->izquierdo, e);
            }
        }
    }

    Nodo<T>* Obtener(Nodo<T>* nodo, T e) {
        if (nodo == nullptr) {
            return nullptr;
        }
        else {
            int r = cotejar(nodo->elem, e);
            if (r == 0) {
                return nodo;
            }
            else if (r < 0) {
                return Buscar(nodo->derecha, e);
            }
            else {
                return Buscar(nodo->izquierdo, e);
            }
        }
    }

    bool Insertar(Nodo<T>*& nodo, T e) {

        if (nodo == nullptr) {
            nodo = new Nodo<T>();
            nodo->elem = e;
            return true;
        }
        else {
            int r = cotejar(nodo->elem, e);
            if (r == 0) {
                return false;
            }
            else if (r < 0) {
                return Insertar(nodo->derecha, e);
            }
            else {
                return Insertar(nodo->izquierdo, e);
            }
        }
    }

    void EnOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return;
        }
        EnOrden(nodo->izquierdo);
        desarrollo(nodo->elem);
        EnOrden(nodo->derecha);
    }

    void PreOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return;
        }
        desarrollo(nodo->elem);
        PreOrden(nodo->izquierdo);
        PreOrden(nodo->derecha);
    }

    void PostOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return;
        }
        PostOrden(nodo->izquierdo);
        PostOrden(nodo->derecha);
        desarrollo(nodo->elem);
    }
    bool EsVacio() {
        return rz == nullptr;
    }
    int Cantidaltder(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        else {
            int cantizq, cantder;
            cantizq = Cantidaltder(nodo->izquierdo);
            cantder = Cantidaltder(nodo->derecha);
            return 1 + cantizq + cantder;
        }
    }

    int Altura(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        else {
            int altizq, altder;
            altizq = 1 + Altura(nodo->izquierdo);
            altder = 1 + Altura(nodo->derecha);
            return altizq > altder ? altizq : altder;
        }
    }

    int Min(Nodo<T>* nodo) {
        if (nodo->izquierdo == nullptr) {
            return nodo->elem;
        }
        else {
            return Min(nodo->izquierdo);
        }
    }

    int Max(Nodo<T>* nodo) {
        if (nodo->derecha == nullptr) {
            return nodo->elem;
        }
        else {
            return Max(nodo->derecha);
        }
    }

    bool Borrar(Nodo<T>*& nodo, T e) {
        if (nodo == nullptr) {
            return false;
        }
        else {
            int r = cotejar(nodo->elem, e);
            if (r < 0) {
                return Borrar(nodo->derecha, e);
            }
            else if (r > 0) {
                return Borrar(nodo->izquierdo, e);
            }
            else {
                if (nodo->derecha == nullptr && nodo->izquierdo == nullptr) {
                    nodo = nullptr;
                    delete nodo;
                    return true;
                }
                else if (nodo->izquierdo == nullptr) {
                    nodo = nodo->derecha;
                    return true;
                }
                else if (nodo->derecha == nullptr) {
                    nodo = nodo->izquierdo;
                    return true;
                }
                else {
                    Nodo<T>* aux = nodo->derecha;
                    while (aux->izquierdo != nullptr) {
                        aux = aux->izquierdo;
                    }
                    nodo->elem = aux->elem;
                    return Borrar(nodo->derecha, aux->elem);
                }
            }
        }
    }

public:
    ArbolBB(void(*otroPunteroAFuncantizqon)(T)) {
        this->desarrollo = otroPunteroAFuncantizqon;
        this->cotejar = [](T a, T b)->int {return a - b; };
        rz = nullptr;
    }
    bool insertar(T e) {
        return Insertar(rz, e);
    }
    void enOrden() {
        EnOrden(rz);
    }
    void preOrden() {
        PreOrden(rz);
    }
    void postOrden() {
        PostOrden(rz);
    }
    int cantidaltder() {
        return Cantidaltder(rz);
    }
    int altura() {
        return Altura(rz);
    }
    bool Buscar(T e) {
        return Buscar(rz, e);
    }
    int Minimo() {
        return Min(rz);
    }
    int Maximo() {
        return Max(rz);
    }
    bool Borrar(T e) {
        return Borrar(rz, e);
    }
};
