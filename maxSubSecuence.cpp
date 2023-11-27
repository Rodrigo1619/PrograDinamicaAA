#include <iostream>

using namespace std;

// Función para calcular el máximo producto de subsecuencias
int maxProducto(int* secuencia, int tamano) {
    int maxActual = secuencia[0];  // Inicializar con el primer elemento
    int minActual = secuencia[0];
    int maxProductoHastaAhora = secuencia[0];

    for (int i = 1; i < tamano; i++) {
        int tempMax = maxActual;

        maxActual = (secuencia[i] > secuencia[i] * maxActual) ? secuencia[i] : secuencia[i] * maxActual;
        minActual = (secuencia[i] < secuencia[i] * tempMax) ? secuencia[i] : secuencia[i] * tempMax;

        maxProductoHastaAhora = (maxProductoHastaAhora > maxActual) ? maxProductoHastaAhora : maxActual;
    }

    return maxProductoHastaAhora;
}
int main() {
    const int MAX_TAMANO = 100;
    int secuencia[MAX_TAMANO];
    int num;
    int tamanoActual = 0;

    while (true) {
        cin >> num;

        if (num == -999999) {
            // Fin de la secuencia, calcular y mostrar el resultado
            int resultado = maxProducto(secuencia, tamanoActual);
            cout << resultado << endl;

            // Restablecer el tamaño de la secuencia
            tamanoActual = 0;

            // Verificar si es la marca de final global
            cin >> num;
            if (num == -999999) {
                break; // Salir del bucle principal
            } else {
                // Agregar el número a la siguiente secuencia
                secuencia[tamanoActual++] = num;
            }
        } else {
            // Agregar el número a la secuencia actual
            secuencia[tamanoActual++] = num;
        }
    }

    return 0;
}
