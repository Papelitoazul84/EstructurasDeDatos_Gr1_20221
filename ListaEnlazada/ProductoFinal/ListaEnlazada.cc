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
            s++;
            n = n->getNext();
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

    void push_back(List<T>* other)
    {
        List<T>* tmp;
        Node* n = other->first;

        for(size_t i = 0; i < other->sz; i++)
        {
            n->getData();

            tmp.push_back(n->getData);

            n = n->getNext;
        }

        last->setNext(tmp.first);
        last = tmp.last;

        last->setNext(nullptr);

        sz = sz + tmp.sz;
    }

    void push_front(T elem)
    {
        Node* n = new Node(elem);

        if(empty())
        {
            first = n;
            last = n;
        }
        else
        {
            n->setNext(first);
            first = n;
        }

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

    void pop_back()
    {
        Node* n = first;

        for(size_t i = 1; i < sz-1; i++)
        {
            n = n->getNext();
        }

        last = n;

        n = n->getNext();

        delete n;

        last->setNext(nullptr);

        sz--;
    }

    void pop_front()
    {
        Node* n = first;

        first = n->getNext();

        delete n;

        sz--;
    }

    T at(size_t p)
    {
        Node* n = first;

        for(size_t i = 1; i < p; i++)
        {
            n = n->getNext();
        }

        return n->getData();
    }

    void insert(size_t p, size_t elem)
    {
        Node* n =  new Node(elem);
        Node* r = first;

        for(size_t i = 1; i < p-1; i++)
        {
            r = r->getNext();
            cout << "Indice: " << i << endl;
        }

        cout << r->getData() << endl;

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

    c->print();

    cout << endl << c->back();

    return 0;
}
