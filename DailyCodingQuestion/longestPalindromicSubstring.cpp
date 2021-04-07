#include<bits/stdc++.h>
using namespace std;

void longestPalindromicSubstring(string str){
		
		int len = str.length();
		int low, high, maxLength = 1, start = 0;
		// check odd length
		for(int i = 1; i<len; i++){
			
			low = i-1;
			high = i;
			// maxLength = 1, start = 0;
			while( low >= 0 && high < len && str[low]==str[high]){
				if(high-low+1 > maxLength){
					start = low;
					maxLength = high - low + 1;
				}
				--low;
				high++;
			}
			
			
			low = i-1;
			high = i+1;
			
			while(low >=0 && high <len && str[low] == str[high]){
				if(high - low + 1 > maxLength){
					start = low ;
					maxLength = high - low + 1;
				}
			}
			--low;
			++high;
		}
	cout<<"Longest palindrome substring is : ";
	
	for(int i = start; i< start+maxLength; i++)
		cout<<str[i];
		cout<<endl;
}


int main(){
	
		string str;
		getline(cin, str);
		cout<<"Input received"<<endl;
		longestPalindromicSubstring(str);
		return 0;
}
