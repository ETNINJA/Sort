/* C++ program for Merge Sort */
//vector has time complexity constant - c++ reference.
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h>

using namespace std;

// Function to implement stooge sort 
void stoogesort(int A[], int l, int h) 
{ 
    if (l >= h) 
        return; 
  
    // If first element is smaller than last, 
    // swap them 
    if (A[l] > A[h]) 
        swap(A[l], A[h]); 
  
    // If there are more than 2 elements in 
    // the array 
    if (h - l + 1 > 2) { 
        int t = (h - l + 1) / 3; 
  
        // Recursively sort first 2/3 elements 
        stoogesort(A, l, h - t); 
  
        // Recursively sort last 2/3 elements 
        stoogesort(A, l + t, h); 
  
        // Recursively sort first 2/3 elements 
        // again to confirm 
        stoogesort(A, l, h - t); 
    } 
} 
  
// Driver Code 
int main(int argc, char *argv[]) 
{ 
    int *A = (int*)malloc((atoi(argv[1]))*sizeof(int));
    int *aux = (int*)malloc((atoi(argv[1]))*sizeof(int));
    for(int i=0; i< atoi(argv[1]); i++)
    {
        A[i]=(rand() % 100);
        
    }
    
    /*cout<<"\nPrinting not order: "<<endl;
    for(int i=0; i< atoi(argv[1]); i++)
    {
        cout<<A[i]<<" - ";
    }*/

    cout<<endl;
     clock_t start_t, end_t, total_t;
    clock_t t= clock();

    //cout<<"\n **Starting of the stoogesort: " << t<<endl;

    // Calling Stooge Sort function to sort 
    // the array 
    stoogesort(A, 0, atoi(argv[1])-1); 

    t = clock() - t;

    //cout<<"\n **End of the stoogesort: " << clock()<<endl;   
   
    //cout<<"\n *** TOTAL time (sec) of the stoogesort: " << ((double)t)/CLOCKS_PER_SEC<<endl; 
    cout<<((double)t)/CLOCKS_PER_SEC<<endl;
    
  
    // Display the sorted array 
    /*for (int i = 0; i < atoi(argv[1]); i++) 
        cout << A[i] << " "; */

    cout<<endl;
  
    return 0; 
} 
