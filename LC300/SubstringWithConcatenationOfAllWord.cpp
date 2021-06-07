#include<bits/stdc++.h>
using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {
	int wordLen = words[0].size();
	vector<int> indexes;
	int n = s.size();
	unordered_map<string, int> count;// seen;
	
	for(string word : words)
		count[word]++;
	
	int totalWords = words.size();
	
	for(int i=0; i<=n-totalWords*wordLen; i++){
		cout<<"Inside outermost for loop\n";
		unordered_map<string, int>seen;
		seen = count;
		int j;
		int countWord = 0;
		for(j = i ; j<n;j = j+wordLen){
			cout<<"Inside second for loop\n";
			string temp = "";
			for(int i2 = 0; i2<wordLen; i2++)
				temp += s[j+i2];
			
			if(count.find(temp)!=count.end()){
				cout<<"first comaprison using hashmap\n";
				seen[temp]--;
				countWord++;
				if(countWord==totalWords)
					break;
				//if(seen[temp]>count[temp]){
				//	cout<<"Inside if condition where count of word exceeds the desired\n";
				//	seen[temp]--;
				//	countWord--;
				//	break;
				//}
			}
			else
				break;
			
			}
		bool allPresent = true;	
		if(countWord==totalWords){
			//indexes.push_back(i);
			for(auto it = seen.begin(); it!=seen.end();it++)
			{
				if(it->second != 0){
					allPresent = false;
					break;
				}
			}
		}
		if(allPresent==true)
			indexes.push_back(i);
		/*
		if(count.size() == seen.size()){ // all words found
		   // cout<<"all distinct words found\n";
		   // cout<<"displaying all key value pair";
			//for(auto it = seen.begin(); it!=seen.end(); it++)
			   // cout<<it->first<<" "<<it->second<<endl;
			bool allPresent = true;
			for(auto it = count.begin(); it!=count.end(); it++){
				string key = it->first;
				int value = it->second;
			   
				if(seen.find(key)!=seen.end() ){
					if(seen[key] != value)
					{
						allPresent = false;
						break;
					}
				}else
				{
					allPresent = false;
					break;
				}
				
				
				//if(seen[key]!=value)
				//    allPresent = false;
			}
			if(allPresent)
				indexes.push_back(i);
				
				
			}*/
		//seen.clear();
		} // end of for loop
	return indexes;
}


int main(){
	int _;
	cin>>_;
	
	while(_--){
		string s;
		vector<string> words;
		int n;
		cout<<"Enter string ,number of words and words: \n";
		cin>>s>>n;
		string temp;
		for(int i = 0; i<n; i++){
			cin>>temp;
			words.push_back(temp);
		}
		vector<int> indexes = findSubstring(s, words);
		for(int i = 0 ; i<indexes.size(); i++)
			cout<<indexes[i]<<" ";
		cout<<endl;
	}
}
