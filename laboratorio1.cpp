#include <iostream>
#include <cstdlib> 
struct Nodo {
	int dato;
	Nodo* siguiente;
	Nodo(int val) : dato(val), siguiente(NULL) {}
};

class ListaMenu {
private:
	Nodo* principal;
	
public:
	ListaMenu() : principal(NULL) {}
	
	void insertar(int val) {
		Nodo* nuevoNodo = new Nodo(val);
		nuevoNodo->siguiente = principal;
		principal = nuevoNodo;
	}
	
	void agregarNumero() {
		int numero;
		std::cout << "Ingrese un número: ";
		std::cin >> numero;
		insertar(numero);
	}
	
	void mostrar() {
		Nodo* actual = principal;
		while (actual != NULL) {
			std::cout << actual->dato << " ";
			actual = actual->siguiente;
		}
		std::cout << std::endl;
	}
	
	void mostrarUltimo() {
		if (principal == NULL) {
			std::cout << "La lista está vacía." << std::endl;
			return;
		}
		
		Nodo* actual = principal;
		while (actual->siguiente != NULL) {
			actual = actual->siguiente;
		}
		////std::cout << "Último elemento: " << actual->dato << std::endl;
	}
	
	int calcularProducto() {
		int producto = 1;
		Nodo* actual = principal;
		while (actual != NULL) {
			producto *= actual->dato;
			actual = actual->siguiente;
		}
		return producto;
	}
	
	int calcularFactorial() {
		if (principal == NULL) {
			std::cout << "La lista está vacía." << std::endl;
			return 0;
		}
		
		int numeroMinimo = principal->dato;
		Nodo* actual = principal;
		while (actual != NULL) {
			if (actual->dato < numeroMinimo) {
				numeroMinimo = actual->dato;
			}
			actual = actual->siguiente;
		}
		
		int factorial = 1;
		for (int i = 1; i <= numeroMinimo; ++i) {
			factorial *= i;
		}
		return factorial;
	}
};

int main() {
	ListaMenu lista;
	
	int opcion;
	do {
		system("cls"); 
		
		std::cout << "\n--- Menú ---\n";
		std::cout << "1. Agregar número\n";
		std::cout << "2. Mostrar lista completa\n";
		std::cout << "3. Mostrar último elemento\n";
		std::cout << "4. Calcular producto de elementos\n";
		std::cout << "5. Calcular factorial del número menor\n";
		std::cout << "6. Salir\n";
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1:
			lista.agregarNumero();
			break;
		case 2:
			std::cout << "Lista completa: ";
			lista.mostrar();
			break;
		case 3:
			lista.mostrarUltimo();
			break;
		case 4: {
			int producto = lista.calcularProducto();
			std::cout << "Producto de los elementos: " << producto << std::endl;
			break;
		}
		case 5: {
			int factorial = lista.calcularFactorial();
			std::cout << "Factorial del número menor: " << factorial << std::endl;
			break;
		}
		case 6:
			std::cout << "Saliendo del programa." << std::endl;
			break;
		default:
			std::cout << "Opción no válida. Intente de nuevo." << std::endl;
		}
		std::cout << "Presione Enter para continuar...";
		std::cin.ignore();
		std::cin.get();
	} while (opcion != 6);
	
	return 0;
}


