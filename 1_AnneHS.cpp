/*************************************************************/
// Anne Almeida - heapsort
/*************************************************************/

#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void MaxHeapify (int *A, int i, int tam);

void MakeHeap (int *A, int tam);

void HeapS (int *A, int tam);

int main(int argc, char *argv[])
{
    //int *A = (int*)malloc((atoi(argv[1]))*sizeof(int));
    int A [] = {9, 6, 5, 0, 8, 2, 1, 3};
        
    /*for(int i=0; i< atoi(argv[1]); i++)
    {
        A[i]=(rand() % 100);
        
    }*/
    
    /*cout<<"\nPrinting not order: "<<endl;
    for(int i=0; i< atoi(argv[1]); i++)
    {
        cout<<A[i]<<" - ";
    }*/

    clock_t start_t, end_t, total_t;
    clock_t t= clock();

    cout<<"\n **Starting of the HeapSort: " << t<<endl;

    HeapS (A, atoi(argv[1]));

    t = clock() - t;

    cout<<"\n **End of the HeapSort: " << clock()<<endl;   
   
    cout<<"\n *** TOTAL time (sec) of the HeapSort: " << ((double)t)/CLOCKS_PER_SEC<<endl;
   
    cout<<"\nPrinting ORDERED: "<<endl;
    for(int i=0; i< atoi(argv[1]); i++)
    {
        cout<<A[i]<<" - ";
    }
    cout<<"\n"<<endl;
    return 0;
}

void MaxHeapify (int *A, int i, int tam)
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maior, aux;

    if ((left < tam) && (A[left] > A[i]))  
        maior = left;
    else maior = i;

    if ((right < tam) && (A[right] > A[maior]))  
        maior = right;
    if (maior != i)
    {
        aux= A[i];
        A[i] = A[maior];
        A[maior]= aux;
        MaxHeapify(A,maior, tam);    
    }
}

void MakeHeap (int *A, int tam)
{
    for (int i = (tam/2); i>=0; i--)
    {
        MaxHeapify(A,i,tam);
    }
}
void HeapS (int *A, int tam)
{
    int aux;
    MakeHeap (A, tam);
    for ( int i = tam-1; i>0; i--)
    {
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        tam--;
        MaxHeapify(A,0,tam);
    }
}
