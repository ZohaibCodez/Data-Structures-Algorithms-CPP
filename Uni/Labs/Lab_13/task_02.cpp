#include<iostream>
#include<array>

using namespace std;

int main(){
    array<int,12> arr1 = {4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6 };
    array<int,12> arr2 = {1, 5, 2, 5, 4, 1, 2, 3, 4, 3, 5};

    array<int,12> dup = {};
    for(int i = 0; i < 12;i++){
        dup[i] = arr1[i];
    }
    
    for(int i:dup){
        cout << dup[i] << " ";
    }

    for(int i = 0;i < 12; i++){
        if(arr1[i] == dup[i]){
            cout << dup[i];
        }
    }
}