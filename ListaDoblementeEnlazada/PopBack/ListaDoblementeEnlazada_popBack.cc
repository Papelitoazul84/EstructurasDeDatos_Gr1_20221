#include <iostream>

using namespace std;

template<typename T>
class List {
private:
    class Node {
    private:
        T data;
        Node* next;
        Node* prev;
    public:

        Node() : data(), next(nullptr), prev(nullptr) {}

        Node(T d) : data(d), next(nullptr), prev(nullptr) {}

        void setNext(Node* n)
        {
            next = n;
        }

        void setPrev(Node* n)
        {
        	prev = n;
		}

        Node* getNext()
        {
            return next;
        }

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

    /*
    Esta es una de las funciones que mas cambian con respecto a la anterior, se aprovecha de la utilidad de esta lista y es que se puede 
    retroceder entre nodos
    Primero se ubica en el ultimo nodo y pasa para el inmediatamente anterior a este
    Luego usando la funcion de obtener el siguiente nodo se borra el nodo siguiente al nuevo "last"
    Finalmente se le dice que su puntero "next" apunta a nullptr y se disminuye el tamaño de la lista
    */
    void pop_back()
    {
        last = last->getPrev();

        delete last->getNext();

        last->setNext(nullptr);

        sz--;
    }
};

int main()
{
    List<int>* c = new List<int>();

	c->print();

    return 0;
}
