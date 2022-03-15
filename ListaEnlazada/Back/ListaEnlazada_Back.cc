/*
A este archivo se le agregaron todas las funciones necesarias para
que retorne el dato dentro del ultimo nodo
Contiene:
-Funcion "back"
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

    size_t size() 
    {
        size_t s = 0;

        Node* n = first;

        while(n != nullptr) {
            s++;
            n = n->getNext();
        }

        return s;
    }

    bool empty() 
    { 
        return first == nullptr;
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
    Funcion que revisa el ultimo nodo mediante el apuntador 'last' y
    devuelve los datos que estan ahi guardados
    */
    T back ()
    {
        return last->getData();
    }
};

int main()
{
   List<int>* c = new List<int>();

   for (int i = 1; i <=5; i++)
   {
        c->push_back(i);
   }

   cout << c->back() << endl;

    return 0;
}
