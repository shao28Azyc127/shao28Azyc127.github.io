#include<iostream>
#include<stack>
using namespace std;
string s;
int l;
stack<char> a;
inline bool Check(int l,int r){
    while(a.size()) a.pop();
    for(int i=l;i<=r;i++){
        if(!a.size()) a.push(s[i]);
        else{
            char c=a.top();
            if(s[i]!=c){
                a.push(s[i]);
            }
            else{
                a.pop();
            }
        }
    }
    /*if(a.size()==0){
        for(int i=l;i<=r;i++) cout<<s[i];
        cout<<endl;
    }*/
    return a.size()==0;
}
long long ans=0;
int n;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            ans+=Check(i,j);
        }
    }
    cout<<ans;
    return 0;
}