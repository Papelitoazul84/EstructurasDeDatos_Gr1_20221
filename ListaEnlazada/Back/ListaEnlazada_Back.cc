/*
A este archivo se le agregaron todas las funciones necesarias para
que retorne el dato dentro del ultimo nodo
Contiene:
-Funcion "getNext"
-Funcion "getData"
-Destructor De Lista
-Funcion "size"
-Funcion "empty"
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

        //Funcion que retorna el siguiente nodo al que se esta ejecutando
        Node* getNext() 
        { 
            return next; 
        }

        //Funcion que retorna el dato guardado en el nodo
        T getData ()
        {
            return data;
        }

    };
    Node* first;
    Node* last;

    /*
    Variable que emulara una especie de indexacion para posicionamiento
    para recorrer los nodos con cierto orden numerico
    */
    size_t sz;


public:

    List() : first(nullptr), last(nullptr), sz(0)
    {

    }

    //Destructor de la lista, funcion contraria al constructor
    ~List()
    {
        Node* n = first;
        while(n != nullptr) {
            n = first;
            first = first->getNext();
            delete n;
        }
    }

    /*
    Funcion que de manera ciclica pasa por cada uno de los nodos para 
    al final de la ejecucion saber cuantos elementos existen.

    ATENCION: Ejecutar esta funcion puede conllevar a problemas de 
    rendimiento debido a su recorrido por toda la lista
    */
    size_t size() {
        //Variable de posicion
        size_t s = 0;

        //Nodo temporal para recorrer la lista
        Node* n = first;

        /*
        Recorrer la lista de modo que en cada salto de nodo se aumente
        el conteo, el ciclo se detendra cuando no detecte mas elementos
        en la lista
        */
        while(n != nullptr) {
            s++;
            n = n->getNext();
        }

        //Retorna el valor final del conteo
        return s;
    }

    /*
    Funcion que confirma si la lista esta vacia mediante el primer nodo
    al revisar si este esta vacio puede saber si el resto de la lista
    esta vacia
    */
    bool empty() 
    { 
        return first == nullptr;
    }

    /*
    Se actualizo el funcionamiento del push back a una version mas eficiente
    que realiza primero una comprobacion si esta tratando con una lista
    vacia o que ya tiene elementos
    */
    void push_back(T elem)
    {
        //Creacion de nodo temporal
        Node* n = new Node(elem);

        //Revisar si la lista esta vacia
        if (empty())
            first = n;
        else
            last->setNext(n);

        //Cambiar la propiedad del ultimo elemento
        last = n;

        //Actualizar el tamaño de la lista
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
