#include <iostream>
#include <algorithm>
using namespace std;

int areaMaxima(int altura[], int n) {
	int maximo = 0; // Almacenamos el �rea m�xima encontrada.
	int inicio = 0; // �ndice inicial de nuestro arreglo.
	int fin = n - 1; // �ndice final de nuestro arreglo.
	
	// Bucle que se ejecuta mientras haya una distancia entre los �ndices inicio y fin.
	while (fin - inicio > 0) {
		// `alturaMinima` es la altura m�nima entre las l�neas en los �ndices `inicio` y `fin`.
		int alturaMinima = min(altura[fin], altura[inicio]);
		
		// `areaActual` calcula el �rea entre `inicio` y `fin`.
		int areaActual = (fin - inicio) * alturaMinima;
		
		// Se incrementa `inicio` si la l�nea en `inicio` es menor, o se decrementa `fin` si
		// la l�nea en `fin` es menor o igual.
		if (altura[fin] > altura[inicio]) {
			inicio++; // Mover el �ndice inicial hacia la derecha.
		} else {
			fin--; // Mover el �ndice final hacia la izquierda.
		}
		
		// Actualiza `maximo` si `areaActual` es mayor que el �rea m�xima encontrada hasta el momento.
		maximo = max(maximo, areaActual);
	}
	return maximo; // Retorna el �rea m�xima encontrada.
}

int main() {
	// Ejemplo de entrada: arreglo de alturas
	int altura[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(altura) / sizeof(altura[0]); // Calcula la cantidad de elementos
	
	// Calcula el �rea m�xima
	int resultado = areaMaxima(altura, n);
	
	// Muestra el resultado
	cout << "La m�xima cantidad de agua que se puede contener es: " << resultado << endl;
	
	return 0;
}
