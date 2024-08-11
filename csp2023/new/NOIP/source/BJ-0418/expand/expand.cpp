#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
string s1[3010],s2[3010];
int f[200];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(c==1)
    {
        int t,t2;
        cin>>t>>t2;
        cout<<(t!=t2);
        while(q--)
        {
            int k1,k2;
            cin>>k1>>k2;
            int x1=t,x2=t2;
            for(int i=1;i<=k1;i++)
            {
                int id,v;
                x1=v;
            }
            for(int i=1;i<=k2;i++)
            {
                int id,v;
                x2=v;
            }
            cout<<(x1!=x2);
        }
    }
    return 0;
}