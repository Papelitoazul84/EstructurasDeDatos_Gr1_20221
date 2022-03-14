/*
A este archivo se le agregaron todas las funciones necesarias para 
retornar el valor de un nodo que esta en una posicion especifca
Contiene:
-Funcion 'at'
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
            last->setNext(n);//last su nuevo siguiente es n
        last = n;//n usted es el nuevo last

        sz++;
    }

    /*
    Funcion que retorna los datos de un vector en especifico, el 
    vector es seleccionado mediante una posicion, se toma un parametro
    de tipo 'size_t' llamado 'p' el cual es la posicion
    Primero se crea un nodo que empieza en 'first'
    Se recorre la lista hasta la posicion dada y se ubica ahi al
    nodo auxiliar
    Se toma el dato del nodo auxiliar
    */
    T at(size_t p)
    {
        Node* n = first;

        for(size_t i = 1; i < p; i++)
        {
            n = n->getNext();
        }

        return n->getData();
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
