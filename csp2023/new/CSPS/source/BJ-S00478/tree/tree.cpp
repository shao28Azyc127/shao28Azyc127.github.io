#include <bits/stdc++.h>
using namespace std;
long long a[100006];
int b[100006];
int c[100006];
int t[100006];
vector <int> tu[100006];

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        t[i]=ceil(a[i]*1.0/max(c[i],1));
    }
    int p,q;
    for(int i = 1;i <n;i++)
    {
        cin>>p>>q;
        tu[p].push_back(q);
        tu[q].push_back(p);
    }
    set <int> havep,cang;
    cang.insert(1);
    int today=1,maxd=0;
    while(havep.size()<n)
    {
        int maxx=-100000000,index=-1;
        for(set <int>::iterator it=cang.begin();it!=cang.end();it++)
        {
            if(t[*it]>maxx) index=*it;
            maxx=max(maxx,t[*it]);
        }
        maxd=max(maxd,today+maxx);
        havep.insert(index);
        cang.erase(index);
        for(int i = 0;i <=tu[index].size();i++)
            if(havep.find(tu[index][i])==havep.end())
                cang.insert(tu[index][i]);
    }
    cout<<maxd;
    return 0;
}
