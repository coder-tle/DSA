 int findMaxDiff(int arr[], int n)
    {
      //Your code here
        if(n<=1)
            return 0;
        
        int min_ = arr[0], result = 0;
        
        for(int i = 1; i<n; i++){
            result = max(arr[i]-min_, result);
            if(arr[i]<min_)
                min_ = arr[i];
        }
        
        
        
       return result;
    }
    
