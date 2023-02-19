// maximize throughput
// sort jobs according to ascending finsih times
// print first job
// choose next activity such that : FT[i-1]<=ST[i]

// time complexity : O(n^2*log(n))

#include<iostream>
#include<bits/stdc++.h>

class item {

    public:
        int id;
        int ST;
        int FT;
};

bool comp(item a, item b) {

    int x = a.FT;
    int y = b.FT;

    return x<y;
    //return a.FT>b.FT;
}

int main() {

    item job[6] = {{1,0,6},
                   {2,3,4},
                   {3,1,2},
                   {4,5,9},
                   {5,5,7},
                   {6,8,9}};

    int n = sizeof(job)/sizeof(job[0]);

    sort(job,job+n,comp);

    for(int i=0;i<n;i++) {
        
        cout<<"["<<job[i].id<<","<<job[i].ST<<","<<job[i].FT<<"]";
    }

    int result[n];
    for(int i=0;i<n;i++) {
        result[i]=0;
    }

    for(int i=0;i<n;i++) {

        if(i==0) {
            result[i]=job[i].id;
        }

        else {

            for (int j=i;j<n;j++) {

                if(job[i-1].FT<=job[j].ST) {

                    result[i] = job[j].id;
                    i=j;
                    break;
                }
            }
        }
        
    }

    cout<<endl<<"answer: ";

    for(int i=0;i<n;i++) {
        if(result[i]!=0) {
            cout<<result[i]<<" ";
        }
    }

    cout<<endl;
}