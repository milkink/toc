#include <iostream>
#include <stack>


using namespace std;


bool PDA(string w){
    // Checking for empty strings
    if (w.length() == 0){
        cout << "Empty string found" << endl;
        return false;
    }


    // Initialising PDA stack
    stack<char> pda_stack;


    int i = 0;
    // Read 1 for reading 'a'
    while (i < w.length() && w[i] == 'a'){ 
        pda_stack.push('a');
        i++;
    }


    // Read 2 for popping 'a' from stack for each 'b'
    while (i < w.length() && w[i] == 'b'){
        if (pda_stack.empty()){
            return false;
        }
        pda_stack.pop();
        i++;
    }


    // Checking if the stack is empty after reading or there is something still left to read
    if (!pda_stack.empty() || i < w.length()){
        return false;
    }
    return true;
}


int main(){
    string w;
    cout << "Enter the string: ";
    cin >> w;
    
    if (PDA(w)){
        cout << "String is accepted";
    }
    else{
        cout << "String is rejected";
    }
}
