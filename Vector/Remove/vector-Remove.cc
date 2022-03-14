/*
A este archivo se le agregaron todas las funciones necesarias para 
una funcion que elimina uno de los datos del vector en una posicion
especifica que es pasada por parametro
Contiene:
-Funcion "remove"
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
    Funcion que eliminar un elemento en una posicion dada por el 
    usuario, esto lo hace recibiendo 1 parametro de tipo 'size_t'
    llamado 'pos' el cual indica la posicion del dato a eliminar.
    Lo primero que hara la funcion es ubicarse en el dato que se
    quiere eliminar.
    Luego hara que este dato se reescriba con todos los datos que hay
    posterior a este de modo que se podria decir que quedo 'eliminado'
    Finalmente indica la reduccion de tamaño
    */
    void remove(size_t pos)
    {
        //Posicionamiento y reescritura
        for(int i = pos; i < sz; i++)
        {
            storage[i] = storage[i + 1];
        }

        //Indicar reduccion de tamaño
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
    
    a.remove(2);
    a.print();

    return 0;
}