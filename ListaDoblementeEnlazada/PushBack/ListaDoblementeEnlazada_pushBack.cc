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

    /*
    Lo unico que cambia en esta implementacion es que al nuevo nodo insertado se le tiene que indicar la direccion del nodo anterior a este,
    en esta implementacion se hace usando a "last" antes de hacer la reubicacion de este 
    */
    void push_back(T elem)
    {
        Node* n = new Node(elem);

        if (empty())
        {
        	first = n;
		}
        else
        {
        	last->setNext(n);
        	n->setPrev(last);
		}

        last = n;

        sz++;
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
};

int main()
{
    List<int>* c = new List<int>();

    for (int i = 1; i <=5; i++)
    {
        c->push_back(i);
    }
    c->print();

    return 0;
}
