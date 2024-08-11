#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int MXN=3010;
typedef pair<string,int> pant;
priority_queue<pant,vector<pant>,greater<pant> > q;
string sg[MXN],sl[MXN]; 
string s[MXN];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;cin>>n>>m;
    if(n==1) {cout<<"1\n";return 0;}
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        sg[i]=s[i],sl[i]=s[i];
        sort(sg[i].begin(),sg[i].end(),greater<char>());
        sort(sl[i].begin(),sl[i].end());
        // cout<<sg[i]<<' '<<sl[i]<<endl;
    }
    for(int i=1;i<=n;i++) q.push({sg[i],i});
    string mn1=q.top().first;
    int id1=q.top().second;q.pop();
    string mn2=q.top().first;
    int id2=q.top().second;q.pop();
    for(int i=1;i<=n;i++)
    {
        string G=mn1;
        if(i==id1) G=mn2;
        // cout<<sl[i]<<' '<<G<<' ';
        if(sl[i]<G) cout<<1;
        else cout<<0;
        // cout<<endl;
    }cout<<endl;
    return 0;
}