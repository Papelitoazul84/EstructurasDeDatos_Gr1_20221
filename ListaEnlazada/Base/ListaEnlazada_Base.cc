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
		};

		/*
		Apuntadores base de la lista, sobre estos se trabajara la mayoria de
		funciones de la lista, apuntan al primer y ultimo nodo de la lista
		*/
		Node* first;
		Node* last;
	public:

	//Constructor de la lista que inicia sin ningun nodo en ella
	List () : first(nullptr), last(nullptr) {
	}
	
	/*
	Funcion que agrega un nodo al final y configura el nuevo nodo como 'last'
	*/
	void push_back(T elem)
	{
		Node* x = new Node(elem);
		last->setNext(x);
		last = x;
	} 
};

int main()
{
	List<char> c;
	
	return 0;
}
