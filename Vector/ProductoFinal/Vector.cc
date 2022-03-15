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

    void resize(int mv)
    {
        T* ns = new T[capacity + mv];
        for(size_t i = 0; i < sz; i++) {
            ns[i] = storage[i];
        }
        delete [] storage;
        storage = ns;
        capacity = capacity + mv;
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

    //INICIO DE POP FRONT
    void pop_front()
    {
        //Mover todos los componentes hacia la izquierda, excepto el primero este simplemente se re-escribira
        for (int i = 1; i < sz; i++)
        {
            storage[i - 1] = storage[i];
        }

        //Ejecutar la reduccion del tamaño del vector
        resizeSub();
        sz--;
    }
    //FIN DE POP FRONT

    //INICIO DE INSERT
    void insert(T elem, size_t pos)
    {
        //Aumentar el espacio en el vector
        if (sz == capacity) {
            resize();
        }

        //Mover elementos desde "pos" hacia la derecha, dejando el espacio para guardar el elemento
        for(int i = sz; i > pos ;i--)
        {
            storage[i + 1] = storage[i];
        }

        storage[pos] = elem;

        sz++;
    }
    //FIN DE INSERT

    //INICIO DE REMOVE
    void remove(size_t pos)
    {
        for(int i = pos; i < sz; i++)
        {
            storage[i] = storage[i + 1];
        }

        resizeSub();
        sz--;
    }
    //FIN DE REMOVE

    //INICIO DE INSERT VECTOR
    void insertVector(Vector<T> other, size_t pos)
    {
        //Reservar el espacio para todos los elementos nuevos a guardar
        resize(other.sz);

        //Hacer que los espacios reservados esten en la posicion deseada
        for (int i = 0; i < other.sz; i++)
        {
            for(int i = sz; i >= pos; i--)
            {
                storage[i + 1] = storage[i];
            }

            sz++;
        }
        
        //Meter los elementos uno por uno dentro del vector en su posicion reservada
        for(int i = 0; i < other.sz; i++)
        {
            storage[pos + i] = other.storage[i];
        }
    }
    //FIN DE INSERT VECTOR
};

int main() {
	
    Vector<int> a;
    Vector<int> b;

    for (int i = 0; i < 10; i++)
    {
    	a.push_back(4);
	}
    a.print();
    
    for (int i = 0; i < 10; i++)
    {
    	b.push_front(8);
	}
    b.print();

    a.insertVector(b, 2);
    a.print();

    return 0;
}