/* C++ program for Merge Sort */
//vector has time complexity constant - c++ reference.
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <time.h>

using namespace std;

void MergeSort (int *A, int *aux, int ini, int fim);

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

    cout<<"\n **Starting of the MergeSort: " << t<<endl;

    MergeSort(A, aux, 0, atoi(argv[1]));

    t = clock() - t;

    cout<<"\n **End of the MergeSort: " << clock()<<endl;   
   
    cout<<"\n *** TOTAL time (sec) of the MergeSort: " << ((double)t)/CLOCKS_PER_SEC<<endl;
   
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
