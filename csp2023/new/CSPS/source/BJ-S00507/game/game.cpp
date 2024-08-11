#include<bits/stdc++.h>
using namespace std;
int n,ans;
string m;
bool nxc(string x)
{
    vector<char>c;
    for(size_t i=0;i<x.size();i++)
    {
        if(c.size()==0)
        {
            c.push_back(x[i]);
            continue;
        }
        if(c.back()==x[i])
        {
            c.pop_back();
        }
        else
        {
            c.push_back(x[i]);
        }
    }
    if(c.size()==0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    //int t=clock();
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>m;
    for(size_t i=0;i<m.size();i++)
    {
        for(size_t j=i+1;j<m.size();j++)
        {
            if(nxc(m.substr(i,j-i+1)))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    //cout<<endl<<"runtime="<<(clock()-t)/1000000.0;
    return 0;
}