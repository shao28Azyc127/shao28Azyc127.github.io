 #include <bits/stdc++.h>
using namespace std;
long long q, op;
map<string,long long> mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>q;
    while(q--){
        cin>>op;
        string s;
        long long k, maxn=0;
        cin>>s>>k;
		string t, n;
        for(long long i=1;i<=k;i++){
            cin>>t>>n;
            if(t=="byte") maxn=max(maxn,1ll);
            else if(t=="short") maxn=max(maxn,2ll);
            else if(t=="int") maxn=max(maxn,4ll);
            else if(t=="long") maxn=max(maxn,8ll);
            else maxn=max(maxn,mp[t]);
        }
        mp[s]=maxn*k;
        cout<<k*maxn<<' '<<maxn<<endl;
    }
    return 0;
}
