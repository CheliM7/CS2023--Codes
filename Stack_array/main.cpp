#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

//defining the maximum size of the stack
#define MAX 500

class Stack {
    int top;

public:
    int a[MAX];

    //defining stack functions
    Stack() { top = -1; }
    bool Push(int x);
    int Pop();
    bool isEmpty();
    bool isFull();
    int StackTop();
    void Display();
};

bool Stack::Push(int x)
{
    //stack overflow(?)
    if (top >= (MAX - 1)) {
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

int Stack::Pop()
{
    //no more terms to be removed
    if (top < 0) {
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
bool Stack::isEmpty()
{
    if (top <= 0) {
        cout << "Empty Stack";
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isFull()
{
    if (top < (MAX-1)){
        return false;
    }
    else{
        return true;
    }
}


int Stack::StackTop()
{
    if (top > -1){
        return a[top];
    }
    else{
        cout << "Empty Stack";
        return -1;
    }
}

void Stack::Display()
{
    for (int i= 0; i<=top ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


// driver program
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
    cout << "Time taken | Array Implementation " << duration.count() << " microseconds" << endl;


    return 0;
}
