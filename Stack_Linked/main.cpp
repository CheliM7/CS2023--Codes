
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// creating a linked list;
class Node {
public:
    int data;
    Node* link;

    // node implementation
     Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void Push(int data){
        // creating a new node temp and adding data
        Node* temp = new Node(data);

        // initializing data into temp data field
        temp->data = data;

        //top pointer reference to temp link
        temp->link = top;

        // setting temp as the top
        top = temp;
    }

       bool isEmpty()
    {
        // If top is NULL, there are no elements are in stack
        return top == NULL;
    }

    //function: returns top element in a stack
    int StackTop()
    {
        // if the stack is not empty , return the top element
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    // pop function
    void Pop()
    {
        Node* temp;
        // stack underflow(?)
        if (top == NULL) {
            exit(1);
        }

        else {
            temp = top;
            top = top->link;
            // deleting the node
            free(temp);
        }
    }

    //function: print all the elements of the stack
    void Display()
    {
        Node* temp;
        //stack underflow(?)
        if (top == NULL) {
            exit(1);
        }

        else {
            temp = top;
            while (temp != NULL) {
                // printing node data
                cout << temp->data;
                // assigning temp link to temp
                temp = temp->link;

                if (temp != NULL)
                    cout << " ";
            }

            cout << endl;
        }
    }
};

// Driver program
int main()
{
    auto start = high_resolution_clock::now();

    class Stack s;
    s.Push(11);
    s.Push(14);
    s.Push(2);
    s.Push(91);
    s.Push(5);
    s.Push(23);
    s.Push(16);
    s.Push(12);
    s.Push(2);
    s.Push(4);
    s.Display();
    for(int i=0;i<5;i++){
        s.Pop();
    }
    s.Display();
    s.Push(300);
    s.Push(300);
    s.Push(22);
    s.Push(1);
    s.Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken | Stack as a Linked List " << duration.count() << " microseconds" << endl;

    return 0;
    }
