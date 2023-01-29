#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int low, int high) {

    int pivot = A[high];
    int i = low-1;

    for (int j=low;j<=high-1;j++) {
        
        if (A[j]<pivot) {

            i++;

            swap(A[i],A[j]);
        }
    }

    swap(A[i+1],A[high]);

    return i+1;
}

void quicksortrecursive(int A[], int low, int high) {

    if (low < high) {

        int pi = partition(A,low,high);

        quicksortrecursive(A,low,pi-1);
        quicksortrecursive(A,pi+1,high);
    }
}

void quicksortiterative(int A[],int low, int high) {

    int n = high-low+1;
    int stack[n];
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;

    while(top>=0) {

        high = stack[top--];
        low = stack[top--];

        int pivot = partition(A,low,high);

        if((pivot-1)>low) {

            stack[++top] = low;
            stack[++top] = pivot-1;
        }

        if ((pivot+1)<high) {

            stack[++top] = pivot+1;
            stack[++top] = high;
        }
    }
}

int main() {

    int A[] = {12,2,3,0,45,6};

    int n = sizeof(A)/sizeof(int);

    quicksortiterative(A,0,n-1);
    quicksortrecursive(A,0,n-1);

    for(int i=0;i<n;i++) {

        cout<<A[i]<<" ";
    }

    cout<<endl;
}