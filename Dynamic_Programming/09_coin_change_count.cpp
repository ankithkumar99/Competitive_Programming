// COIN CHANGE COUNT PROBLEM

#include<bits/stdc++.h>
using namespace std;

int countsubsetsum(vector<int> arr, int sum){
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
                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return dp[n][sum];
}

int main(){
    vector<int> arr = {1, 2, 3};
    int sum = 4, ans;
    ans = countsubsetsum(arr, sum);
    cout << ans;
    return 0;
}