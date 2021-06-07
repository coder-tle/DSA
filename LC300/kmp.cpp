#include<bits/stdc++.h>
using namespace std;

void preCompute(int pArr[], string s){

	pArr[0] = 0;
	int i = 1, j = 0, n = s.size();
	
	for(i = 1; i<n; i++){
		if(s[j]==s[i]){
			//cout<<"value of j at i : "<<i<<" "<<j<<endl;
			pArr[i] = j+1;
			j++;
		}
		else {
			while(j!=0 && s[j] != s[i]){
				j = pArr[j-1];
				//cout<<"Value of J in loop "<<j<<endl; 
			}
			if(s[j]==s[i]){
				//cout<<"value of j at i : "<<i<<" "<<j<<endl;
				pArr[i] = j+1;
				j++;}
			else if(j ==0 && s[j]!=s[i])
				pArr[i] = 0;
		}
	}
}

int KMP(string s, string p, int pArr[]){
	int nP = p.size(), nS = s.size();
	int j = 0, i = 0;
	
	for(i = 0; i<s.size(); i++){
		if(p[j] == s[i])
				j++;
		else{
			while(j!=0 && p[j] !=s[i])
				j = pArr[j-1];
			if(p[j] == s[i])
				j++;
		}
		if(j==p.size()){
			//cout<<"i : "<<i<<"\n";
			//cout<<"From for loop Value of j : "<<j<<endl;
			//return i-p.size() -1;
			return i + 1 - j;
		}
	}
//	cout<<"i :"<<i<<" j: "<<j<<endl;
//	int nP = p.size();
	cout<<nP<<endl;
	if(j == p.size()){
			//cout<<"Value of j : "<<j<<endl;
			return (i-(int)p.size());
		}
	return -1;
}

int main(){
	
	string s, p;
	cin>>s>>p;
	
	int n = p.size();
	int pArr[n];
	
	preCompute(pArr, p);
	
	for(int i = 0; i<n; i++)
	//	cout<<pArr[i]<<" ";
	cout<<endl;
	
	if(KMP(s, p, pArr) != -1){
		cout<<"Pattern found at index : "<<KMP(s,p, pArr)<<"\n";
	}
	else 
		cout<<"Pattern not found\n";
	
	return 0;
}
