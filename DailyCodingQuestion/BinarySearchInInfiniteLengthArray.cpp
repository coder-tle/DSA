#include<bits/stdc++.h>
using namespace std;

/*
	1. arr[high] < target
			low = high
			high *= 2
	2. arr[high] >= target
			return current bounds
 
 */
 
 
 
 
 
void findBound(int arr[] , int * low, int * high, int target){
	*low = 0, *high = 1; // no need to maintain low indices , since low will be always = high/2;
	
	while( true ) // determine condition ??
	{
		if(arr[*high] < target){
			*low = *high;
			*high *= 2;
			
			
		}
		else if(arr[*high] >= target){
			break;
		}
	}
	return ;
}



// In this problem assume length is unkown to get 
// infinte length condition



int binarySearch(int arr[],  int target){
	
	int low, high;
	findBound(arr, &low, &high, target);
	int mid = low + (high - low)/2;
	int pos = -1;
	
	while( low<=high) // ?? determine condition
	{
		mid = low + (high - low)/2; // mid was not getting updated too.
		if(arr[mid] < target){
			low = mid+1;
			
		}
		else if(arr[mid] > target){
			high = mid-1;
		}
		else if( arr[mid] == target)
		return mid; // error was returning pos here 
	}
	
	return -1;
	
	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
	cin>>arr[i];
	cout<<"Enter target element to be found : ";
	int target;
	cin>>target;
	
	cout<<"Element found at index : "<<binarySearch(arr, target);
	
	return 0;
}
