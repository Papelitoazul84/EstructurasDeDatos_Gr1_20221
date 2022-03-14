/*
A este archivo se le agregaron todas las funciones necesarias para
poder meter un vector dentro de otro en una posicion especifica
que es pasada por parametro
Contiene:
-Funcion "insertVector"
-Funcion "resize" que recibe un parametro tipo 'int'
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

    /*
    La diferencia de este 'resize' es que este recibe un parametro
    y a la hora de determinar cuanto espacio mas reservarle al vector
    sabe especificamente cuanto darle de manera que no se incurre
    en un desperdicio de espacio
    */
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
    Funcion que inserta un vector completo dentro de otro vector en 
    una posicion especifica, esto lo hace con 2 parametros uno seria
    de tipo 'Vector<T>' llamado 'other' el cual simboliza el vector
    que entra, luego esta el dato de tipo 'size_t' llamado 'pos'
    que entrega la posicion desde la cual empezara a entrar el vector

    Primero que nada para esta funcion es necesario un nuevo metodo 
    de 'resize' el cual toma un parametro, la diferencia de este es
    que sabe exactamente cuantos elementos va a aumentar el vector,
    por lo que es un poco mas eficiente en cuanto a desperdicio de 
    memoria

    Ya que los espacios dados por 'resize' se colocan al final del
    vector, cada elemento desde la posicion deseada para meter el 
    nuevo vector debe ser movido a la derecha hasta haber ocupado 
    totalmente los nuevos espacios; Cada elemento se mueve la 
    cantidad de veces que sea necesaria para que quede bien
    posicionado
        El primer forloop determina cual es el dato a mover y el
        segundo determina cuantas veces se mueve el dato
        Aqui se aprovecha para hacerle saber al vector que su tamaño
        esta aumentando
    
    Despues de tener ya los espacios reservados para poder meter los
    datos se mete cada dato uno por uno en la posicion que se le
    reservo
    */
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
    //FIN CAMBIOS
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
    	b.push_back(8);
	}
    b.print();

    a.insertVector(b, 2);
    a.print();

    return 0;
}