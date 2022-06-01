/*
https://leetcode.com/problems/house-robber-ii/
T.C O(N)
S.C O(1)
*/
class Solution {
public:
    int robhouses(int start,int n,vector<int> &nums) {
        int prev1 = nums[start];
        int prev2 = 0;
        int lv,rv;
        int curr;
        for(int i=start+1;i<=n;i++) {
             lv = nums[i] + prev2;
             rv = prev1;
             curr = max(lv,rv);
             prev2 = prev1;
             prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
            
        int first  = robhouses(0,n-2,nums);
        int last = robhouses(1,n-1,nums);
        
        return max(first,last);
    }
};