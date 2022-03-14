/*
A este archivo se le agregaron todas las funciones necesarias para
retornar todos los datos que fueron guardados dentro de la lista
Contiene:
-Funcion 'print'
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
    Funcion que imprime todos los datos de los nodos de una lista
    Primero crea un nodo en la posicion 'first' del vector
    Luego recorre ciclicamente toda la lista en cada nodo para
    e imprime sus datos antes de continuar al siguiente nodo
    */
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
