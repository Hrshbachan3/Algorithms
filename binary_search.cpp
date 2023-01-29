#include<iostream>
using namespace std;

int binarysearchiterative(int A[], int high, int low, int target) {

    while(high>=low) {
        
        int mid = low + (high-low)/2;

        if(target==A[mid]) {
            return mid;
        }

        if(target>A[mid]) {
            low = mid+1;
        }
        else if(target<A[mid]) {
            high = mid-1;
        }
    }

    return -1;
}

int binarysearchrecursive(int A[], int high, int low, int target) {

    int mid = low + (high-low)/2;

    if(high>=low) {

        if(target==A[mid]) {
            return mid;
        }

        if(target>A[mid]) {
            return binarysearchrecursive(A, high, mid+1, target);
        }
        else if(target<A[mid]) {
            return binarysearchrecursive(A, mid-1, low, target);
        }
    }

    return -1;
}

int main() {

    int A[] = {0,20,30,50,60,80,110,130,140};

    int n = sizeof(A)/sizeof(int);

    int mid = n/2;
    int high = n-1;
    int low = 0;

    int target = 40;
    
    int ans = binarysearchiterative(A,high,low,target);
    int ans = binarysearchrecursive(A,high,low,target);

    cout<<ans;

    cout<<endl;
}