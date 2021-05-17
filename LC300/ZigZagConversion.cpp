class Solution {
public:
    
    
    string convert(string s, int numRows) {
         int i, j, step;
        string res;
        if(numRows == 1)
            return s;
        // First row
        j = 0; step = 2*(numRows-1);
        while(j<s.size()){
            res.push_back(s[j]);
            j += step;
        }
        
        // Intermediate row
        for(i=1;i<numRows-1;i++){
            j = i;
            step = 2*(numRows-1-i);
            while(j<s.size()){
                res.push_back(s[j]);
                j+=step;
                step = abs(2*(numRows-1) - step);
            }
        }
        
        // Last row
        j = numRows-1; step = 2*(numRows-1);
        while(j<s.size()){
            res.push_back(s[j]);
            j+= step;
        }
        return res;
    }
    
    // P    A   Y   P   A   L   I   S   H   I   R   I   N   G
    // 0   1   2   3   4   5   6   7   8   9   10  11  12  13
     //                                               ^
// j = 13 , numRows = 4 , step =  4, 2*(numRows-1) = 6
            // P  I  N
           //   A L S I  G
           //
           //P I
           /*    string convert(string s, int numRows) {
        int i, j, step, n = numRows;
        string res;
        for(i=0; i<n-1;i++){
            j = i;
            step = (n-1-i)*2;
            while(j<=s.size()-1){
                res.push_back(s[j]);
                j+= step;
            }
        }
        step = 2*(n-1);
        j = n-1;
        while(j<=s.size()-1){
                res.push_back(s[j]);
                j+= step;
            }
        
        return res;
    }
*/
};
