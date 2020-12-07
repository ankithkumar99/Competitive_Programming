// LONGEST COMMON SUBSEQUENCE

#include<bits/stdc++.h>
using namespace std;

int static dp[101][101];

// RECURSION METHOD
int lcs1(string s1, string s2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1] == s2[m-1]){
        return 1 + lcs1(s1, s2, n-1, m-1);
    }
    else{
        return max(lcs1(s1, s2, n-1, m), lcs1(s1, s2, n, m-1));
    }
}

// MEMOIZATION METHOD
int lcs2(string s1, string s2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] == -1){
        if(s1[n-1] == s2[m-1]){
            return 1 + lcs1(s1, s2, n-1, m-1);
        }
        else{
            return max(lcs1(s1, s2, n-1, m), lcs1(s1, s2, n, m-1));
        }
    }
    else{
        return dp[n][m];
    }
}

// TABULATION METHOD
int lcs3(string s1, string s2, int n, int m){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    string s1 = "AGGTAB" , s2 = "GXTXAYB";
    int ans, n=s1.size(), m = s2.size();
    memset(dp, -1, sizeof(dp));
    ans = lcs3(s1, s2, n, m);
    cout << ans;
    return 0;
}