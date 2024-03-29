#include <iostream>
#include <vector>

using namespace std;

int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp ){
    
    for (int r = n - 1; r >= 0; r--) {
        for (int c = m - 1; c >= 0; c--) {
            if (r == n - 1 && c == m - 1) 
                dp[r][c] = arr[r][c];
            else if (r == n - 1) 
                dp[r][c] = dp[r][c + 1] + arr[r][c];
            else if (c == m - 1) 
                dp[r][c] = dp[r + 1][c] + arr[r][c];
            else 
                dp[r][c] = min(dp[r + 1][c], dp[r][c + 1]) + arr[r][c];
        }
    }
    return dp[0][0];
}

int main()  {

    int n;
    int m;
    cin >> n >> m;
  
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<int>> dp(n, vector<int>(m));

    cout << minCost(n, m, arr, dp);
}
