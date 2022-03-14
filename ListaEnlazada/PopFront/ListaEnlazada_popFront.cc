/*
A este archivo se le agregaron todas las funciones necesarias
para poder eliminar el primer elemento de una lista enlazada
Contiene: 
-Funcion "popFront"
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
    public:

        Node() : data(), next(nullptr) {}

        Node(T d) : data(d), next(nullptr) {}

        void setNext(Node* n) 
        { 
            next = n; 
        }

        Node* getNext() 
        { 
            return next; 
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
            s++;//cuento un elemento mas
            n = n->getNext();//n pasa a ser el siguiente
        }
        return s;
    }

    void push_back(T elem)
    {
        Node* n = new Node(elem);
        if (empty())
            first = n;
        else
            last->setNext(n);
        last = n;

        sz++;
    }

    /*
    Funcion que elimina el primer elemento de una lista
    Primero crea un nodo que arranca desde la primera posicion de la 
    lista
    Se hace que el nuevo 'first' se el nodo a la derecha del nodo
    auxiliar, se elimina el nodo en el que esta parado el nodo
    auxiliar
    Se le informa a la lista la disminucion de elementos
    */
    void pop_front()
    {
        Node* n = first;

        first = n->getNext();

        delete n;

        sz--;
    }
    
};

int main()
{
   List<int>* c = new List<int>();

   for (int i = 1; i <=5; i++)
   {
        c->push_back(i);
   }

    return 0;
}
