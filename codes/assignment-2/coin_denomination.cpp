#include<iostream>
#include<bits/stdc++.h>

int main() {

    int V = 999;

    int denomination[] = {2,5,10,20,50,100,200,500};

    int n= sizeof(denomination)/sizeof(denomination[0]);

    sort(denomination,denomination+n,greater<int>());

    int i=0;

    while(V) {

        if(denomination[i]<=V) {
            cout<<denomination[i]<<" ";
            V=V-denomination[i];
        }
        else {
            i++;
        }
    }
}