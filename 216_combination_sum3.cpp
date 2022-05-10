/*
    Problem -> https://leetcode.com/problems/combination-sum-iii/
    T.C ->  O(2^N)
    // S.C ->  O(N)
    where N is 9
*/
class Solution {
public:
    vector<vector<int>> res;
    void combination(int curr,int k,int idx,int size,int n,vector<int> &arr,vector<int> &temp,int sum) {
        if(sum>n) return;
        if(idx == 9) {
            if(sum == n && curr == k) {
                res.push_back(temp);
            }
            return;
        }
        if(curr<k) {
            temp.push_back(arr[idx]);
            combination(curr+1,k,idx+1,size,n,arr,temp,sum+arr[idx]);
            temp.pop_back();
        }
        combination(curr,k,idx+1,size,n,arr,temp,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        vector<int> temp;
        
        for(int i=1;i<=9;i++)
            arr[i-1] = i;
        
        combination(0,k,0,9,n,arr,temp,0);
        
        return res;
    }
};