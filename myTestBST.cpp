// Name: Ivan Tlaseca
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 9

//Prompt: Build a BST with given words. Insert them in an order that gives smallest tree depth possible. Display the tree shape. Then, remove the root, print out the tree depth; and re-display the tree in a tree-shape.
//Inputs: string array, first and last index of the array
//Output: Tree depth (using is_balanced() function) & Tree shape as demonstrated in testBST
//R1: Recursive function to build a BST with smallest depth
//R2: Recursive function needs to find middle element in the array and insert it into the BST
//R3: Function then will make 2 recursive calls: one on the first half of the array not including middle element (indx 0 to mid - 1), and the second call on the second half of the array not including middle element (mid+1 to size - 1)
//R4: Base case for function: if array size is 1, insert it to BST and end the function
//Algo: Store given words in an array, sort array in aspherical order, call recursive function and pass the array to it

#include <string>   
#include "bst.h"
#include <algorithm>
using namespace std;

 binary_search_tree<string> wordsBST;   //Global variables can be accessed anywhere.
 
void smallDepthTree(string arr[], int firstIndx, int lastIndx){
    int midIndx = 0;
    string middleWord;  
    if(lastIndx - firstIndx > 0){ 
        midIndx = (firstIndx + lastIndx)/2;                       //Indx of middle element
        middleWord = (arr[midIndx]);                                  //Grabs word in the middle of the array (index 16, this way each half of the tree has 15 nodes)
        wordsBST.insert(middleWord);                               //Inserts middle word into the array
        smallDepthTree(arr, firstIndx, midIndx); 
        smallDepthTree(arr, midIndx+1, lastIndx);
    } 
}

int main(){

    string words[] = { "After", "Also", "any", "back", "because", "come", "day", "even", "first", "give", "how", "its",
                                    "look", "most", "new", "now", "only", "other", "our", "over", "than", "then", "these", 
                                    "think", "two", "us", "use", "want", "way", "well", "work" }; //31 elements

    int n = sizeof(words)/sizeof(words[0]);
    sort(words, (words+n)); //words + n is where the index will stop
    smallDepthTree(words, 0, 31);
    print(wordsBST.get_root(), 0);
    cout << "balanced? " << wordsBST.is_balanced() << endl;
    //Second part of first question
    cout<<"\nRemoving the root node..."<<endl;
    wordsBST.remove("now");
    print(wordsBST.get_root(), 0);
    cout << "balanced? " << wordsBST.is_balanced() << endl;
}

