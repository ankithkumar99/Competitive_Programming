#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int uk(vector<int> len, vector<int> price, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(len[i-1] <= j){
                dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

int main(){
    vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = len.size(), ans;
    memset(dp, -1, sizeof(dp));
    ans = uk(len, price, n);
    cout << ans;
    return 0;
}