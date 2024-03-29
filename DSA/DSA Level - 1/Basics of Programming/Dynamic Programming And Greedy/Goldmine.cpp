#include <bits/stdc++.h>
using namespace std;


void maxGold(int n, int m, vector <vector<int> > &arr, vector<vector<int> > &dp ) {

    for(int j= m - 1; j >= 0; j--){
        for(int i = n - 1; i >= 0; i--){
            if(j == m - 1) 
                dp[i][j] = arr[i][j]; 
                
            else if(i == 0 && n == 1)
                dp[i][j] = arr[i][j] + dp[i][j+1];  
                
            else if(i == 0 && n > 1)
                dp[i][j] = arr[i][j] + max(dp[i+1][j+1], dp[i][j+1]);  
                
            else if(i == n - 1)
                dp[i][j] = arr[i][j] + max(dp[i-1][j+1], dp[i][j+1]);   
            
            else
                dp[i][j] = arr[i][j] + max(max(dp[i+1][j+1], dp[i][j+1]), dp[i-1][j+1]); 
        }
    }
    int max = dp[0][0];
    for(int i = 1; i < n; i++){
        if(dp[i][0] > max){
            max = dp[i][0];
        }
    }
    cout << max;

}

int main() {
    int m, n;
    cin >> n >> m;
    vector <vector<int> > arr (n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector <vector<int> > dp (n, vector <int> (m));
    maxGold(n, m, arr, dp);


}