#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=101;
struct Node
{
    string type,name;
    int l,r;
}a[N];
map<string,ll>mp;
map<ll,bool>MP;
map<ll,int>Mp;
int n,cnt=0,L=-1;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int k;
            cin >> k;
        }
        else if(op==2)
        {
            cnt++;
            cin >> a[cnt].type >> a[cnt].name;
            if(a[cnt].type=="byte")
            {   
                for(int j=L+1;j<=L+1;j++)
                    MP[j]=true,Mp[j]=cnt;
                a[cnt].l=L+1,a[cnt].r=L+1,L+=1;
            }
            else if(a[cnt].type=="short")
            {
                for(int j=L+1;j<=L+2;j++)
                    MP[j]=true,Mp[j]=cnt;
                a[cnt].l=L+1,a[cnt].r=L+2,L+=2;
            }
            else if(a[cnt].type=="int")
            {
                for(int j=L+1;j<=L+4;j++)
                    MP[j]=true,Mp[j]=cnt;
                a[cnt].l=L+1,a[cnt].r=L+4,L+=4;
            }
            else
            {
                for(int j=L+1;j<=L+8;j++)
                    MP[j]=true,Mp[j]=cnt;
                a[cnt].l=L+1,a[cnt].r=L+8,L+=8;
            }
            mp[a[cnt].name]=a[cnt].l;
        }
        else if(op==3)
        {
            string S;
            cin >> S;
            cout<<mp[S]<<endl;
        }
        else
        {
            ll addr;
            cin >> addr;
            if(!MP[addr])cout<<"ERR"<<endl;
            else cout<<a[Mp[addr]].name<<endl;
        }
    }
    return 0;
}