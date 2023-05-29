/*
* Tyler Du
* 4/23/23
* Binary Search Tree
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstring>

using namespace std;
  
struct Node {
    int data;
    Node* right;
    Node* left;
    Node(int newNode) {
        data = newNode;
        right = NULL;
        left = NULL;
    }
};

void insert(Node* &n, Node* newNode);
void print(Node* n, int numTabs);
void remove(Node* &n, int value);
void search(Node* n, int value);

int main() {
    char input[10];
    bool running = true;
    Node* n = NULL;

    while (running == true) { 
      cout << "Add, print, file, delete, search, or quit" << endl;
      cout << "Typing file will use the numbers from the file" << endl;

        cin.get(input, 10);
        cin.ignore(1, '\n');

        if (input[0] == 'A' || input[0] == 'a') { // inputs numbers into the tree
            int num;
            bool done = false;
            cout << "Input numbers 1-999, type '0' when done" << endl;
            while (done == false) { 
                cin >> num;
                cin.ignore(1, '\n');
                if (num >= 1 && num <= 999) { // input
                    Node* newNode = new Node(num);
                    insert(n, newNode);
                }
                else if (num == 0) { // done inputting numbers
                    done = true;
                }
                 else {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == 'F' || input[0] == 'f') { // generates numbers from a file
            cout << "Numbers from file are in the n" << endl;
            ifstream numbers;
            numbers.open("numbers.txt");
            int numnums;
            while (numbers >> numnums) {
                Node* newNode = new Node(numnums);
                insert(n, newNode);
            }
            numbers.close();
        }
        if (input[0] == 'P' || input[0] == 'p') { // prints
            print(n, 0);
        }
        if (input[0] == 'D' || input[0] == 'd') { // delete
            cout << "What number would you like to delete?" << endl;
            int deleteNum;
            cin >> deleteNum;
            cin.ignore(1, '\n');
            remove(n, deleteNum);
        }
        if (input[0] == 'S' || input[0] == 's') { // searches for a value in the tree
            int searchNum;
            cout << "What number would you like to search?" << endl;
            cin >> searchNum;
            cin.ignore(1, '\n');
            search(n, searchNum);
        }
        if (input[0] == 'Q' || input[0] == 'q') { // quits the program
            running = false;
        }
    }
}
 