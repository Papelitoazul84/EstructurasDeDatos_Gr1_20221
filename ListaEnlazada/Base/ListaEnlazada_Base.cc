/*
Este es el codigo inicial para la lista, esta tal y como lo entrego
el profesor, las funciones aqui agregadas fueron las que el entro por
su cuenta en clase.
Contiene: 
-Constructor de la lista
-Constructor anidado de los nodos (Sin argumento)
-Constructor anidado de los nodos (Con argumento)
-Funcion 'setNext'
-Funcion 'pushBack'
*/

#include <iostream>

using namespace std;

template<typename T>
class List {
	private:
		/*
		Clase anidada dentro de la lista para creacion de nodos,privada
		a otras listas 
		*/
		class Node {
			private:
				/*
				Aqui se declaran los datos que se guardan dentro de cada nodo
				como es el dato que guarda y un puntero hacia el siguiente nodo
				*/
				T data;
				Node* next;
			public:
				//Constructor del nodo sin recibir argumentos
				Node() : data(), next(nullptr) {}
				
				//Constructor del nodo recibiendo el dato a guardar
				Node(T d) {
					data = d;
				}
				
				//Funcion que le indica a un nodo cual es su siguiente nodo
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

		/*
		Apuntadores base de la lista, sobre estos se trabajara la mayoria de
		funciones de la lista, apuntan al primer y ultimo nodo de la lista
		*/
		Node* first;
		Node* last;

		/*
   	 	Variable que emulara una especie de indexacion para posicionamiento
    	para recorrer los nodos con cierto orden numerico
    	*/
    	size_t sz;
	public:

	//Constructor de la lista que inicia sin ningun nodo en ella
	List () : first(nullptr), last(nullptr) {
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
};

int main()
{
	List<int>* c = new List<int>();
	
	return 0;
}
