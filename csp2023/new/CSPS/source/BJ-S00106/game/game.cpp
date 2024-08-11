#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string s;
    int l;
    cin>>l;
    int cnt=0;
    stack<char>temp;
    cin>>s;
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
          	while(temp.size()!=0){
            	temp.pop();
			}
		    if(sizeof(temp)!=0&&temp.top()!=s[j]){
		    	temp.push(s[j]);
		    }else{
		    	temp.pop();
		    }
			
		}
		if(temp.empty()){
		     cnt++;
		}
    }
    cout<<cnt;
    
    return 0;
}