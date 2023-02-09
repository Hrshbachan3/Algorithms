#include<iostream>
using namespace std;

void merge(int A[], int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1];
    int right[n2];

    for(int i=0;i<n1;i++) {

        left[i] = A[low+i];
    }

    for(int i=0;i<n2;i++) {

        right[i] = A[(mid+1)+i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while(i<n1 && j<n2) {

        if(left[i]<=right[j]) {
            A[k] = left[i];
            i++;
        }

        else {
            A[k] = right[j];
            j++;
        }

        k++;
    }

    while(j<n2) {
        A[k] = right[j];
        j++;
        k++;
    }

    while(i<n1) {
        A[k] = left[i];
        i++;
        k++;
    }
}


void mergesortrecursive(int A[], int low, int high) {

    if(low<high) {

        int mid = (low+high)/2;

        mergesortrecursive(A,low,mid);
        mergesortrecursive(A,mid+1,high);

        merge(A,low,mid,high);
    }
}

void mergesortiterative(int A[],int low, int high) {

    for(int size=1;size<(high-low);size=2*size) {

        for(int i=low;i<high;i=i+2*size) {

            int branch_low = i;
            int branch_mid = i+size-1;
            int branch_high = i+(2*size)-1;

            if(high<branch_high) {
                branch_high = high;
            }

            merge(A,branch_low,branch_mid,branch_high);
        }
    }
}

int main() {

    int A[] = {12,2,3,0,45,6};

    int n = sizeof(A)/sizeof(int);

    mergesortiterative(A,0,n-1);
    mergesortrecursive(A,0,n-1);

    for(int i=0;i<n;i++) {

        cout<<A[i]<<" ";
    }

    cout<<endl;
}