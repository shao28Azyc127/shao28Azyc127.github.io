#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
using namespace std;
#define ll long long
#define ull unsigned long long
ll read(){
    ll x=0,k=1;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
map<string,int> mp,mp2;
struct E{
    long long p,l;
    string name;
};
struct str{
    vector<E> son;
    ll mx,siz;
}a[205];
int n=4,m=0;
E b[205];
long long solve3(){
    string s;
    cin>>s;
    // cout<<s<<endl;
    // for(int i=1;i<=m;i++) cout<<b[i].l<<" "; puts("");
    ll ret=0;
    for(int l=0,r=0,u;l<s.length();l=r=r+1){
        for(;s[r]&&s[r]!='.';r++);
        // cout<<l<<" "<<r<<" "<<ret<<" "<<u<<endl;
        string t;
        for(int i=l;i<r;i++) t+=s[i];
        if(!l){
            for(int i=1;i<=m;i++){
                if(b[i].name==t){
                    ret+=b[i].l,u=b[i].p;
                    break;
                }
            }
            continue;
        }
        for(int i=0;i<a[u].son.size();i++){
            // cout<<t<<" "<<a[u].son[i].name<<endl;
            if(a[u].son[i].name==t){
                ret+=a[u].son[i].l,u=a[u].son[i].p;
                break;
            }
        }
    }
    // cout<<ret<<endl;
    return ret;
}
void solve4(long long x){
    if(!m||(m&&x>=b[m].l+a[b[m].p].siz)){
        puts("ERR");
        return;
    }
    int u;
    vector<string> ans;
    for(int i=1;i<=m;i++){
        if(x<b[i].l+a[b[i].p].siz){
            if(x<b[i].l){
                puts("ERR");
                return;
            }
            x-=b[i].l,u=b[i].p,ans.push_back(b[i].name);
            break;
        }
    }
    // cout<<x<<" "<<u<<" "<<a[b[1].p].siz<<endl;
    while(u>4){
        int i0=a[u].son.size()-1;
        if(x>=a[u].son[i0].l+a[a[u].son[i0].p].siz) {
            puts("ERR");
            return;

        }
        for(int i=0;i<a[u].son.size();i++){
            if(x<a[u].son[i].l+a[a[u].son[i].p].siz){
                if(x<a[u].son[i].l) {
                    puts("ERR");
                    return;
                }
                x-=a[u].son[i].l,ans.push_back(a[u].son[i].name),u=a[u].son[i].p;
                break;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i+1<ans.size()) putchar('.');
    }
    puts("");
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"]=1,mp["short"]=2,mp["int"]=3,mp["long"]=4;
    a[1].mx=a[1].siz=1,a[2].mx=a[2].siz=2,a[3].mx=a[3].siz=4,a[4].mx=a[4].siz=8;
    int T=read();
    while(T--){
        int op=read();
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            mp[s]=++n;
            long long l=0;
            while(k--){
                string t,u;
                cin>>t>>u;
                int p=mp[t];
                if(l%a[p].mx) l+=a[p].mx-l%a[p].mx;
                a[n].son.push_back({mp[t],l,u});
                a[n].mx=max(a[n].mx,a[mp[t]].mx);
                // cout<<l<<endl;
                l+=a[mp[t]].siz;
            }
            // cout<<a[n].son[0].l<<endl;
            if(l%a[n].mx) l+=a[n].mx-l%a[n].mx;
            a[n].siz=l;
            // cout<<a[n].son.size()<<endl;
            printf("%lld %lld\n",a[n].siz,a[n].mx);
        }
        else if(op==2){
            string s,t;
            cin>>s>>t;
            long long l=b[m].l+a[b[m].p].siz;
            if(l%a[mp[s]].mx) l+=a[mp[s]].mx-l%a[mp[s]].mx;
            b[++m]={mp[s],l,t};
            long long ans=0;
            // for(int i=1;i<m;i++) ans+=a[b[i].p].siz;
            printf("%lld\n",l);
        }
        else if(op==3){
            printf("%lld\n",solve3());
        }
        else if(op==4){
            long long x=read();
            solve4(x);
        }
        // cout<<endl;
    }
    return 0;
}