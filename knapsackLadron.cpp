#include <iostream>
#include <algorithm>

using namespace std;
int maximizarRobo(int capacidadMochila, int* pesos, int* valores, int cantidadObjetos){
    int dp[cantidadObjetos+1][capacidadMochila+1];

    for(int i = 0; i<=cantidadObjetos; i++){
        for(int w = 0; w<=capacidadMochila; w++){
            if(i== 0 || w == 0)
                dp[i][w] = 0;
            else if(pesos[i-1] <= w)
                dp[i][w] = max(valores[i-1] + dp[i-1][w - pesos[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[cantidadObjetos][capacidadMochila];

}

int main(){
    int capacidadMochila = 10;
    int pesos[] = {2, 3, 4, 5};
    int valores[] = {3, 4, 5, 6};
    int cantidadObjetos = sizeof(pesos)/sizeof(pesos[0]);

    int result = maximizarRobo(capacidadMochila, pesos, valores, cantidadObjetos);

    cout<<result;
}
