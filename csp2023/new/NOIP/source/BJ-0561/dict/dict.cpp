#include <bits/stdc++.h>
using namespace std;
vector<string>a;
string b;
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        sort(t.begin(),t.end());
        a.push_back(t);
        reverse(t.begin(),t.end());
        if(b!="")
        {
            b=min(b,t);
        }
        else
        {
            b=t;
        }
    }
    for(size_t i=0;i<a.size();i++)
    {
        if(a[i]<=b)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
