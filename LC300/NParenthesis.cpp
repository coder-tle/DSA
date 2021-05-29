#include<bits/stdc++.h>
using namespace std;



vector<string> generateParenthesis(int n) {
        vector<string> tRes, res;
        tRes.push_back("()");
        
        for(int i = 2; i<=n; i++){
            string tCenter, tLeft, tRight;
            
            for(int i2 = 0; i2 < tRes.size(); i2++){
				//cout<<tRes[i2]<<endl;
                tCenter = '('+tRes[i2]+')';
                tRight = "()"+tRes[i2];
                tLeft = tRes[i2]+"()";
                //cout<<tRight<<" "<<tLeft<<endl;
                if(tRight!=tLeft){
                    res.push_back(tRight);
                }
                res.push_back(tCenter);
                res.push_back(tLeft);
                
                
                
            }
            if(i%2==0 && i!=2){ // special case
				string temp = "";
				for(int i3 = 1; i3<=i/2;i3++){
					temp = temp + '(';
				}
				
				for(int i3 = 1; i3<=i/2;i3++){
					temp = temp + ')';
				}
				temp += temp;
				res.push_back(temp);
				cout<<temp<<endl;
			}
            tRes = res;
            res.clear();
        }
        return tRes;
    }


int main(){
	
	int _;
	cin>>_;
	
	while(_--){
		int n;
		cin>>n;
		
		vector<string> result = generateParenthesis(n);
		
		
	}
	
	
	
	
}
