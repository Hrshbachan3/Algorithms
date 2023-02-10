// sort according to descending profit
// number of slots = max deadline, but here : slots = number of jobs
// allot jobs to slot right before deadline

// time complexity : O(n^2)
// axiliary space : O(n)

#include<iostream>
#include<bits/stdc++.h>

class item {

    public:
        int id;
        int deadline;
        int profit;
};

bool comp(item a, item b) {

    int x = a.profit;
    int y = b.profit;

    return x>y;
    // return a.deadline>b.deadline;
}

int main() {

    item job[7] = {{1,3,35},
                   {2,4,30},
                   {3,4,25},
                   {4,2,20},
                   {5,3,15},
                   {6,1,12},
                   {7,2,5}};

    int n=sizeof(job)/sizeof(job[0]);

    int slot[n]; // slots = number of jobs
    for(int i=0;i<n;i++) {
        slot[i]=0;
    }

    int answer[n];

    sort(job,job+n,comp); // sorting in descending order of profit

    // allocation
    for(int i=0;i<n;i++) {

        for(int j=job[i].deadline-1;j>=0;j--) {

            if(slot[j]==0) {

                slot[j]=1;
                answer[j]=i;
                break;
            }
        }
    }

    cout<<"answer: ";

    for(int i=0;i<n;i++) {

        if(slot[i]) {
            cout<<job[answer[i]].id<<" ";
        }
    }

    cout<<endl;
}