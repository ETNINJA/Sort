#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <time.h>

using namespace std;

void MergeSort (int *A, int *aux, int ini, int fim);

void MaxHeapify (int *A, int i, int tam);

void MakeHeap (int *A, int tam);

void HeapS (int *A, int tam);

int main(int argc, char *argv[])
{
   // vector<int> A= {2,4,1,6,8,5,3,7};
    //int A[atoi(argv[1])];
    //int aux[atoi(argv[1])];
    //aux.resize(atoi(argv[1]));     
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

    clock_t start_t, end_t, total_t;
    clock_t t= clock();

   

    MergeSort(A, aux, 0, atoi(argv[1]));

    t = clock() - t;
   
    cout<<"\n *** TOTAL time (sec) of the MergeSort: " << ((double)t)/CLOCKS_PER_SEC<<endl;

    t= clock();


    HeapS (A, atoi(argv[1]));

    t = clock() - t;

   
    cout<<"\n *** TOTAL time (sec) of the HeapSort: " << ((double)t)/CLOCKS_PER_SEC<<endl;
   
    /*cout<<"\nPrinting ORDERED: "<<endl;
    for(int i=0; i< atoi(argv[1]); i++)
    {
        cout<<A[i]<<" - ";
    }*/
    cout<<"\n"<<endl;
    return 0;
}

void  MergeSort (int *A, int *aux, int ini, int fim)
{
    if (ini!=fim-1)
    {
        int mid = (ini + (fim-1))/2;         
        MergeSort(A, aux, ini, mid+1);
        MergeSort(A, aux, mid+1, fim);
        
        int i = ini, j = mid+1, k=0;

		while(i != mid+1 && j != fim)
		{
			if(A[i] < A[j])
            {
				aux[k] = A[i];
                i++;
            }
			else
            {
                aux[k] = A[j];
                j++;
            }				
            k++;
		}

		while(i != mid+1)
        {
            aux[k] = A[i];
            k++; i++;
        }			

		while(j != fim)
        {
			aux[k] = A[j];
            k++;j++;
        }

		for(i=0;i<k;++i)
        {
            A[ini+i] = aux[i];
        }			
	}    
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
