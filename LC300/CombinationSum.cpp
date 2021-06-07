class Solution {
public:
    vector<vector<int>> result;
    
    void helperCombination(vector<int> candidates, int target, vector<int> combination, int start){
        if(target<0)
            return;
        if(target==0){
            result.push_back(combination);
            return;
        }
        for(int i = start; i<candidates.size(); i++){
            combination.push_back(candidates[i]);
            helperCombination(candidates, target-candidates[i], combination, i); // if i+1, then multiple usage of same coin will be not possible, 
																																		// each coing can be used once
            combination.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        helperCombination(candidates, target, combination, 0);
        return result;
    }
};

/*
#1      2   3   6   7
        0   1   2   3
2       /
4      /|
6     
8    
*/
