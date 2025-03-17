#include<iostream>
using namespace std;
int find_length(int arr[]){
    int count = 0;
    while(arr[count] != '\0'){
        count++;
    }
    return count;
}

void merge_arr(int arr1[], int arr2[]){
    int n1 = find_length(arr1);
    int n2 = find_length(arr2);
    int arr3[n1 + n2 + 1];
    for(int i = 0 ; i< n1; i++){
        for(int j = 0 ; j<i; j++){
            if(arr1[j] > arr1[j+1]){
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp; 
            }
        }
    }
    for(int i = 0 ; i< n2; i++){
        for(int j = 0 ; j<i; j++){
            if(arr2[j] > arr2[j+1]){
                int temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp; 
            }
        }
    }
    for(int j = 0 ; j<n1 ; j++){
        arr3[j] = arr1[j];
    }
    for(int k = 0 ; k<n2 ; k++){
        arr3[n1 + k ] = arr2[k]; 
    }
    
    for(int i = 0 ; i< (n1+ n2); i++){
        for(int j = 0 ; j<i; j++){
            if(arr3[j] > arr3[j+1]){
                int temp = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = temp; 
            }
        }
    }
    arr3[n1+n2] = '\0';
    for(int k = 0 ; k <(n1+n2) ; k++){
        cout<<arr3[k]<<" ";
    }


}
int main (){

    int arr1[5] = {1,3,2,4,6};
    int arr2[5] = {5,7,3,10,8};
    merge_arr(arr1 , arr2);
    return 0;
}