#include<iostream>
using namespace std;
/*
removing duplicates from the an array
*/

int main(){
    int arr[10] = {1,2,2,3,4,5,6,6,7,8};
    int new_arr[10];
    int j = 0 ;
    new_arr[j]= arr[0];
    j++;
    for (int i = 1 ; i<10 ; i++){
        if ( arr[i] != arr[i-1]){
            new_arr[j]= arr[i];
            j ++; 
        }
    }
    for(int k = 0 ; k < j; k++){ 
        cout<< new_arr[k] << " ";}

    return 0 ;
}