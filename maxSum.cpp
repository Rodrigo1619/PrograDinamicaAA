#include <iostream>

using namespace std;

int maxSum(int* arr, int size){
    if(size==0)
        return 0;
    int maxEndingHere = arr[0];
    int maxSofar = arr[0];

    for(int i = 0; i<size; i++){
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSofar = max(maxSofar, maxEndingHere);
    }
    return maxSofar;
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = maxSum(arr, size);

    cout<<result;
}