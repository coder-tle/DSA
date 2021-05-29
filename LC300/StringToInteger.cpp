class Solution {
public:
    int myAtoi(string s) {
        
        int res = 0, n = s.size(), i = 0;
        bool negative = false;
        bool overflow = false;
        while(  i<n && s[i] == ' '  ){
            i++;
        }
        
        if(i<n && s[i]=='-'){
            negative = true;
            i++;
        }
        else if(i<n && s[i] == '+')
            i++;
        int t;
        while(i<n && s[i]<='9'&& s[i]>='0'){
            t = s[i] - '0';
            
            if(res>INT_MAX/10 || (res==INT_MAX/10 && t > 7) )
            {
                overflow = true;
                break;
            }
            res  = res*10 + t;
            i++;
        }
        
        if(overflow == true){
            if(negative)
                return INT_MIN;
            else
                return INT_MAX;
        }
        
        if(negative )
            return (-1)*res;
        return res;
            
            
    }
};
