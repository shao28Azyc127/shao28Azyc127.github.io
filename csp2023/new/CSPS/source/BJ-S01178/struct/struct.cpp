#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=102;

int n,ans,p[800005],cnt,last;

struct node
{
    string name;
    int l,r;
    string s;
}a[N];

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==2)
        {
            cnt++;
            cin>>a[cnt].s>>a[cnt].name;
            int k;
            if(a[cnt].s=="byte")
                k=1;
            if(a[cnt].s=="short")
                k=2;
            if(a[cnt].s=="int")
                k=4;
            if(a[cnt].s=="long")
                k=8;
            while(last%k!=0)
                last++;
            a[i].l=last;
            for(int i=1;i<=k;i++)
                p[last+i-1]=cnt;
            last+=k;
            a[i].r=last-1;
        }
        if(op==3)
        {
            string s;
            cin>>s;
            for(int i=1;i<=cnt;i++)
                if(s==a[i].name)
                {
                    cout<<a[i].l<<endl;
                    break;
                }
        }
        if(op==4)
        {
            int addr;
            cin>>addr;
            cout<<a[p[addr]].name<<endl;
        }
    }
    return 0;
}
