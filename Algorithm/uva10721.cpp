#include <iostream>

using namespace std;

/*
reference:
    https://ppt.cc/fr07lx
    https://ppt.cc/fzn4hx
*/

//static auto __ = []
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    return 0;
//}();

int n, k, m;
long long dp[51][51][51];

void compute()
{
   for (int i = 1; i < 51; i++) for (int j = i; j < 51; j++) dp[i][1][j] = 1; // 只有一個bar
   
   for (int n = 1; n <= 50; n++) for (int k = 1; k <= 50; k++) for (int m = 1; m <= 50; m++)
   {
       // 由於最多 n 個 units，因此當 m > n 時，dp[n][k][m] = dp[n][k][n]，也就是無法再接 bar 上去
       if (m > n) { dp[n][k][m] = dp[n][k][n]; continue; }
       // 新接上的 bar 寬度為 1 ~ m
       for (int i = 1; i <= m; i++) dp[n][k][m] += dp[n - i][k - 1][m];
          // ex: BC(7,4,3) = BC(6,3,3) + BC(5,3,3) + BC(4,3,3)
   }
    
}

int main()
{
    compute(); //先將全部計算出來
    while (cin >> n >> k >> m) cout << dp[n][k][m] << '\n';
}