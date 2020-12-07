//  01-KNAPSACK PROBLEM

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

// RECURSIVE METHOD
int kp1(vector<int> wt, vector<int> val, int w, int n){
    if (w == 0 || n == 0){
        return 0;
    }
    if (wt[n-1] <= w){
        return max(val[n-1] + kp1(wt, val, w-wt[n-1], n-1), kp1(wt, val, w, n-1));
    }
    else {
        return kp1(wt, val, w, n-1);
    }
}

// MEMOIZATION METHOD
int kp2(vector<int> wt, vector<int> val, int w, int n){
    if (w == 0 || n == 0){
        return 0;
    }
    if (dp[n][w] != -1){
        return dp[n][w];
    }
    if (wt[n-1] <= w){
        dp[n][w] = max(val[n-1] + kp2(wt, val, w-wt[n-1], n-1), kp2(wt, val, w, n-1));
        return dp[n][w];
    }
    else {
        dp[n][w] = kp2(wt, val, w, n-1);
        return dp[n][w];
    }
}

// TABULATION METHOD
int kp3(vector<int> wt, vector<int> val, int w, int n){
    for (int i=0; i<=n; i++){
        for (int j=0; j<=w; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50, n = wt.size(), ans;
    memset(dp, -1, sizeof(dp));
    ans = kp3(wt, val, w, n);
    cout << ans;
}
