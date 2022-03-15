/*
A este archivo se le agregaron todas las funciones necesarias
para añadir un nuevo nodo en cualquier posicion de la lista
Contiene:

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
    Para realizar esta accion se usan 2 nodos auxiliares
    primero un nodo creado con el elemento a agregar, luego
    otro nodo que empieza en el 'first' de la lista.

    Lo primero es hacer que el nodo ubicado al inicio la recorra
    hasta llegar al anterior del punto deseado para ubicar el nodo,
    se hace que sea el anterior para poder usar la funcon getNext()

    Ahora hacemos que el nodo con el 'data' se ubique en el nodo
    siguiente al recorredor de lista, es decir, en la posicion 
    solicitada.

    Finalmente se hace que el siguiente nodo del recorredor sea
    el que tenia la 'data' y se aumenta el tamaño de la lista
    */
    void insert(size_t p, size_t elem)
    {
        Node* n =  new Node(elem);
        Node* r = first;

        for(size_t i = 1; i < p-1; i++)
        {
            r = r->getNext();
        }

        n->setNext(r->getNext());
        r->setNext(n);

        sz++;
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
