#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct s{
    string s_name,c_name[101];
    int len[101],k;
    ll ans_len;
}a[101];
ll Find(ll x,int T){
    ll ans=0;
    while(ans<x) ans+=T;
    return ans;
}
map<string,int> mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,k,tmp=0; string str,aa; cin>>n;

    ll pre;

    for(int i=1;i<=n;i++){
        cin>>k;
        if(k==1){
           ll ans_1=0,ans_2=0; pre=0;
           int m; cin>>str>>m; tmp++;
           mp[str]=tmp; a[tmp].k=0;
           for(int i=1;i<=m;i++){
            cin>>str>>aa; int T;
            if(str=="byte") ans_2=max(ans_2,(ll)1),T=1;
            else if(str=="short") ans_2=max(ans_2,(ll)2),T=2;
            else if(str=="int") ans_2=max(ans_2,(ll)4),T=4;
            else if(str=="long") ans_2=max(ans_2,(ll)8),T=8;
            else ans_2=max(ans_2,a[mp[str]].ans_len),T=a[mp[str]].ans_len;
            if(T>pre) ans_1=Find(ans_1,T)+T;
            else ans_1+=T;
            pre=T;
           }
           a[tmp].ans_len=ans_1;
           cout<<ans_1<<' '<<ans_2<<endl;
        }

    }
    fclose(stdin); fclose(stdout);
    return 0;
}
