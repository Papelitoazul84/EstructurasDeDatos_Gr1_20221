/*
Este es el codigo inicial para el vector, esta tal y como lo entrego el profesor las funciones aqui agregadas fueron las 
que el entrego por su cuenta en clase.
Contiene:
-Constructor
-Funcion "Resize"
    El resize trae el aumento en '*2', para cambiarlo hacerlo en la propia funcion
-Funcion "push_back"
-Funcion "size"
-Funcion "print"
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
	
    //Constructor del vector con las respectivas inicializaciones de variables
    Vector() {
        sz = 0;
        capacity = 7;
        storage = new T[capacity];
    }
    
private:
	
    /*
    Esta funcion aumenta el tamaño del vector, aumenta la cantidad de cosas que se pueden meter en el antes de tener que ejecutarlo de nuevo
    ADVERTENCIA: El uso de esta funcion requiere un alto uso de memoria por lo que siempre se debe buscar la forma de ejecutarla lo menos posible
    Para cambiar el indice de aumento del vector en cada ejecucion se debe cambier en 'Creacion del vector en el heap' y en 'Cambio del valor de capacity'
    */
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

    //Funcion publica (Llamable desde el main) que permite meter un elemento al final de la lista
    void push_back(T elem) {
        if (sz == capacity) {
            resize();
        }
        storage[sz] = elem;
        sz++;
    }

    //Funcion publica que retorna la cantidad de elementos dentro del vector
    size_t size() {
        return sz;
    }
    
    /*
    Funcion que imprime los elementos que tenga el vector (No entra dentro del espacio aun no ocupado del vector), su tamaño se ve limitado por
    la variable 'sz'
    */
    void print() {
        for (size_t i = 0; i < size(); i++)
            cout << " " << storage[i];
        cout << endl;
    }
};

int main() {
	
    Vector<int> a;

    for (int i = 0; i < 10; i++)
    {
    	a.push_back(4);
	}
    a.print();
    
    return 0;
}