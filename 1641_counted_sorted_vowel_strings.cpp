/*
    Problem -> https://leetcode.com/problems/count-sorted-vowel-strings/
    T.C ->  O(2^N)
*/

class Solution {
public:
    int count = 0;
    void vowelStrings(int s,int idx,int n,char arr[],string &str) {
        if(idx == n) {
            count++;
            return;
        }
        for(int i=s;i<5;i++) {
            str.push_back(arr[i]);
            vowelStrings(i,idx+1,n,arr,str);
            str.pop_back();
        }
        
    }
    int countVowelStrings(int n) {
        string str;
        char arr[] = {'a','e','i','o','u'};
        vowelStrings(0,0,n,arr,str);
        
        return count;
    }
};

// T.C O(N) 

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1,1,1,1,1};
        
        for(int i=2;i<=n;i++) {
            for(int j=3;j>=0;j--) {
                dp[j] = dp[j] + dp[j+1];
            }
        }
        
        return accumulate(dp,dp+5,0);
    }
};