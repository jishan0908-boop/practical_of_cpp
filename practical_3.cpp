#include<iostream>
using namespace std;

int main(int argc , char* argv[]){
    string text;
    if (argc >1){
        text = argv[1];
    }

    int freq[26] = {0};

    for(char c : text){
        if( c >= 'A' && c <= 'z'){
        if(c >='A' && c<='Z'){
            c = c + 32;
        }
        int index = c - 'a';
        freq[index]++;
        }
    }

    cout<<"Character  |  Frequency"<<endl;
    cout<<"======================="<<endl;
    
    for(int i = 0 ; i < 26 ; i++){
        if(freq[i] > 0){
        cout<<char('a' + i)<<"          |  "<<freq[i]<<endl;        
    }
    }
    return 0;

}