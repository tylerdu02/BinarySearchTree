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
                else if (num == 0) { 
                    done = true;
                }
                 else {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == 'F' || input[0] == 'f') { // generates numbers from numbers.txt file
            cout << "Numbers from file are in the tree" << endl;
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
        if (input[0] == 'S' || input[0] == 's') { // search
            int searchNum;
            cout << "What number would you like to search?" << endl;
            cin >> searchNum;
            cin.ignore(1, '\n');
            search(n, searchNum);
        }
        if (input[0] == 'Q' || input[0] == 'q') { // quit
            running = false;
        }
    }
}

void insert(Node* &n, Node* newNode) { // inserts new node into tree
    if (n == NULL) { 
        n = newNode;
    }
    else if (newNode->data <= n->data) {
        insert(n->left, newNode); 
    }
    else if (newNode->data > n->data) { 
        insert(n->right, newNode);
    }
}

void print(Node* n, int numTabs) { // prints tree in order
    if (n == NULL) { 
        return;
    }
    numTabs += 10;
    print(n->right, numTabs); 
    cout << endl;
    for (int i = 10; i < numTabs; i++) { 
        cout << " ";
    }
    cout << n->data << endl;
    print(n->left, numTabs);  
}

void remove(Node* &n, int value) { // removes value from tree
    if (n == NULL) { 
        cout << "Invalid input. Try again." << endl;
        return;
    }
    else if (value < n->data) { 
        remove(n->left, value); 
    }
    else if (value > n->data) { 
        remove(n->right, value);
    }
    else if (value == n->data) { 
        if (n->left == NULL && n->right == NULL) { 
            cout << "Deleted number: " << value << endl;
            delete n;
            n = NULL;
        }
        else if (n->left == NULL) { 
            cout << "Deleted number: " << value << endl;
            Node* temp = n;
            n = n->right;
            delete temp;
        }
        else if (n->right == NULL) { 
            cout << "Deleted number: " << value << endl;
            Node* temp = n;
            n = n->left;
            delete temp;
        }
        else { 
            cout << "Deleted number: " << value << endl;
            Node* temp = n->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            n->data = temp->data;
            remove(n->right, temp->data);
        }
    }
    else { 
        cout << "Invalid input. Try again." << endl;
    }
}

void search(Node* n, int value) { // searches for a value 
    if (n == NULL) { 
        cout << "Invalid input. Try again." << endl;
        return;
    }
    else if (value < n->data) { 
        search(n->left, value);
    }
    else if (value > n->data) { 
        search(n->right, value);
    }
    else if (value == n->data) { 
        cout << "Number: " << value << endl;
    }
    else { 
        cout << "Invalid input. Try again." << endl;
    }
}