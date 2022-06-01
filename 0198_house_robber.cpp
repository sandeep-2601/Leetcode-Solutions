/*
https://leetcode.com/problems/house-robber/
T.C O(N)
S.C O(1)
*/

class Solution {
public:
    int dp[110];
    int robhouses(int n,vector<int> &nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        int lv,rv;
        int curr;
        for(int i=1;i<=n;i++) {
             lv = nums[i] + prev2;
             rv = prev1;
             curr = max(lv,rv);
             prev2 = prev1;
             prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return robhouses(nums.size()-1,nums);
    }
};