// kamisako

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// int rd(){
//     int x=0,f=0;char ch=getchar();
//     for(;ch<'0'||ch>'9';ch=getchar())f|=(ch=='-');
//     for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+ch-'0';
//     return f?-x:x;
// }

const int maxn=3010;
int n,m;
string s[maxn];
string ms,mss;
int buk[maxn][26];
int mbk[26];

inline bool cmp(string& s1,string& s2){
    for(int i=0;i<m;++i){
        if(s1[i]!=s2[i])return s1[i]<s2[i];
    }
    return 0;
}

inline bool cmmp(int s1){
    int l=0,r=25;
    // cout<<s[s1]<<"\n";
    for(int i=0;i<m;++i){
        while(buk[s1][l]==0)l++;
        while(mbk[r]==0)r--;
        // cout<<(char)(l+'a')<<" "<<(char)(r+'a')<<"\n";
        if(l!=r)return l<r;
    }
    return 0;
}

inline bool cmmmp(int s1,int s2){
    int l=0,r=25;
    // cout<<s[s1]<<"\n";
    for(int i=0;i<m;++i){
        while(buk[s1][l]==0)l++;
        while(buk[s2][r]==0)r--;
        // cout<<(char)(l+'a')<<" "<<(char)(r+'a')<<"\n";
        if(l!=r)return l<r;
    }
    return 0;
}

int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n==1){cout<<1;return 0;}
    else if(m==1){
        ms.resize(m),mss.resize(m);
        for(int i=0;i<m;++i)ms[i]=mss[i]='z';
        for(int i=1;i<=n;++i){
            cin>>s[i];
            if(cmp(s[i],mss))ms=mss,mss=s[i];
            else if(cmp(s[i],ms))ms=s[i];
        }
        for(int i=1;i<=n;++i){
            if(s[i]!=mss)cout<<0;
            else cout<<1;
        }
    }else{
        // ms.resize(m),mss.resize(m);
        // for(int i=0;i<m;++i)ms[i]=mss[i]='z';
        // count
        for(int i=1;i<=n;++i){
            cin>>s[i];
            // if(cmp(s[i],ms))ms=s[i];
            for(int j=0;j<m;++j)buk[i][s[i][j]-'a']++;
        }
        // cout<<ms<<"\n";
        // for(int i=0;i<m;++i){
        //     mbk[ms[i]-'a']++;
        // }
        // for(int i=0;i<=25;++i)cout<<(char)(i+'a')<<" "<<mbk[i]<<"\n";
        for(int i=1;i<=n;++i){
            // cout<<cmmp(i);
            // cmmp(i);
            bool fl=1;
            for(int j=1;j<=n;++j){
                if(i==j)continue;
                if(!cmmmp(i,j)){fl=0;break;}
            }
            cout<<fl;
        }
    }

    return 0;
}

// u'r right, but genshin