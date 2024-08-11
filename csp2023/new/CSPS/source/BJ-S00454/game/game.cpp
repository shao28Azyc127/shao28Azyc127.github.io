#include<bits/stdc++.h>
using namespace std;
int ck(string s,int l,int r){
    queue<char>q,q2;
    bool f=1;
    for(int i=l;i<r;i++){
        if(!q.empty()){
            if(s[i]==q.front())q.pop();
            else{
                q.push(s[i]);
            }
        }else{
            q.push(s[i]);
        }
    }
    char c;
    while(f){
        f=0;
        while(!q.empty()){
            c=q.front();
            q.pop();
            if(q.empty()){
                q2.push(c);
                break;
            }
            if(q.front()==c){
                q.pop();
                f=1;
            }else{
                q2.push(c);
            }
        }
        while(!q2.empty()){
            q.push(q2.front());
           // cout<<q2.front();
            q2.pop();
        }
       // cout<<endl;
    }
    if(q.empty())return 1;
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    string s,s2;
    cin>>n>>s;
    int ln=s.size(),ans=0;
    for(int j=2;j<=ln;j+=2){
        for(int i=0;i+j<=ln;i++){
            ans+=ck(s,i,i+j);
        }
    }
    cout<<ans;
    return 0;
}
