#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ans[3001];
int n,m;
string a,b;
set<pair<string,int> >s;
set<pair<string,int> >::iterator it;
const bool cmp(const char a,const char b){
    return a>b;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        b=a;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),cmp);
        s.insert(make_pair(a,i));
        s.insert(make_pair(b,n));
    }
    while((it=s.begin())->second!=n){
        ans[it->second]=1;
        s.erase(it);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<endl;
}
