/*
A este archivo se le agregaron todas las funciones necesarias para
una funcion que agregue elementos al vector en la parte del frente
Contiene:
-Funcion "pushFront"
-Funcion auxiliar "moveElement"
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
    Funcion que pone un nuevo elemento al inicio del vector,
    esto lo hace mediante el uso de una funcion auxiliar que mueve
    cada elemento a la derecha (puede ser modificada para que 
    mueva los elementos desde una posicion especifica).

    Recibe por parametro un dato de tipo T
    */
    void push_front(T elem)
    {
    	//En caso de ser necesario aumenta el tamaño del vector
    	if (sz == capacity)
    	{
    		resize();
		}
		
		//Ejecuta subfuncion que mueve a la derecha todos los elementos
		moveElement();
		
		//Agregar nuevo elemento en la posicion 0 del vector
		storage[0] = elem;
		
        //Indica al vector que ahora tiene un elemento extra
		sz++;
	}
	
    //Subfuncion
	void moveElement()
	{
		for (int i = sz; i > 0; i--)
		{
			storage[i] = storage[i - 1];
		}
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
    
    for (int i = 0; i < 10; i++)
    {
    	a.push_front(8);
	}
    a.print();
    
    return 0;
}