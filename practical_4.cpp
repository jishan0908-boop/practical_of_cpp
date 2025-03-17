#include<iostream>
using namespace std;
/*
Menu driven 
show address of eacg chr in string done
concatenae two string
compare two string
calaculate length of string using pointer 
covert lower case to upper case 
reverse a string
*/

int show_address(char str[]) {

    cout << "String: " << str << endl;

   
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << "Address of " << str[i] << ": " << static_cast<const void*>(&str[i]) << endl;
    }
    return 0;
}

void concat(char str[]) {
    int MAX;
    cout << "Enter the length of the string you want for the second string: ";
    cin >> MAX;
    
    char str2[MAX];
    cin.ignore(); 
    cout << "Enter the second string: ";
    cin.getline(str2, MAX);


    int n = 0;
    while (str[n] != '\0') {
        n++;  
    }

    int n2 = n + MAX - 1;  

    char str3[n2 + 1];  
    for (int i = 0; i < n; i++) {
        str3[i] = str[i];
    }

    for (int i = 0; i < MAX - 1; i++) {  
        str3[n + i] = str2[i];
    }
    str3[n2] = '\0';
    cout << "Concatenated string: " << str3 << endl;
}

void convert(char str[]){
    int n = 0;
    while (str[n] != '\0') {
        n++;  
    }
    char str2[n];
    for (int i = 0 ; i<n ; ++i){
        if(str[i]>='A' || str[i<='Z']){
            if(str[i]>='a' || str[i]<='z'){
                str2[i] = (char)(str[i] - 32);
            }
            else{
                str2[i] = str[i];
            }
        }
    }
    str2[n] = '\0';
    cout<<"STRING is :  "<<str2<<endl;
    
}

bool compareStrings(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return false;  
        }
        str1++;
        str2++;
    }
  
    return *str1 == *str2;
}

int stringLength(const char* str) {
    const char* ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    return length;
}
void reverse(char str[]){
    int n = 0;
    while (str[n] != '\0') {
        n++;  
    }
    char str2[n + 1];
    for(int i = n-1 ; i >= 0 ; --i){
        str2[n-i-1] = str[i];
    }
    str2[n] = '\0';
    cout<<"Reverse string "<<str2<<endl; 

}
int main() {
    int MAX;
    cout << "Enter the length of the string you want: ";
    cin >> MAX;
    char str[MAX];
    cin.ignore();
    cout << "Enter the string: ";
    cin.getline(str, MAX);
    //show_address(str);
    //concat(str);
    //convert(str);
    //reverse(str);

    return 0;
}