/*
https://leetcode.com/problems/climbing-stairs/
*/

/*
T.C O(N)
S.C O(N)
*/

class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};

/*
T.C O(N)
S.C O(N)
*/

class Solution {
public:
     int climbStairs(int n) {
        int temp;
        int w1 = 1;
        int w2 = 1;
        for(int i=2;i<=n;i++) {
            temp = w2;
            w2 = w1 + w2;
            w1 = temp;
        }
        return w2;
    }
};