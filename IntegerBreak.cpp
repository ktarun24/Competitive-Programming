//Given a positive integer n, break it into the sum of at least two positive integers 
//and maximize the product of those integers. Return the maximum product you can get .

//Question link : https://leetcode.com/problems/integer-break/

class Solution {
public:
      int integerBreak(int n) {
        if(n <= 3)
        {
            return n-1;
        }
        int dp[n + 1][n + 1], i, j;
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else if(j >= i)
                {
                    int x = (dp[i][j - i]) * i;
                    dp[i][j] = max(dp[i - 1][j], x);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][n];
    }
};
