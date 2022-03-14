/*
A este archivo se le agregaron todas las funciones necesarias para 
una funcion que elimine el elemento del final del vector en 
cada ejecucion
Contiene:
-Funcion "popFront"
*/
#include <iostream>

using namespace std;

template<typename T>
class Vector {
private:
	
    size_t sz;
    size_t capacity;
    T* storage;
    
public:
	
    Vector() {
        sz = 0;
        capacity = 7;
        storage = new T[capacity];
    }
    
private:
	
    void resize() {
        T* ns = new T[capacity * 2];
        for(size_t i = 0; i < sz; i++) {
            ns[i] = storage[i];
        }
        delete [] storage;
        storage = ns;
        capacity = capacity * 2;
    }
    
public:
	
    void push_back(T elem) {
        if (sz == capacity) {
            resize();
        }
        storage[sz] = elem;
        sz++;
    }

    size_t size() {
        return sz;
    }
    
    void print() {
        for (size_t i = 0; i < size(); i++)
            cout << " " << storage[i];
        cout << endl;
    }

    //INICIO CAMBIOS
    /*
    Funcion que elimina el primer elemento de un vector, esto lo hace 
    moviendo hacia la izquierda todos los componentes del vector 
    haciendo que eventualmente el primero salga del vector.
    Tiene la desventaja que debe mover todos y cada uno de los
    elementos del vector, por lo que si el vector es muy grande tal
    vez de problemas de rendimiento
    */
    void pop_front()
    {
        //Mover los componentes
        for (int i = 1; i < sz; i++)
        {
            storage[i - 1] = storage[i];
        }

        //Informar sobre la reduccion del tamaño
        sz--;
    }
    //FIN CAMBIOS
};

int main() {
	
    Vector<int> a;
    for (int i = 0; i < 10; i++)
    {
    	a.push_back(4);
	}
    a.print();

    a.pop_front();
    a.print();

    return 0;
}