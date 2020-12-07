// UNBOUNDED KNAPSACK PROBLEM

#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int uk(vector<int> wt, vector<int> val, int w, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return dp[n][w];
}

int main(){
    vector<int> wt = {1, 50};
    vector<int> val = {1, 30};
    int w = 100, n = wt.size(), ans;
    memset(dp, -1, sizeof(dp));
    ans = uk(wt, val, w, n);
    cout << ans;
    return 0;
}