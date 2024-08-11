#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,int>mp,c,st;
map<int,string>E,e;
int a[1100],z[1100];
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,an=0;
    cin>>n;
    a[1]=z[1]=1;
    a[2]=z[2]=2;
    a[3]=z[3]=4;
    a[4]=z[4]=8;
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=3;
    mp["long"]=4;
    for(int i=1;i<=n;i++)
    {
        int op,cnt=4;
        cin>>op;

        if(op==2)
        {
            string S,R;
            mp[R]=++cnt;
            cin>>S>>R;
            if(an%z[mp[S]]!=0)
            {
                int pre=an;
                an=(an/z[mp[S]]+1)*z[mp[S]];
                for(int i=pre;i<=an;i++)
                    E[i]="ERR";
            }
            else
            {
                cout<<an<<endl;
                int pre=an;
                st[R]=an;
                an+=z[mp[S]];
                for(int i=pre;i<=an;i++)
                    E[i]=R;
            }
        }
        if(op==3)
        {
            string S;
            cin>>S;
            cout<<st[S]<<endl;
        }
        if(op==4)
        {
            int add;
            cin>>add;
            cout<<E[add]<<endl;
        }
    }
    return 0;
}
