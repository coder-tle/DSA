class Solution {
public:
    string intToRoman(int x) {
        int arr[13] = { 1,4, 5,9, 10, 40, 50, 90, 100,400, 500, 900, 1000};
    
        
			unordered_map<int, string> hmap1 = { {1, "I"},{4,"IV"}, 
											  {5,"V"},{9,"IX"},
											  {10, "X"},{40, "XL"},
											  {50, "L"},{90, "XC"},
											  {100, "C"},{400, "CD"},
											  {500, "D"}, {900, "CM"},
											  {1000, "M"}
				
			};
        
        /*unordered_map<int, string> spl = {  {4,"IV"}, 
                                          {9,"IX"},
                                          {40, "XL"},
                                          {90, "XC"},
                                          {400, "CD"},
                                          {900, "CM"}
                                               
        };
        
        unordered_map<int, string> hmap1 = { {1, "I"},
                                          {5,"V"},
                                          {10, "X"},
                                          {50, "L"},
                                          {100, "C"},
                                          {500, "D"},
                                          {1000, "M"}
            
        };*/
        int temp,  d, i = 12;
        string res = "";
        
        while( x>0 && i>=0 ){
            //d = x/hmap1[arr[i]];
             d = x/arr[i];
            if(d>0){
                //temp = d*hmap1[arr[i]];
                //temp = d*arr[i];
                //if(temp == 40 || temp == 90 || temp == 400 || temp == 900){
                //    res += spl[temp];
                //}
                //else{ // not special case
                    for(int i2 = 1; i2<=d; i2++)
                        res += hmap1[arr[i]];
                //}
            
            }
            //x = x%hmap1[arr[i]];
            x = x%arr[i];
            
           // if(x==4 || x==9){
             //   res += spl[x];
               // x = 0;
            //}
            i--;
        }
        
        return res;
        
        
        
    }
};
