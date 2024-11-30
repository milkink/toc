#include <iostream>
#include <stack>


using namespace std;


void wXwr(string w) {
    // Constructing the pushdown stack
    stack<char> pd_stack;


    int n = w.length();
    // Reading from Input Tape
    int i = 0;
    // Read from input tape and push the letters to stack until 'X' is found
    while (w[i] != 'X' && i < n) {
        pd_stack.push(w[i]);
        i++;
    }
    // "X" is read
    i++;
    // Read from input tape and pop from stack
    while (i < n) {
        // If stack becomes empty before all the letters are read then string is rejected
        if (pd_stack.empty()) {
            cout << "The string is rejected as it is not in the form w X w(reverse)" << endl;
            return;
        }
        char top = pd_stack.top();
        pd_stack.pop();
        // If the top letter of stack doesn't match with current letter of input tape then string is rejected
        if (w[i] != top){
            cout << "The string is rejected as it is not in the form w X w(reverse)" << endl;
            return;
        }
        i++;
    }
    // If stack is not empty after all the letters are read then string is rejected
    if (!pd_stack.empty()) {
            cout << "The string is rejected as it is not in the form w X w(reverse)" << endl;
            return;
        }
    // If stack is empty after all the letters are read and the letters before 'X' match with those after 'X' then string is rejected
    cout << "The string is accepted as it is in the form w X w(reverse)" << endl;
}


int main(){
    // Taking string input
    string w;
    cout << "Enter the string: ";
    cin >> w;
    
    wXwr(w);
}
