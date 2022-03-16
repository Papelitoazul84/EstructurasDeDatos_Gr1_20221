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
    Esta funcion tambien aprovecha bastante bien el hecho de ser doblemente enlazada, ya que simplemente con indicarle cual es el anterior
    nodo a la funcion de "delete" esta lo borrara sin mayor problema 
    Primero le decimos al nodo que se adelante una posicion 
    Luego le decimos que borre el nodo inmediatamente anterior 
    Se le indica que el anterior ahora es nullptr y se reduce el tamaño del nodo
    */
    void pop_front()
    {
        first = first->getNext();

        delete first->getPrev();

        first->setPrev(nullptr);

        sz--;
    }
};

int main()
{
    List<int>* c = new List<int>();

	c->print();

    return 0;
}
