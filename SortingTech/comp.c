#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int *A, int n)
{
    int flag;
    for(int i = 0; i < n-1; i++) {
        flag = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
    }
}

void Insertion(int *A, int n)
{
    int x, i, j;

    for(i = 1; i < n; i++) {
        x = A[i];
        j = i - 1;
        while (j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

/**
 * Selection Sort
 */
void Selection(int *A, int n)
{
    int j, k;

    for(int i = 0; i < n-1; i++) {
        for(j = k = i; j < n; j++) {
            if(A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

/**
 * Quick Sort
 */
static int partition(int A[],int l,int h)
{
    int pivot = A[l];
    int i = l,j = h;
    
    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        
        if(i < j)swap(&A[i], &A[j]);
    }while(i < j);
    
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;
    
    if(l<h)
    {
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

/**
 * Merge Sort
 */
static void Merge(int *A, int l, int mid, int h)
{
    int i, j , k;
    int B[h+1];
    i = l;
    j = mid +1;
    k = l;
    while(i <= mid && j <= h) {
        if(A[i] < A[j]) {
            B[k++] = A[i++];
        } 
        else {
            B[k++] = A[j++];
        }
    }
    for(; i <= mid; i++) {
        B[k++] = A[i];
    }
    for(; j <= h; j++) {
        B[k++] = A[j];
    }
    for(i = l; i <= h; i++) {
        A[i] = B[i];
    }
}
void IMergeSort(int *A, int n)
{
    int p, l, h, mid, i;
    for(p = 2; p <= n; p = p * 2) {
        for(i = 0; i+p-1 < n; i = i + p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
    }
    if(p/2 < n) {
        printf("%d\n", p/2-1);
        Merge(A, 0, p/2 - 1, n - 1);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3};
    int n =10;
    
    IMergeSort(A, n);

    for(int i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}