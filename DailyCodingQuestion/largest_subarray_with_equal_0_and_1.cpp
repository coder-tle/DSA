#include<bits/stdc++.h>
using namespace std;

void largestSubarrayWithEqual_0_1(int arr[], int n){
		int maxLen = -1, startIdx = -1;
		
		for(int i = 0; i<n; i++){
			int sum_ = 0;
			for(int j = i; j<n; j++){
				if(arr[j] == 1)
					sum_+=1;
				else if(arr[j] == 0)
					sum_ -= 1;
				
				if((sum_ ==0) && (j-i+1) > maxLen){
						
						maxLen = j-i+1;
						cout<<"MaxLen updated : "<<maxLen<<"\n";
						startIdx = i;
					}
			}
		}
		
		if(maxLen != -1)
		cout<<"Subarray starts at "<<startIdx<<" length : "<<maxLen<<endl;
		else
		cout<<"No such subarray exists\n";
	}

int main(){
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	
	int arr[n];
	for(int i = 0; i<n; i++)
		cin>>arr[i];
	
	largestSubarrayWithEqual_0_1(arr, n);
	return 0;
	
	
}
