// Name: Ivan Tlaseca
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 9

#include <string>   
#include "bst.h"
#include <iostream>
#include <sstream>

using namespace std;

void printNode(string node);

binary_search_tree<string> words;

void removeDuplicates(binary_search_tree<string> words);

int main(){
    //FINISHED
    string userInput;
    
    cout<<"Original Text:"<<endl;
    getline(cin, userInput);
    istringstream ss(userInput);
    string x;
    while(getline(ss, x, ' ')){
        words.insert(x);
    }
    cout<<endl;
    cout<<"Processed Text:"<<endl;
    inorder(printNode, words.get_root()); 
    cout<<endl;
}

void printNode(string node){
    cout<< node << " ";
}

