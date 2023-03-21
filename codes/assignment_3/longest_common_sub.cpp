#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursive approach
int recursive_LCS(string s1, string s2, int m, int n) {

    if(m == 0 || n == 0) {
        return 0;
    }
    
    if(s1[m-1] == s2[n-1]) {

        return 1 + recursive_LCS(s1,s2,m-1,n-1);
    }
    else {

        return max(recursive_LCS(s1,s2,m-1,n),recursive_LCS(s1,s2,m,n-1));
    }
}

// recursive memoization, tabular tho
// will have to use vectors coz 2D arrays cannot be called without specifying at least 1 dimension.
// recommended, specify the 2nd dimension in 2D array while calling, first dimension can be ambiguous.
int dynamic_LCS(string s1, string s2, int m, int n, vector<vector<int> >dp) {

    if(m == 0 || n == 0) {
        return 0;
    }

    if(s1[m-1] == s2[n-1]) {

        return dp[m][n] = 1 + dynamic_LCS(s1,s2,m-1,n-1,dp);
    }
    else {

        return dp[m][n] = max(dynamic_LCS(s1,s2,m-1,n,dp),dynamic_LCS(s1,s2,m,n-1,dp));
    }
}

// recursive memoization without the vector
class dynamic_LCS_array {

    public:
        int dp[100][100];

        int dynamic_LCS(string s1, string s2, int m, int n) {
            if(m == 0 || n == 0) {
                return 0;
            }

            if(s1[m-1] == s2[n-1]) {

                return dp[m][n] = 1 + dynamic_LCS(s1,s2,m-1,n-1);
            }
            else {

                return dp[m][n] = max(dynamic_LCS(s1,s2,m-1,n),dynamic_LCS(s1,s2,m,n-1));
                }
        }
};

// iterative tabulatiton
int iterative_LCS(string s1, string s2, int m, int n) {

    int dpi[m+1][n+1];

    //initialzation coz 1st row and column are 0
    for(int i=0;i<m+1;i++) {
        dpi[i][0] = 0;
    }
    for(int j=0;j<n+1;j++) {
        dpi[0][j] = 0;
    }

    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {

            if(s1[i-1] == s2[j-1]) {

                dpi[i][j] = 1 + dpi[i-1][j-1];
            }

            else {

                dpi[i][j] = max(dpi[i-1][j],dpi[i][j-1]);
            }
        }
    }

    return dpi[m][n];
}

int main() {

    string s1;
    string s2;

    cout<<"enter first word: ";
    cin>>s1;

    cout<<"enter second word: ";
    cin>>s2;

    int m = s1.size();
    int n = s2.size();

    dynamic_LCS_array dynamic_LCS2;

    // ???????????????????
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));

    cout<<"longest common subsequence is: "<<recursive_LCS(s1,s2,m,n);
    cout<<endl;
    cout<<"longest common subsequence is: "<<dynamic_LCS(s1,s2,m,n,dp);
    cout<<endl;
    cout<<"longest common subsequence is: "<<dynamic_LCS2.dynamic_LCS(s1,s2,m,n);
    cout<<endl;
    cout<<"longest common subsequence is: "<<iterative_LCS(s1,s2,m,n);
    cout<<endl;
}