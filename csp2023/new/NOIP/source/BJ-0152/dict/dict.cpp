#include<bits/stdc++.h>
#define p_b push_back
#define p1 first
#define p2 second
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}struct Trie {
    struct node {
        map<int,int>mp;
        int cnt;
        node(){
            mp.clear();cnt=0;
        }
    };
    int tot;
    vector<node>v;
    Trie(){
        v.resize(1);
        tot=0;
    }
    void ins(string &s){
        int x=0;v[0].cnt++;
        for(char ch:s){
            if(!v[x].mp[ch])v[x].mp[ch]=++tot,v.p_b(node());
            x=v[x].mp[ch];
            v[x].cnt++;
        }
    }void del(string &s){
        int x=0;v[0].cnt--;
        for(char ch:s){
            x=v[x].mp[ch];
            v[x].cnt--;
        }
    }int qry(string &s){
        int x=0;
        for(char ch:s){
            for(auto it:v[x].mp){
                if(it.p1<'a'||it.p1>'z')continue;
                if(it.p1<ch&&v[it.p2].cnt)return 0;
            }if(!v[x].mp.count(ch))return 1;
            x=v[x].mp[ch];
            if(!x)return 1;
        }if(v[x].cnt)return 0;
        return 1;
    }
}T;
string s[3005];
int n,m;
void slv(){
    n=read(),m=read();
    up(i,1,n)getline(cin,s[i]);
    up(i,1,n){
        sort(s[i].begin(),s[i].end());
        reverse(s[i].begin(),s[i].end());
        T.ins(s[i]);
    }up(i,1,n){
        T.del(s[i]);
        reverse(s[i].begin(),s[i].end());
        if(T.qry(s[i]))printf("1");
        else printf("0");
        reverse(s[i].begin(),s[i].end());
        T.ins(s[i]);
    }printf("\n");
}int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}