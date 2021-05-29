class Solution {
public:
    
    int minSizeString(vector<string>& strs){
        int n = strs.size();
        int size_ = INT_MAX;
        for(int i = 0; i<n; i++){
            //   size_ = min(size_, strs[i].size());
            if(strs[i].size() < size_)
                size_ = strs[i].size();
        }
        return size_;
    }
    
    bool checkPrefix(vector<string>& strs, int i){
        int n = strs.size();
        char t = strs[0][i];
        
        for(int j = 0; j<n; j++){
            if(strs[j][i]!= t)
                return false;
            
        }
        return true;
    }
    
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0)
            return "";
        string prefix = "";
        bool commonToAll = false;
        int minSize = minSizeString(strs);
        for(int i = 0; i<minSize; i++){
            commonToAll = checkPrefix(strs,i);
            if(commonToAll)
                prefix += strs[0][i];
            else
                break;
            
        }
        return prefix;
    }
};
