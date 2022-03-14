/*
A este archivo se le agregaron todas las funciones necesarias para
una funcion que elimine elementos al final del vector
Contiene: 
-Funcion "popBack"
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
    
    void push_front(T elem)
    {
    	if (sz == capacity)
    	{
    		resize();
		}
		
		moveElement();
		
		storage[0] = elem;
		
		sz++;
	}
	
	void moveElement()
	{
		for (int i = sz; i > 0; i--)
		{
			storage[i] = storage[i - 1];
		}
	}

    //INICIO CAMBIOS
    /*
    Funcion que elimina el ultimo elemento de un vector, esto lo hace
    sacando del conteo de elementos a el ultimo de estos, de esta
    forma el ultimo elemento se volvera parte de la basura contenida
    en la diferencia entre 'sz' y 'storage'
    */
    void pop_back()
    {
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
    
    for (int i = 0; i < 10; i++)
    {
    	a.push_front(8);
	}
    a.print();

    a.pop_back();
    a.print();
    
    return 0;
}