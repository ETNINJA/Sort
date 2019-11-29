/* C++ program for Quick Sort */
//vector has time complexity constant - c++ reference.
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void QuickSort(vector<int> &A, int begin, int end);
int Partition (vector<int> &A, int begin, int end);
void Qs (vector<int> &A, vector<int> &L,vector<int> &R);

int main()
{
    vector<int> A;
    clock_t start_t, end_t, total_t;
    srand(time(NULL));
    for(int i=0; i< 1000000; i++)
    {
        A.push_back(rand() % 100000);
    }

    /*cout<<"\nPrinting not order: "<<endl;
    for(int i=0; i< A.size(); i++)
    {
        cout<<A[i]<<" - ";
    }*/

    clock_t t= clock();
    cout<<"\n **Starting of the QuickSort: " << t<<endl;

    QuickSort(A, 0, (A.size()-1));

    t = clock() - t;
    cout<<"\n **End of the QuickSort: " << clock()<<endl;   
   
    cout<<"\n *** TOTAL time (sec) of the QuickSort: " << ((double)t)/CLOCKS_PER_SEC<<endl;
   
    /*cout<<"\nPrinting ORDERED: "<<endl;
    for(int i=0; i< A.size(); i++)
    {
        cout<<A[i]<<" - ";
    }*/
    cout<<"\n"<<endl;
    return 0;
}

void QuickSort(vector<int> &A, int begin, int end)
{
    if (begin>=end) return;
   int pivot = Partition(A, begin, end);
   QuickSort(A,begin, pivot-1);
   QuickSort(A, pivot+1, end);
   
}
int Partition (vector<int> &A, int begin, int end)
{
    int pivot = A[end];
    //cout<<"\npivot"<<pivot<<" end: "<<end<<endl;
    int  j = begin, menor;

    for(int i=begin; i<end; i++) 
    {
        if (A[i]<= pivot)
        {
            int menor = A[i];
            A[i] = A[j];
            A[j]=menor;
            //cout<<"A[i]"<<A[i]<<" i: "<<i<<endl;
            j++;
        }
    }
    A[end]=A[j];
    //cout<<"A[j]"<<A[j]<<" j: "<<j<<endl;
    A[j] = pivot;
    return j;
}