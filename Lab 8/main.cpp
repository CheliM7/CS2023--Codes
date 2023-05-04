#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
//defining l and r
int l=(2*root)+1;
int r=(2*root)+2;
int largerVal;

//if the left value is larger than the root
if (l<n && arr[l]> arr[root]){
   largerVal= l;
}

//if not, the larger value will be the root
else{
   largerVal=root;
}

//comparing the larger value obtained with the right value
if (r<n &&  arr[r]> arr[largerVal]){
   largerVal= r;
}

//if the root is not the Larger value,swapping takes place
if (largerVal !=root){
   int temp;
    temp=arr[root] ;
    arr[root]=arr[largerVal]  ;
    arr[largerVal]=temp;
    heapify( arr,n,largerVal);
}
}

// implementing heap sort
void heapSort(int arr[], int n)
{
//building a max heap
for (int i=n/2-1;i>=0;i--){
    heapify(arr, n,i);
}

for (int i=n-1;i>=0;i--){
    int temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    heapify (arr,i,0);
}

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   //setting an array
   int arr[100];
   int x;
   cout<<endl;
   cout<<"Enter a digit: ";

   //obtaining the array length as a user input
   cin>> x;
   for(int i=0; i<x; i++){
    arr[i] = rand()% 1000;
   }

   cout<<"Input array"<<endl;
   displayArray(arr,x);

   //sorting the new randomly generated array
   heapSort(arr,x);

   cout << "Sorted array"<<endl;
   displayArray(arr,x);

}


