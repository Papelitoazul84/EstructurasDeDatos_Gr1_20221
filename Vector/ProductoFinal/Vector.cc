#include <iostream>

using namespace std;

template<typename T>
class Vector {
private:
	
    size_t sz;
    size_t capacity;
    T* storage;
    
public:
	
    Vector() {
        sz = 0;
        capacity = 7;
        storage = new T[capacity];
    }
    
private:
	
    void resize() {
        T* ns = new T[capacity * 2];
        for(size_t i = 0; i < sz; i++) {
            ns[i] = storage[i];
        }
        delete [] storage;
        storage = ns;
        capacity = capacity * 2;
    }

    void resize(int mv)
    {
        T* ns = new T[capacity + mv];
        for(size_t i = 0; i < sz; i++) {
            ns[i] = storage[i];
        }
        delete [] storage;
        storage = ns;
        capacity = capacity + mv;
    }

public:

    void push_back(T elem) {
        if (sz == capacity) {
            resize();
        }
        storage[sz] = elem;
        sz++;
    }

    size_t size() {
        return sz;
    }
    
    void print() {
        for (size_t i = 0; i < size(); i++)
            cout << " " << storage[i];
        cout << endl;
    }
    
    void push_front(T elem)
    {
    	if (sz == capacity)
    	{
    		resize();
		}
		
		moveElement();
		
		storage[0] = elem;
		
		sz++;
	}
	
	void moveElement()
	{
		for (int i = sz; i > 0; i--)
		{
			storage[i] = storage[i - 1];
		}
	}

    void pop_back()
    {
        sz--;
    }

    void pop_front()
    {
        for (int i = 1; i < sz; i++)
        {
            storage[i - 1] = storage[i];
        }

        sz--;
    }
    
    void insert(T elem, size_t pos)
    {
        if (sz == capacity) {
            resize();
        }

        for(int i = sz; i > pos ;i--)
        {
            storage[i + 1] = storage[i];
        }

        storage[pos] = elem;

        sz++;
    }

    void remove(size_t pos)
    {
        for(int i = pos; i < sz; i++)
        {
            storage[i] = storage[i + 1];
        }

        sz--;
    }

    void insertVector(Vector<T> other, size_t pos)
    {
        resize(other.sz);


        for (int i = 0; i < other.sz; i++)
        {
            for(int i = sz; i >= pos; i--)
            {
                storage[i + 1] = storage[i];
            }

            sz++;
        }
        
        for(int i = 0; i < other.sz; i++)
        {
            storage[pos + i] = other.storage[i];
        }
    }
};

int main() {
	
    Vector<int> a;
    Vector<int> b;

    for (int i = 0; i < 10; i++)
    {
    	a.push_back(4);
	}
    a.print();
    
    for (int i = 0; i < 10; i++)
    {
    	b.push_front(8);
	}
    b.print();

    a.insertVector(b, 2);
    a.print();

    return 0;
}