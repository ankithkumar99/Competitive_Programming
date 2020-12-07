// COUNT THE NO OF SUBSETS WITH GIVEN DIFFERENCE

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
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int countsubsetdiff(vector<int> arr, int diff){
    int sum1, sum=0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    sum1 = (sum + diff) / 2;
    return countsubsetsum(arr, sum1);
}

int main(){
    vector<int> arr = {1, 2, 1, 3};
    int diff = 1, ans;
    ans = countsubsetdiff(arr, diff);
    cout << ans;
    return 0;
}