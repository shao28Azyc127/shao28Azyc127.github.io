#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAXN 110
#define ll long long
using namespace std;
ll st[MAXN],ed[MAXN],p=1,n,m,x;
string s1,s2,nme[MAXN];
int mod;

ll getp(ll a,ll b)
{
    if (a%b==0) return a;
    return a-a%b+b;
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    st[0]=-1;
    ed[0]=-1;
    for (int i=1;i<=n;i++)
    {
        cin>>mod;
        if (mod==2)  //O(1)
        {
            cin>>s1>>s2;
            if (s1[0]=='b')
            {
                st[p]=ed[p-1]+1;
                ed[p]=st[p];
            }
            else if (s1[0]=='s')
            {
                st[p]=getp(ed[p-1]+1,2);
                ed[p]=st[p]+1;
            }
            else if (s1[0]=='i')
            {
                st[p]=getp(ed[p-1]+1,4);
                ed[p]=st[p]+3;
            }
            else if (s1[0]=='l')
            {
                st[p]=getp(ed[p-1]+1,8);
                ed[p]=st[p]+7;
            }
            nme[p]=s2;
            p++;
        }
        if (mod==3)  //O(n)
        {
            cin>>s1;
            int tmp=0;
            for (int i=1;i<p;i++)
            {
                if (nme[i]==s1)
                {
                    tmp=i;
                    break;
                }
            }
            cout<<st[tmp]<<endl;
        }
        if (mod==4) //O(logn)
        {
            cin>>x;
            long long tmp=upper_bound(st+1,st+p,x)-st-1;
            if (ed[tmp]<x)
            {
                cout<<"ERR"<<endl;
            }
            else
            {
                cout<<nme[tmp]<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
