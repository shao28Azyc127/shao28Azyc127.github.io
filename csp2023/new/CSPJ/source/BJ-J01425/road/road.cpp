#include<bits/stdc++.h>
using  namespace std;
vector<int> a;
vector<int> v;
int vain=100000
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        vain=min(vain,b)
        v.push_back(b);
        vain=b;
    }
    if(v[0]==vain)
    {
        cout<<vain/a[0]<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        vain=min(vain,b)
        v.push_back(b);
    }