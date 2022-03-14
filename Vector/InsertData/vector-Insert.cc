/*
A este archivo se le agregaron todas las funciones necesarias para
una funcion que inserta un nuevo dato dentro del vector en una
posicion especifica que sera pasada por parametro
Contiene:
-Funcion "Insert"
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
    Funcion que inserta un elemento en una posicion dada por el 
    usuario, esto lo hace recibiendo 2 parametros; Primero uno de
    tipo 'T' llamado 'elem' e indica el dato que va a estar entrando
    y otro de tipo 'size_t' indica la posicion en la que va a quedar
    guardado el dato.
    Lo primero que hara la funcion es revisar si tiene suficiente
    espacio para realizar la accion
    Luego se ubica en la posicion deseada para guardar el dato y 
    mueve todos los elementos a la derecha desde ahi
    Despues de eso inserta el elemento deseado en la posicion que
    quedo libre
    Finalmente indica el aumento de tamaño del vector
    */
    void insert(T elem, size_t pos)
    {
        //Verificar si es necesario aumento de tamaño
        if (sz == capacity) {
            resize();
        }

        //Mover elementos a la derecha
        for(int i = sz; i > pos ;i--)
        {
            storage[i + 1] = storage[i];
        }

        //Guardar dato en posicion dada
        storage[pos] = elem;

        //Indicar aumento de tamaño
        sz++;
    }
    //FIN CAMBIOS
};

int main() {
	
    Vector<int> a;
    for (int i = 0; i < 10; i++)
    {
    	a.push_back(4);
	}

    a.insert(5, 6);
    a.print();

    return 0;
}