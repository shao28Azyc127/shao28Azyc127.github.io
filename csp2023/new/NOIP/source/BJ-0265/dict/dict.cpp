/*you can do it*/
#include<bits/stdc++.h>
#define fr(ii,xx,yy) for(int ii=xx;ii<=yy;ii++)
#define rf(ii,xx,yy) for(int ii=xx;ii>=yy;ii--)
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define pt printf
inline void rd(){}template<typename T,typename...args>inline void rd(T&x,args&...y){char ch;bool f=0;for(ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')f=1;for(x=0;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';if(f)x=-x;rd(y...);}
using namespace std;
const int N=3e3+33;
string s[N];
int n,m;int pre[N],suf[N];
int get(int i,int j){
    if(!i||!j)return i+j;
    return s[i]<s[j]?i:j;
}
//bucket sort speed!!!
void Sort1(string&s){
    int cnt[30]={0};
    fr(i,0,s.length()-1){
        cnt[s[i]-'a']++;
    }
    int it=-1;
    fr(i,0,25){
        while(cnt[i]--){
            s[++it]=i+'a';
        }
    }
}void Sort2(string&s){
    int cnt[30]={0};
    fr(i,0,s.length()-1){
        cnt[s[i]-'a']++;
    }
    int it=-1;
    rf(i,25,0){
        while(cnt[i]--){
            s[++it]=i+'a';
        }
    }
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    rd(n,m);
    if(n==1){
        pt("1\n");return 0;
    }
    fr(i,1,n){
        cin>>s[i];
      //  sort(s[i].begin(),s[i].end(),greater<char>());
       Sort2(s[i]);
    }
    pre[0]=0;
    fr(i,1,n){
       pre[i]=get(pre[i-1],i);
    }
    suf[n+1]=0;
    rf(i,n,1){
        suf[i]=get(suf[i+1],i);
    }
    fr(i,1,n){
        string tmp=s[i];
        //sort(tmp.begin(),tmp.end());
        Sort1(tmp);
        if(tmp<s[get(pre[i-1],suf[i+1])]){
            pt("1");
        }else{
            pt("0");
        }
    }pt("\n");
    return 0;
}
