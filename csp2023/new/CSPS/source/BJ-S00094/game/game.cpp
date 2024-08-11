#include<bits/stdc++.h>
using namespace std;
string s[10001];
int n;
bool nt[10001]=0;
bool check(int l,int r){
    int cnt=r-l+1;
    while(cnt){
        int size1=cnt;
        for(int i=l;i<r;i++){
            if(s[i]==s[i+1]&&s[i]!='*')
                cnt-=2;
                s[i]=s[j]='*';
        }
    }
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]==s[i]+1){
            nt[i]=nt[i+1]=1;
            cnt+=2;
        }
    }
    cout<<n;
    return 0;
}
