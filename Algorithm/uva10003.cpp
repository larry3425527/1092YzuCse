#include <iostream>
using namespace std;

int l;
int n;
int dp[52][52];

void compute()
{
    cin >> n;
    int * table = new int[n + 2];
    n++;
    table[0] = 0; table[n] = l;
    for (int i = 1; i < n; i++) cin >> table[i];
    int end , temp;
    for (int rang = 2; rang <= n; rang++)
    {
        for (int begin = 0; begin < n; begin++)
        {
            end = begin + rang;
            if (end > n) break;
            dp[begin][end] = INT_MAX;
            for (int c = begin + 1; c < end; c++)
            {
                temp = dp[begin][c] + dp[c][end] + table[end] - table[begin];
                if (temp < dp[begin][end]) dp[begin][end] = temp;
               // cout << "dp" << begin << end <<dp[begin][end] << endl;
            }
        }
    }
}

int main()
{
    while (cin >> l && l != 0) 
    {
        compute();
        cout << "The minimum cutting is " <<  dp[0][n] << endl;
    }
    return 0;
}