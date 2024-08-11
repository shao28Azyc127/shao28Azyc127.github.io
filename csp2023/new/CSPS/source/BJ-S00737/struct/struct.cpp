#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int maxn=1000005;

int n;
int tot;
int ad;
map<string,int> mp;
string m[maxn];

int st[maxn];
int lst[maxn];
void update(int l,int r,int v)
{
    for(int i=l;i<=r;i++)
    {
        lst[i]=v;
    }
    return;
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            continue;
        }
        else if(op==2)
        {
            string t,n;
            cin>>t>>n;
            printf("%d\n",ad);
            m[++tot]=n;
            mp[n]=tot;
            st[tot]=ad;
            if(t=="byte")
            {
                update(ad,ad,tot);
                ad++;
            }
            else if(t=="short")
            {
                update(ad,ad+1,tot);
                ad+=2;
            }
            else if(t=="int")
            {
                update(ad,ad+3,tot);
                ad+=4;
            }
            else
            {
                update(ad,ad+7,tot);
                ad+=8;
            }
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            printf("%d\n",st[mp[s]]);
        }
        else
        {
            int add;
            scanf("%d",&add);
            int ans=lst[add];
            if(ans) cout<<m[ans]<<endl;
            else printf("ERR\n");
        }
    }
    return 0;
}
