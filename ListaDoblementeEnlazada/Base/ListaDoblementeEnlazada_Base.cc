/*
Este archivo contiene los cambios mas basicos sobre el archivo de "lista enlazada" para crear una lista doblemente enlazada,
aqui se especifica los cambios sobre el constructor y las funciones base de trabajo con nodos
*/
#include <iostream>

using namespace std;

template<typename T>
class List {
private:
    class Node {
    private:
        T data;
        Node* next;

        //Agregado un nuevo dato dentro del nodo
        Node* prev;
    public:
        //Se cambia la inicializacion de datos del constructor del nodo
        Node() : data(), next(nullptr), prev(nullptr) {}

        Node(T d) : data(d), next(nullptr), prev(nullptr) {}

        void setNext(Node* n)
        {
            next = n;
        }

        //Funcion para establecer el nodo anterior sobre el que se ejecute esta funcion
        void setPrev(Node* n)
        {
        	prev = n;
		}

        Node* getNext()
        {
            return next;
        }

        //Funcion para obtener el nodo anterior sobre el que se este ejecutando esta funcion
        Node* getPrev()
        {
        	return prev;
		}

        T getData ()
        {
            return data;
        }

    };
    Node* first;
    Node* last;
    size_t sz;

public:
    List() : first(nullptr), last(nullptr), sz(0) {}

    ~List()
    {
        Node* n = first;
        while(n != nullptr) {
            n = first;
            first = first->getNext();
            delete n;
        }
    }

    bool empty()
    {
        return first == nullptr;
    }

    size_t size() {
        size_t s = 0;
        Node* n = first;
        while(n != nullptr) {
            s++;
            n = n->getNext();
        }
        return s;
    }

    void print()
    {
        Node* n = first;

        cout << endl;

        for(size_t i = 0; i < sz; i++)
        {
            cout << n->getData();
            n = n->getNext();
        }
    }

    T front()
    {
        return first->getData();
    }

    T back ()
    {
        return last->getData();
    }
};

int main()
{
    List<int>* c = new List<int>();

    return 0;
}
