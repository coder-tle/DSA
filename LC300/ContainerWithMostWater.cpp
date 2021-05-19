class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0, temp;
        
        while(i<j){
            temp = min(height[i], height[j])*(j-i);
            res  = max(res, temp);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};
