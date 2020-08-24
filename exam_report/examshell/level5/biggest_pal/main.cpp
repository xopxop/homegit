#include <iostream>
#include <cstring>
 
using namespace std;
 
char* getSubstring(char c[], int starting, int ending){
 
    int length = ending - starting + 1;
    int temp = length;
     
    if(length > strlen(c)){
        return "null";
    }
 
    char* str = new char[length + 1];
 
    char *p1 = str;
    char *p2 = &c[starting];
 
    while(temp--){
        *(p1++) = *(p2++);
    }
 
    *p1 = '\0';
 
    return str;
 
}
 
int main(){
 
    char* str = "jklollolkidding";
    const int length = strlen(str);
 
    char* palindrome = new char[strlen(str)];
    int palindromeLength = 0;
 
    bool strTable[length][length];
 
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            strTable[i][j] = false;
        }
    }
 
    // if length == 1
    for(int i = 0; i < strlen(str); i++){
        strTable[i][i] = true;
    }
 
    //if length == 2
    for(int i = 0; i < strlen(str) - 2; i++){
 
        if(str[i] == str[i + 1]){
 
            strTable[i][i + 1] = true;
 
        }
 
    }
 
    //if length > 2
    int j;
    for(int k = 2; k < strlen(str); k++){
 
        for(int i = 0; i < strlen(str); i++){
 
            j = i + k;
 
            if(str[i] == str[j] && strTable[i + 1][j - 1] == true){
 
                if(strlen(getSubstring(str, i, j)) > palindromeLength){
 
                    palindrome = getSubstring(str, i, j);
                    palindromeLength = strlen(getSubstring(str, i, j));
 
                }
 
                strTable[i][j] = true;
 
            }
 
        }
 
    }
 
    cout << palindrome << endl;
 
return 0; }
