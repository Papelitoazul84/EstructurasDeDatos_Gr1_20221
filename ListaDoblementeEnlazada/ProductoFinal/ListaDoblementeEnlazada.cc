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

    void push_front(T elem)
    {
        Node* n = new Node(elem);

        if(empty())
        {
            last = n;
        }
        else
        {
            n->setNext(first);
            first->setPrev(n);
        }

        first = n;

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
        last = last->getPrev();

        delete last->getNext();

        last->setNext(nullptr);

        sz--;
    }

    void pop_front()
    {
        first = first->getNext();

        delete first->getPrev();

        first->setPrev(nullptr);

        sz--;
    }

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

    void insert(size_t p, size_t elem)
    {
        Node* n = new Node(elem);
        Node* r = first;

        for(size_t i = 1; i < p-1; i++)
        {
            r = r->getNext();
        }

        n->setNext(r->getNext());
        n->setPrev(r);
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

	c->insert(5, 9);
	c->print();

    return 0;
}
