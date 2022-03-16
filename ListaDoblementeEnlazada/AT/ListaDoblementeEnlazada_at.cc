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
    Esta es otra funcion que cambia mucho, su funcionamiento es muy similar pero al usar dobles enlaces se puede usar la "organizacion 
    binaria", lo que hace esto es dividir la lista por la mitad dependiendo a que extremo de la lista este mas cerca el dato buscado
    Mediante condicionales comprueba si el nodo buscado esta mas cerca del final o del inicio de la lista
    Dependiendo de esto recorrera la lista hacia adelante o hacia atras

    Este algoritmo tiene una efectividad muy alta ya que en el peor de los casos recorrera solo la mitad de la lista
    */
    T at (size_t p)
    {
        Node* n;

        if (p <= sz/2)
        {
            n = first;

            for (int i = 1; i < p; i++)
            {
                n = n->getNext();
            }
        }
        else if (p >= sz/2)
        {
            n = last;

            for (int i = sz; i > p; i--)
            {
                n = n->getPrev();
            }
        }

        return n->getData();
    }

};

int main()
{
    List<int>* c = new List<int>();

	c->print();

    return 0;
}
