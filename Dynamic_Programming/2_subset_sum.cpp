#include<bits/stdc++.h>
using namespace std;

int subsetsum(vector<int> arr, int sum){
    int n = arr.size();
    int dp[n+1][sum+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int j=1; j<=sum;j++){
        dp[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 33, ans;
    ans = subsetsum(arr, sum);
    if(ans == 0)
        cout << "False";
    else
        cout << "True";
}