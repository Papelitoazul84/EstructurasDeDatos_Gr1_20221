/*
A este archivo se le agregaron todas las funciones necesarias para poder
meter un nuevo nodo al inicio de la lista, cambiando el indicador de
"first" y cambiando el puntero del nuevo nodo
Contiene:
-Funcion "pushFront"
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
    Coloca un nuevo elemento nodo al inicio de la lista
    Primero crea un nuevo nodo el cual usa el constructor con parametros
    luego confirma si la lista esta vacia, si es asi hace que el
    nodo ingresado sea tanto el 'first' como el 'last' de la lista
    Si la lista no esta vacia cambia el puntero del nuevo nodo hacia
    el primer elemento de la lista y cambia la propiedad de first
    Finalmente actualiza la cantidad de datos que contiene la lista
    */
    void push_front(T elem)
    {
        //Crear nodo
        Node* n = new Node(elem);

        //Comprobar si la lista esta vacia
        if(empty())
        {
            //Actualizar valores lista
            first = n;
            last = n;
        }
        else
        {
            //Actualizar apuntador del nodo y valores de la lista
            n->setNext(first);
            first = n;
        }

        //Actualizar tamaño de la lista
        sz++;
    }
};

int main()
{
   List<int>* c = new List<int>();

   for (int i = 1; i <=5; i++)
   {
        c->push_front(i);
   }

    return 0;
}
