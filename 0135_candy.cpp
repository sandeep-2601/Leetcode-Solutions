/*
https://leetcode.com/problems/candy/
*/

/*
T.C O(N)
S.C O(N)
*/

class Solution {
public:

    void fill(int n,int arr[]) {
        for(int i=0;i<n;i++)
            arr[i] = 1;
    }

    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int res = 0;
        int left[n];
        int right[n];
        
        fill(n,left);
        fill(n,right);
        
        for(int i=1;i<n;i++) {
            if(ratings[i]>ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        
        for(int i=n-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1])
                right[i] = right[i+1] + 1;
        }
        
        for(int i=0;i<n;i++) {
            res += max(left[i],right[i]);
        }
            
        return res;
    }
};