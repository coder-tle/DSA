#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n){
	int temp, j;
	
	for(int i = 1; i<n; i++){
		
		temp = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j] >= temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	
}

void Display(int arr [], int n){
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
		int n;
		cout<<"Enter size of array : ";
		cin>>n;
		if(n == 0){
			cout<<"Array is empty\n";
			//return 0;
		}
			
		else if ( n > 0){
			int arr[n];
		cout<<"Enter element of array : \n";
		for(int i  = 0; i<n; i++)
			cin>>arr[i];
		
		cout<<"Array before sorting :\n";
		Display(arr, n);
		
		InsertionSort(arr, n);
		cout<<"Array after sorting : \n";
		Display(arr, n);
		
	}
		
		return 0;
}
