class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1, maxLen = 1;
        int l , r;
        string temp, res;
        int n = s.size();
        
        if(n==0)
            return "";
        //temp = res = s[0]; // what is its use ??
        
        // for odd size 
        for(int i  = 1; i<n-1;i++){
            len = 1;
            temp = "";
            //temp += s[i]; // what is need of this ??
            l = i-1;
            r = i+1;
            while(  (l>=0 && r<n) && (s[l] == s[r]) ){
                l--;
                r++;
                len += 2;
            }
            if(len > maxLen){
                maxLen = len;
                //if(l < 0 || r>=n)
                {
                    l++;
                    r--;
                }
                temp = "";
                for(int i = l; i<=r; i++)
                    temp += s[i];
                res = temp;
            }
        }
        
        // for even size
        for(int i = 0; i<n-1; i++){
            l = i;
            r = i+1;
            len = 0;
            
            while(  (l>=0 && r<n) && (s[l]==s[r])   )
            {
                l--;
                r++;
                len += 2;
            }
            if(len > maxLen){
                maxLen = len;
                //if(l < 0 || r>=n)
                {
                    l++;
                    r--;
                }
                temp ="";
                for(int i = l; i<=r; i++)
                    temp += s[i];
                res = temp;
            }
        }
        if ( maxLen == 1)
            res = s[0];
        return res;
    }
};
