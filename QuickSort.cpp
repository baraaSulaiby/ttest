#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>

using namespace std;


double randDouble(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

void quickSort(double A[], int p, int q);

//declare the partition function
int partition(double A[], int p, int q);

// #define ArraySize 1000
const int ArrayOfSizes [] = {10000, 20000, 30000, 40000, 50000};

main()
{
    srand(time(NULL));


    for (int ArraySize: ArrayOfSizes){
        
        double A[ArraySize];
        for (int i = 0; i < ArraySize; i++)
        {
            double x = randDouble(0, 100);
            A[i] = x;
            // cout<<A[i]<<", ";
        }

        cout << endl
            << endl;

        clock_t begin = clock();
        
        quickSort(A, 0, ArraySize - 1);
        
        clock_t end = clock();

        cout << (float)(end - begin) / CLOCKS_PER_SEC;
        cout << endl;

        cout << ArraySize << endl;
        
        // for (int i = 0; i < ArraySize; i++)
        //     cout << A[i] << ", ";
        cout << endl;
    }


}


// Quick Sort 
void quickSort(double A[], int p, int q)
{
    if (p < q)
    {
        int r = partition(A, p, q);
        quickSort(A, p, r - 1);
        quickSort(A, r + 1, q);
    }
}

int partition(double A[], int p, int q)
{
    double x = A[q];
    int i = p - 1;

    for (int j = p; j < q; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[q]);
    return i + 1;
}