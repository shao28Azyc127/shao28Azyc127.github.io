#include<bits/stdc++.h>

using namespace std;

int n,ans;
char s[100];
deque<char>stk;
struct Node{
    bool in;
    bool near;
    int number;}ne;


int main(){
    //freopen("game1.in","r",stdin);
    //freopen("game1.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>s[i];
   
        while(i>0&&s[i]==stk.back()){
        stk.pop_back();
       if(ne.near&&!ne.in){ans=ans+1+ne.number;
       }
        else if(!ne.near&&!ne.in){ans++;ne.number++;}
            else {ans++;}
        ne.near=true;
        ne.in=true;
    }
    
    
    stk.push_back(s[i]);
}


cout<<ans;
return 0;}
