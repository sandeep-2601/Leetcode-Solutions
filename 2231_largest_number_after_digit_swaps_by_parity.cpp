/*
    Problem -> https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
    T.C  -> O(N) + O(N²) + O(N)
    S.C  -> O(N)
    where N is the number of digits present in num
*/

class Solution1 {
public:
    int largestInteger(int num) {
        
        vector<int> digits;
        int n;
        
        while(num != 0) {
            digits.push_back(num%10);
            num /= 10;
        }
        
        n = digits.size();
        
        for(int i=n-1;i>=1;i--) {
            
            for(int j=i-1;j>=0;j--) {
                if(((digits[i]&1) == (digits[j]&1)) && (digits[i] < digits[j]) ) {
                    swap(digits[i],digits[j]);
                } 
            }
        }
        
        for(int i=n-1;i>=0;i--)
            num = num*10 + digits[i];
        
        return num;
    }
};

// T.C  -> O(N) + O(NlogN) + O(N)
// S.C  -> O(N)
// where N is the number of digits present in num
class Solution2 {
public:
    int largestInteger(int num) {
        
        vector<int> even_digits;
        vector<int> odd_digits;
        int n,t,temp = num;
        int ei = 0,oi = 0,val = 0,c=0;
        
        while(num != 0) {
            t = num%10;
            (t&1) ? odd_digits.push_back(t) : even_digits.push_back(t);
            num/= 10;
        }
        
        sort(even_digits.begin(),even_digits.end());
        sort(odd_digits.begin(),odd_digits.end());
        
        while(temp != 0) {
            t = temp%10;
            val = (t&1) ? odd_digits[oi++] : even_digits[ei++];
            num += val*pow(10,c);
            temp /= 10;
            c++;
        }
        
       
        return num;
    }
};