class Solution {
public:
    
    int binarySearch(vector<int>& nums, int l , int r, int target){
        int mid;
        
        while(l<=r){
            mid = l + (r-l)/2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
                r = mid-1; // ?
            else if(target>nums[mid])
                l = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n-1, mid, pivot ;
        int result = 0;
        
        if(n==1)
        {
            if(nums[0]==target)
                return 0;
            else 
                return -1;
        }
        else if(n==2){
            if(target==nums[0])
                return 0;
            else if(target == nums[1])
                return 1;
            return -1;
        }
        else if(n>2){
            l = 0, r = n-1;
            while(l+1<r){
                mid = l + (r-l)/2;
                if(nums[l]<nums[mid])
                    l = mid;
                else if(nums[l]>nums[mid])
                    r = mid;
                
            }
            if(nums[l]<nums[r])
                pivot = l;
            else if(nums[l]>nums[r])
                pivot = r;
            l = 0, r = n-1;
            
            if(nums[l]<=target && target<=nums[pivot-1])
                result = binarySearch(nums, l, pivot-1, target);
            else// does not matter if (nums[pivot]<=target && target<=nums[r]) // ?
                result = binarySearch(nums, pivot, r, target);
            
            return result;
        }
        return -1;
    }
};

/*
//#1     6,  7,  0,  1,  2   target = 3
         0    1  2   3  4     mid = 1
                 |  
              pivot =  2
             
*/             
              
