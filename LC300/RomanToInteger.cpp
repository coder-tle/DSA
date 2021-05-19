class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hmap = { {'I', 1},
                                          {'V', 5},
                                          {'X', 10},
                                          {'L', 50},
                                          {'C', 100},
                                          {'D', 500},
                                          {'M', 1000}
            
        };   
        
        
        int res = 0;
        int n = s.size();
        for(int i = 0; i<s.size(); i++){
            if(i<n && s[i]=='I'){
                if(i+1<n && s[i+1]=='V'){
                    res += 4;
                i++;
                }
                else if(i+1<n && s[i+1]=='X'){
                    res += 9;
                i++;}
                else{
                res += hmap[s[i]];
            }
            }
            else if(i<n && s[i]=='X'){
                if(i+1<n && s[i+1]=='L'){
                    res += 40;i++;}
                else if(i+1<n && s[i+1]=='C'){
                    res += 90;
                i++;}
                else{
                res += hmap[s[i]];
            }
            }
            else if(i<n && s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    res += 400;i++;}
                else if(i+1<n && s[i+1]=='M'){
                    res += 900;
                i++;}
                else{
                res += hmap[s[i]];
            }
            }else{
                res += hmap[s[i]];
            }
            
        }
        return res;
    }
};
