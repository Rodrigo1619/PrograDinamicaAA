#include <iostream>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila (0/1 knapsack)
int knapsack(int capacidad, int pesos[], int valores[], int n) {
    int dp[n + 1][capacidad + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacidad; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (pesos[i - 1] <= w) {
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    // Ejemplo de uso
    int capacidad = 10;
    int pesos[] = {2, 3, 4, 5};
    int valores[] = {3, 4, 5, 6};
    int n = sizeof(pesos) / sizeof(pesos[0]);

    int resultado = knapsack(capacidad, pesos, valores, n);

    cout << "El valor máximo que se puede obtener es: " << resultado << endl;

    return 0;
}
