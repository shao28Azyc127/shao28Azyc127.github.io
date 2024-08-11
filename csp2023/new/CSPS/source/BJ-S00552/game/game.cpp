#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int cnt=0;
int rcnt[2000100];
void f(int l,int r){
    while(s[l]==s[r]){
        rcnt[r]=max(rcnt[r],rcnt[l-1]+1);
        if(l==1||r==n){
            return;
        }
        l--;r++;
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","r",stdout);
    memset(rcnt,0,sizeof rcnt);
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<n;i++){
        if(s[i]==s[i+1]){
            f(i,i+1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<rcnt[i]<<" ";
        cnt+=rcnt[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
