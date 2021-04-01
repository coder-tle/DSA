#include<bits/stdc++.h>
using namespace std;


void display(set<int> s){
	
		set<int> :: iterator it = s.begin();
		
		for(; it!=s.end(); it++){
			cout<<*it<<" ";
			
		}
		cout<<endl;
}
void displayUnordered(unordered_map<int, set<int> > hmap){
		
		cout<<"Displaying the unordered map\n";
		unordered_map<int, set<int> >::iterator itrH;
		
		itrH = hmap.begin();
		set<int>::iterator itrS;
		
		//cout<<itrH->first<<endl;
		
		
		for(; itrH != hmap.end(); itrH++){
			cout<<"Key: "<<itrH->first<<"\t";
			itrS = itrH->second.begin();
			cout<<"Values : ";
			for(; itrS!=itrH->second.end(); itrS++){
				cout<<*itrS<<" ";
			}
			
		}
		
}
int main(){
		
		unordered_map<int, set<int>> hmap;
		
		set<int> s1 , s2, s3;
		
		s1.insert(1);
		
		s1.insert(2);
		s1.insert(3);
		s1.insert(4);
		s1.insert(5);
		s1.insert(6);
		display(s1);
		
		
		s2 = s1;
		

		s2.insert(0);
		s2.insert(-1);
		
		display(s2);
		display(s1);
		
		
		hmap[0] = s1;
		hmap[1] = s2;
		
		displayUnordered(hmap);
		
		return 0;
	
}
