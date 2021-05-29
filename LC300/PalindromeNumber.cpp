#include<bits/stdc++.h>
using namespace std;


    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int temp = x, rev = 0, t, n1, n2;
        
        // reversing x
        while(temp!=0){
            t = temp%10;
            temp /= 10;
            if(rev > INT_MAX/10 || (rev==INT_MAX/10 && t>7))
                return false;
            rev = rev*10 + t;
        }
        
        n1 = x, n2 = rev;
        
        if(log10(n1)!=log10(n2))
            return false;
        
        // checking both from r to l
        /*while(n1>0 && n2>0){
            if(n1%10 != n2%10)
                return false;
            n1 /= 10;
            n2 /= 10;
        }*/
        if(n1!=n2)
            return false;
        return true;
        
    }

int main(){
	
	int _, n, t;
	cin>>_;
	
	while(_--){
		cin>>n;
		cout<<isPalindrome(n)<<endl;
		cout<<(int)log10(n)<<endl;
	}
	
	return 0;
	
}
