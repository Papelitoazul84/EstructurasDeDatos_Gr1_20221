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

    //Inicio algoritmo de ordenamiento "merge sort"
    void push_BackN(Node* n)
    {
        n->setNext(nullptr);

        if(empty())
        {
            first = n;
        }
        else
        {
            last->setNext(n);
        }

        last = n;
        sz++;
    }

    void split(List<T>* A, List<T>* B)
    {
        Node* n = first;

        for (int i = 0; i < sz; i++)
        {
            if (i % 2 == 0)
            {
                A->push_backN(n);
                n = n->getNext();
            }
            else
            {
                B->push_backN(n);
                n = n->getNext();
            }
        }

        last = nullptr;
        first = nullptr;
        sz = 0;
    }

    void merge(List<T>* A, List<T>* B)
    {
        Node* n;

        Node* xa = A->first;
        Node* xb = B->first;

        while (xa != nullptr && xb != nullptr)
        {
            if (xa->getData() < xb->getData())
            {
                n = xa;
                xa = xa->getNext();
                push_back(n);
            }
            else
            {
                n = xb;
                xb = xb->getNext();
                push_back(n);
            }
        }

        while (xa != nullptr)
        {
            n = xa;
            xa = xa->getNext();
            push_BackN(n);
        }

        while (xb != nullptr)
        {
            n = xb;
            xb = xb->getNext();
            push_BackN(n);
        }
    }

    void mergeSort()
    {
        if (sz <= 1)
        {
            return;
        }
        else
        {
            List<T>* A;
            List<T>* B;

            split(&A, &B);

            A->mergeSort();
            B->mergeSort();

            merge(&A, &B);
        }
    }
    //Final de "merge sort"
};

int main()
{
    List<int>* c = new List<int>();

    c->push_back(9);
    c->push_back(8);
    c->push_back(7);
    c->push_back(6);
    c->push_back(5);
    c->push_back(4);

    c->print();

    c->mergeSort();
    c->print();

    return 0;
}