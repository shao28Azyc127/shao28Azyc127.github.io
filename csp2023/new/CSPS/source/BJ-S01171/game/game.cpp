#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
char s[N];
int n;
int ans=0;
bool st[N]={false};
void ipt(){
    scanf("%d",&n);
    scanf("%s",s);
}
bool check(int l,int r){
    for(int i=l;i<=r;i++) st[i]=false;
    while(1){
        bool flg=false;
        for(int i=l;i<=r;i++){
            int idx=-1;
            for(int j=i+1;j<=r;j++) if(st[j]==false&&s[i]==s[j]){idx=j;flg=true;}
            if(idx==-1) continue;
            else{
                //cout<<"dis:"<<st[i]<<"and"<<st[idx]<<';';
                st[i]=true;
                st[idx]=true;
            }
        }
        if(flg==false) break;
    }
    for(int i=l;i<=r;i++) if(st[i]==false) return false;
    //cout<<l<<'~'<<r<<endl;
    //for(int i=l;i<=r;i++) cout<<s[i];
    //cout<<endl;
    return true;
}
void solve(){
    int lenn=strlen(s);
    //for(int i=0;i<lenn;i++) printf("%c",s[i]);
    //cout<<endl;
    for(int l=0;l<lenn;l++){
        for(int r=l;r<lenn;r++){
            if(l==r) continue;
            if(check(l,r)) ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ipt();
    solve();
    return 0;
}