// Lista enlazada en C
// cod. fuente de https://www.programiz.com/dsa/linked-list-operations
#include <stdio.h>
#include <stdlib.h>

// Crear un nodo node
struct Nodo {
	int data;
	// puedo agregar mas elementos a la estructura
	struct Nodo* next;
};

// Insert at the beginning
void agregarAlPrincipio(struct Nodo** head_ref, int new_data) {
	// Allocate memory to a node
	struct Nodo* new_node = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	// insert the data
	new_node->data = new_data;
	
	new_node->next = (*head_ref);
	
	// Move head to new node
	(*head_ref) = new_node;
}

// Insert a node after a node
void agregarLuegoDe(struct Nodo* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("El nodo anterior no puede ser NULL");
		return;
	}
	
	struct Nodo* new_node = (struct Nodo*)malloc(sizeof(struct Nodo));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Insert the the end
void agregarAlFinal(struct Nodo** head_ref, int new_data) {
	struct Nodo* new_node = (struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo* last = *head_ref; /* used in step 5*/
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	
	while (last->next != NULL) last = last->next;
	
	last->next = new_node;
	return;
}

// Delete a node
void eliminarNodo(struct Nodo** head_ref, int key) {
	struct Nodo *temp = *head_ref, *prev;
	
	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next;
		free(temp);
		return;
	}
	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}
	
	// If the key is not present
	if (temp == NULL) return;
	
	// Remove the node
	prev->next = temp->next;
	
	free(temp);
}

// Buscar un nodo 
int searchNode(struct Nodo** head_ref, int key) {
	struct Nodo* actual = *head_ref;
	
	while (actual != NULL) {
		if (actual->data == key) return 1;
		actual = actual->next;
	}
	return 0;
}

// ordenar lista enlazada
void sortLinkedList(struct Nodo** head_ref) {
	struct Nodo *actual = *head_ref, *index = NULL;
	int temp;
	
	if (head_ref == NULL) {
		return;
	} else {
		while (actual != NULL){ 
			// index apunta al nodo siguiente a actual
			index = actual->next;
			
			while (index != NULL) {
				if (actual->data > index->data) {
					temp = actual->data;
					actual->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			actual = actual->next;
		}
	}
}

// mostramos la lista
void printList(struct Nodo* node) {
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
}

// Programa principal
int main() {
	struct Nodo* INICIO = NULL;
	
	agregarAlFinal(&INICIO, 1);
	agregarAlPrincipio(&INICIO, 2);
	agregarAlPrincipio(&INICIO, 3);
	agregarAlFinal(&INICIO, 4);
	agregarLuegoDe(INICIO->next, 5);
	
	printf("Lista Enlazada Creada: ");
	printList(INICIO);
	
	printf("\nLuego de eliminar el nodo con dato 3: ");
	eliminarNodo(&INICIO, 3);
	printList(INICIO);
	
	int item_to_find = 3;
	if (searchNode(&INICIO, item_to_find)) {
		printf("\nse encontro %d", item_to_find);
	} else {
		printf("\n%d no se encuentra en la lista", item_to_find);
	}
	
	sortLinkedList(&INICIO);
	printf("\nSorted List: ");
	printList(INICIO);
}
