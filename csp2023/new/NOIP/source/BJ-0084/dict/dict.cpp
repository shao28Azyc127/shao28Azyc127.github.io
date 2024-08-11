#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3005],t[3005];
int cnt[30];
struct node{
    string s;bool tp;//tp=0:s tp=1:t
    int id;
    bool operator<(const node&b){
        return s==b.s?tp==b.tp?id<b.id:tp>b.tp:s<b.s;
    }
};vector<node>a;
bool ans[3005];
vector<int>ids;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        for(auto j:s[i])++cnt[j-'a'];
        s[i]="";
        for(int j=0;j<26;j++)for(int k=1;k<=cnt[j];k++)s[i]+='a'+j;
        for(int j=25;~j;j--)for(++cnt[j];--cnt[j];)t[i]+='a'+j;
        a.push_back({s[i],0,i});
        a.push_back({t[i],1,i});
    }
    sort(a.begin(),a.end());
    for(auto i:a){
        if(i.tp==1)ids.push_back(i.id);
        else{
            if(ids.size()==0)ans[i.id]=1;
            else if(ids.size()==1&&ids[0]==i.id)ans[i.id]=1;
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<"\n";
    return 0;
}