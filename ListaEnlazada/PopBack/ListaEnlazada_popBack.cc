/*
A este archivo se le agregaron todas las funciones necesarias para 
poder eliminar el ultimo elemento de una lista
Contiene:
-Funcion 'popBack'
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
    Esta funcion elimina el ultimo nodo de una lista enlazada
    Primero crea un nodo auxiliar que empieza en el elemento 'first'
    de la lista
    Luego de manera ciclica se recorre cada nodo hasta llegar hasta 
    el penultimo nodo
    Ya estando aqui hacemos que el nodo auxiliar se vuelva el ultimo,
    ya que al estar en la penultima posicion no esta contando con
    el final, de cierta manera se podria decir que lo esta excluyendo
    Se establece el nodo en la lista y luego se elimina este
    Finalmente se hace que el nodo siguiente a 'last' sea nulo y se
    le informa a la lista que disminuyo su cantidad de elementos
    */
    void pop_back()
    {
        //Nodo auxiliar
        Node* n = first;

        //Recorrido ciclico hasta el penultimo
        for(size_t i = 1; i < sz-1; i++)
        {
            n = n->getNext();
        }

        //Establecer penultimo como ultimo
        last = n;

        n = n->getNext();

        //Borrar nodo auxiliar
        delete n;

        //Hacer que el nodo siguiente al ultimo sea nulo
        last->setNext(nullptr);

        //Informar a la lista su disminucion
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
