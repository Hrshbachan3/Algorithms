// calculate profit/weight
// sort in descending order as per profit/weight
// start filling bag in arranged order till filled

// time complexity: O(n*logn)
// space complexity: O(n)

#include<iostream>
#include<bits/stdc++.h>

class item {

    public:
        float weight;
        float profit;
};

bool comp(item a, item b) {

    float x = (a.profit)/(a.weight);
    float y = (b.profit)/(b.weight);
 
    return x>y;
}

int main() {

    float bag = 60;
    float max_profit=0;

    item A[] = {{5,30},{10,40},{15,45},{22,77},{25,90}};

    sort(A,A+5,comp); // introsort = quick + heap + insertion ; with a comparator

    cout<<"sorted data: ";

    for(int i=0;i<5;i++) {
        cout<<"["<<A[i].weight<<","<<A[i].profit<<"]";
    }

    cout<<endl;

    for(int i=0;i<5;i++) {

        if(bag<=A[i].weight) {

            max_profit = max_profit + bag*(A[i].profit/A[i].weight);
            bag = 0;
            break;
        }
        else {

            bag = bag - A[i].weight;
            max_profit = max_profit + A[i].profit;
        }
    }

    cout<<"maximum profit: "<<max_profit;

    cout<<endl;
}