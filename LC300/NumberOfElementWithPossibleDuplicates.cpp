#include<bits/stdc++.h>
using namespace std;




// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetRightPosition(int A[], int l, int r, int key)
{
	int m;

	while( r - l > 1 )
	{
		m = l + (r - l)/2;

		if( A[m] <= key )
			l = m;
		else
			r = m;
	}

	return l;
}

// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
	int m;

	while( r - l > 1 )
	{
		m = l + (r - l)/2;

		if( A[m] >= key )
			r = m;
		else
			l = m;
	}

	return r;
}

int CountOccurances(int A[], int size, int key, int lPtr, int rPtr)
{
	// Observe boundary conditions
	//int left = GetLeftPosition(A, -1, size-1, key);
	//int right = GetRightPosition(A, 0, size, key);
	
	
	int left = GetLeftPosition(A, lPtr-1, rPtr, key);
	int right = GetRightPosition(A, lPtr, rPtr+1, key);
	
	// What if the element doesn't exists in the array?
	// The checks helps to trace that element exists
	return (A[left] == key && key == A[right])?
		(right - left + 1) : 0;
}

int main(){
	int _;
	cin>>_;
	
	
	while(_--){
		int n;
		cin>>n;
		
		
		int arr[n];
		
		for(int i = 0; i<n; i++)
			cin>>arr[i];
		
		//cout<<"Number of occurance of 0 :"<<CountOccurances(arr, n, 0, 2, n-2)<<endl;
		
		vector<int> a = {2, 3,4};
		cout<<a[0]<<a[1]<<a[2]<<endl;
		
	}
	return 0;
}

