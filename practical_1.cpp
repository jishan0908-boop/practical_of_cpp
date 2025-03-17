#include<iostream>
using namespace std;
#include <cmath>


/*
 s = 1- 1/(2^2) + 1/(3^3)......

*/
int main(int argc ,  char* argv[]){
    int number;
    if (argc < 2) {
        cout << "Enter the number: ";
        cin >> number; 
    } else {
        number = stoi(argv[1]); 
    }
    float sum_of_series = 1;
    if (number<= 0 || number==1){
        cout<<"Sum is : "<< 1 <<endl;
        return 0;
    }
    
    for(int i = 2 ; i<=number ; i++){
        if(i%2==0){
            sum_of_series -= 1/pow(i, i);
        }
        else{
            sum_of_series += 1/pow(i,i);
        }
    }

    cout<< "Sum of the series is : "<<sum_of_series<<endl; 

    return 0 ;
}