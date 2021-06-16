class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        vector<int> result(num1.size()+num2.size(),0);
        string p="";
        for(int i = num1.size()-1; i>=0; i--){
            int op1 = num1[i]-'0';
            for(int j = num2.size()-1; j>=0; j--){
                int op2 = num2[j]-'0';
                int mul = op1*op2 + result[i+j+1] ;
                
                result[i+j] += mul/10;
                result[i+j+1] = mul%10;
                
            }
        }
        
        
        for(int i = 0; i<num1.size()+num2.size(); i++){
            if(!(p.size()==0 && result[i]==0)){
                //p += (char)('0'+result[i]);
                
                //cout<<result[i]<<" ";
                char t = '0'+result[i];
                //cout<<"t : "<<t<<endl;
                
                p.push_back(t);
            }
        }
        if(p.size()==0)
            return "0";
        return p;
        
        /*
        long long finalResult = 0, result = 0, multiplier = 1, carry = 0, temp, temp2, temp3, m=1 ;
                
        for(int i = num1.size()-1; i>=0; i--){
            carry = 0, temp = num1[i]-'0', result = 0;
            m = 1;
            for(int j = num2.size()-1; j>=0; j--){ // ??
                temp2 = num2[j]-'0';
                temp3 = temp2*temp + carry;
                
                carry = temp3/10;
                temp3 = temp3%10;
                temp3 = temp3*m;
                result += temp3; //??
                m = m*10;
            }
            if(carry != 0)//?? 
                result = carry * m+result;
            // result  contains value of one row
            
            result = result * multiplier;
            finalResult += result;
            
            multiplier = multiplier * 10;
        }
    
    
    temp = finalResult;
    string output = "";
    int t  ;
    while(temp){
        t = temp%10;
        temp = temp/10;
        output += (t+'0');
    }
    reverse(output.begin(), output.end());
    
    return output;
    */
    }
};
