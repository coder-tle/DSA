#include<bits/stdc++.h>
using namespace std;

    
    string reverseString(string s){
    int lPtr = 0, rPtr = s.size() -1;
	//cout<<"\n"<<num<<endl;
    char t;
	while(lPtr<rPtr){
	t = s[rPtr];
	s[rPtr] = s[lPtr];
	s[lPtr] = t;
	lPtr++;
	rPtr--;
	}
    return s;
    }
    
    // integer to string in reverse order
    string numberToString(int x){
        string num = "", res;
        int r, temp = x;
        char t;
        
        while(temp>0){
	    r = temp%10;
	    t = '0'+r;
	    num += t;
	    temp = temp/10;
	    }
        
        return reverseString(num);
        
        
    }
    bool isGreater(string i, string m){
        int nI = i.size(), nM  = m.size();
        if(nI < nM)
            return false;
        else if(nI==nM){
            if(i[0]<m[0])
                return false;
            
        }
        return true;
    }
    
   int stringToNumber(string s){
        int i = s.size()-1;
        int multiplier = 1;
        int t, res = 0;
        while(i>=0){
            t = s[i] - '0';
            res += t*multiplier;
            multiplier *= 10;
            i--;
        }
        return res;
    }
    
    int reverse(int x) {
        bool negative = false;
        if(x<0){
            negative = true;
            x = abs(x);
        }
        
        int maxNumber = 0x7FFFFFFF;
        string maxNumberString = numberToString(maxNumber);
        string inputString = numberToString(x);
        cout<<inputString<<endl;
        string reverseOfInput = reverseString(inputString);
        cout<<reverseOfInput<<endl;
        if(isGreater(reverseOfInput,maxNumberString)){ 
            // reverse of input is greater than maxNumber string
            // return 0;
            return 0;
            
        }
        int result = stringToNumber(reverseOfInput);
        cout<<reverseOfInput<<endl;
        cout<<result<<endl;
        if(negative)
        return (    (-1)*result );
        return result;
        
    }

 /*int stringToNumber(string s){
        int i = s.size()-1;
        int multiplier = 1;
        int t, res = 0;
        while(i>=0){
            t = s[i] - '0';
            res += t*multiplier;
            multiplier *= 10;
            i--;
        }
        return res;
    }*/
int main(){
	
	
	cout<<reverse(-2147483412
);
/*	cout<<0x7FFFFFFF;
	
	int a = 0x7FFFFFFF;
	cout<<"\n"<<a;
	
	
	string num = "";
	
	int mod = 10^9;
	int temp = a;
	int q,r,d;
	char t;
	while(temp>0 && mod != 0){
		q = temp/mod;
		t = '0'+q;
		num += t;
		//temp = temp - q*(temp/mod); // this modulus
		temp = temp%mod;
		mod = mod/10;
		
	}

	// integer to string in reversed manner
	while(temp>0){
	r = temp%10;
	t = '0'+r;
	num += t;
	temp = temp/10;
	}
	
	
	// to reverse a string
	int lPtr = 0, rPtr = num.size() -1;
	cout<<"\n"<<num<<endl;

	while(lPtr<rPtr){
	t = num[rPtr];
	num[rPtr] = num[lPtr];
	num[lPtr] = t;
	lPtr++;
	rPtr--;
	}
	
//	cout<<"\n"<<num<<endl;

	//cout<<stringToNumber("123");
	*/
	
	return 0;
}
