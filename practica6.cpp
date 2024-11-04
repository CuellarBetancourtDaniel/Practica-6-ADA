#include <iostream>
#include <algorithm>
using namespace std;

int areaMaxima(int altura[], int n) {
	int maximo = 0; // Almacenamos el área máxima encontrada.
	int inicio = 0; // Índice inicial de nuestro arreglo.
	int fin = n - 1; // Índice final de nuestro arreglo.
	
	// Bucle que se ejecuta mientras haya una distancia entre los índices inicio y fin.
	while (fin - inicio > 0) {
		// `alturaMinima` es la altura mínima entre las líneas en los índices `inicio` y `fin`.
		int alturaMinima = min(altura[fin], altura[inicio]);
		
		// `areaActual` calcula el área entre `inicio` y `fin`.
		int areaActual = (fin - inicio) * alturaMinima;
		
		// Se incrementa `inicio` si la línea en `inicio` es menor, o se decrementa `fin` si
		// la línea en `fin` es menor o igual.
		if (altura[fin] > altura[inicio]) {
			inicio++; // Mover el índice inicial hacia la derecha.
		} else {
			fin--; // Mover el índice final hacia la izquierda.
		}
		
		// Actualiza `maximo` si `areaActual` es mayor que el área máxima encontrada hasta el momento.
		maximo = max(maximo, areaActual);
	}
	return maximo; // Retorna el área máxima encontrada.
}

int main() {
	// Ejemplo de entrada: arreglo de alturas
	int altura[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(altura) / sizeof(altura[0]); // Calcula la cantidad de elementos
	
	// Calcula el área máxima
	int resultado = areaMaxima(altura, n);
	
	// Muestra el resultado
	cout << "La máxima cantidad de agua que se puede contener es: " << resultado << endl;
	
	return 0;
}
