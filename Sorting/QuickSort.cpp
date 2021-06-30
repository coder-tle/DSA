#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[], int p, int r){
	int pivotValue = arr[r];
	int i = p-1;
	
	for(int j = p ; j<r; j++){
		if(arr[j]<pivotValue){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i+1], arr[r]);
	
	return i+1;
	
}


void QuickSort(int arr[], int p, int r){
	if(p<r){
		int pivotIndex = Partition(arr, p, r);
		QuickSort(arr, p, pivotIndex -1 );
		QuickSort(arr, pivotIndex+1, r);
	}
	
}





void Display(int arr[], int l, int r){
	for(int i = l; i<=r; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
}

int main(){
	
	int tc;
	cin>>tc;
	
	while(tc--){
		int n;
		cin>>n;
		
		int arr[n];
		for(int i =0; i<n; i++)
			cin>>arr[i];
		QuickSort(arr, 0, n-1);
		
		Display(arr, 0, n-1);
	}
	
}
