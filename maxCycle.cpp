#include <iostream>
#include <algorithm>

using namespace std;

int cycleLenght(int n){
    int count = 1;
    while (n != 1){
        if(n % 2 == 1) n = 3 * n + 1;
        else n = n/2;

        count++;
    }
    return count;
}

int maxCycleLenght(int i, int j){
    int maxCycle = 0;

    for(int k = min(i,j); k <= max(i,j); k++){
        maxCycle = max(maxCycle, cycleLenght(k));
    }
    return maxCycle;
}

int main(){
    int i,j;
    while (cin>>i>>j)
    {
        int maxCycle = maxCycleLenght(i,j);
        cout<<i << " " << j << " " << maxCycle<<endl;
    }
    return 0;
}