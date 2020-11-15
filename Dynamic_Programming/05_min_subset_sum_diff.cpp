#include<bits/stdc++.h>
using namespace std;

int subsetsumdiff(vector<int> arr, int sum){
    int n = arr.size();
    int dp[n+1][sum+1];
    for (int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for (int j=1; j<=sum; j++){
        dp[0][j] = 0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> v1;
    for (int j=0; j<=sum/2; j++){
        if(dp[n][j] == 1){
            v1.push_back(j);
        }
    }
    int mn = INT_MAX;
    for (int i=1; i<v1.size(); i++){
        //cout << v1[i] << " ";
        mn = min(mn, sum - 2*v1[i]);
    }
    return mn;
}

int main(){
    vector<int> arr = {3, 1, 4, 2, 2, 1};
    int sum = 0, ans;
    for (int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    ans = subsetsumdiff(arr, sum);
    cout << ans;
    return 0;
}