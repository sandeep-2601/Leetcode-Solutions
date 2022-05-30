/*
https://leetcode.com/problems/best-sightseeing-pair/
T.C O(N)
S.C O(1)
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = values[0];
        int res = -1;
        
        for(int i=1;i<n;i++) {
            res  = max(res,maxi + values[i] - i);
            maxi = max(maxi,values[i] + i);
        }
        
        return res;
    }
};