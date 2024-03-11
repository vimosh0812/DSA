#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; // initialize largest as root
   int l = 2*root + 1; // left = 2*i + 1
   int r = 2*root + 2; // right = 2*i + 2

   // if left child is larger than root
   if (l < n && arr[l] > arr[largest]){
      largest = l;
   }

   // if right child is larger than largest so far
   if (r < n && arr[r] > arr[largest]){
      largest = r;
   }

   // if largest is not root
   if (largest != root){
      swap(arr[root], arr[largest]);
      // recursively heapify the affected sub-tree
      heapify(arr, n, largest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--){
      heapify(arr, n, i);
   } 
  
   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--){
      // move current root to end
      swap(arr[0], arr[i]);
  
      // call max heapify on the reduced heap
      heapify(arr, i, 0);
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
   int heap_arr[] = {34,2,13,22,9,16};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
