#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+3;

char s[maxn];
int n;

int check(int st,int ed){
    int sz=0;
    stack<int> c;
    c.push(s[(st)]-'a');
    for(int i=st;i<ed;i++){
        if(sz==0){
            sz++;
            c.push(s[i]-'a');
            continue;
        }
        if(s[i]-'a'==c.top()){
            c.pop();
            sz--;
        }else{
            sz++;
            c.push(s[i]-'a');
        }
    }
    if(sz){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+2;j<=n;j+=2){
            res+=check(i,j);
        }
    }
    cout<<res;
    return 0;
}
