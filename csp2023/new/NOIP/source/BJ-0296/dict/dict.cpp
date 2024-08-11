#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3003],smx[3003],smn[3003];
void stu(string &s){
    int cnt[30];
    for(int i=0;i<26;i++)cnt[i]=0;
    for(int i=0;i<m;i++){
        cnt[s[i]-'a']++;
    }
    s="";
    for(int i=0;i<26;i++){
        while(cnt[i]--){
            s+=char(i+'a');
        }
    }
    return;
}
void sotd(string &s){
    int cnt[30];
    for(int i=0;i<26;i++)cnt[i]=0;
    for(int i=0;i<m;i++){
        cnt[s[i]-'a']++;
    }
    s="";
    for(int i=25;i>=0;i--){
        while(cnt[i]--){
            s+=char(i+'a');
        }
    }
    return;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        smx[i]=smn[i]=s[i];
        sotd(smx[i]);
        stu(smn[i]);
    }
    for(int i=1;i<=n;i++){
        bool ans=1;
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            ans=ans&&(smn[i]<smx[j]);
        }cout<<ans;
    }
    
    return 0;
}
