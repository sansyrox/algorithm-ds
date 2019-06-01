#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

char *mystrtok(char str[], char delim) {

    static char*input= NULL;
    if(str!=NULL) {
        input = str;
    }

    char * output = new char[strlen(input) + 1]; // =1 is for the NULL character
    // Return a word as a dynamically allocated word array from my function
    // Read the word from input and it will store in output and just return 

    for(int i=0; input[i]!='\0'; i++ ){
        if(input[i]!=delim) {
            // Do some work - copy the character in the output array
            output[i] = input[i];
        } else {
            // you are now at delim
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }

}
 
int main() {
    char str[] = "Hello, I am from, new delhi";

    char* ptr;

    ptr = mystrtok(str, " ");
    cout<<ptr<<endl;
    // while(ptr != NULL) {
    //     cout<<ptr<<endl;
    //     ptr = mystrtok(NULL, ", ");
    // }
    ptr = mystrtok(str, " ");
    cout<<ptr<<endl;

    string line = "GeeksForGeeks is a must try"; 
      
    // Vector of string to save tokens 
    vector <string> tokens; 
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    // Printing the token vector 
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens[i] << '\n'; 

    return 0;
}