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

    void resizeSub()
    {
        T* ns = new T[capacity - 1];
        for (size_t i = 0; i < sz; i++)
        {
            ns[i] = storage[i];
        }

        delete [] storage;
        storage = ns;
        capacity--;
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
    
    //INICIO DE PUSH FRONT

    //Funcion De Taller
    void push_front(T elem)
    {
    	//Crear nuevo espacio
    	if (sz == capacity)
    	{
    		resize();
		}
		
		//Mover elementos del vector a la derecha
		moveElement();
		
		//Agregar nuevo elemento al inicio
		storage[0] = elem;
		
		sz++;
	}
	
	//Subfuncion de reposicionamiento de elementos del vector
	void moveElement()
	{
		for (int i = sz; i > 0; i--)
		{
			storage[i] = storage[i - 1];
		}
	}
    //FIN DE PUSH FRONT

    //INICIO DE POP BACK
    void pop_back()
    {
        resizeSub();
        sz--;
    }


    //FIN DE POP BACK
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