#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,ll> mp;
map<ll,string> rev;
int g[200],cnt;
int main()
{
    ios::sync_with_stdio(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    ll addr=0;
    for(int i=1;i<=n;i++)
    {
        ll op,pl;
        string T,name;
        cin>>op;
        if(op==2)
        {
            cin>>T>>name;
            mp[name]=addr;

            cout<<addr<<endl;
            if(T=="long")  addr+=8;
            else if(T=="int")  addr+=4;
            else if(T=="short")  addr+=2;
            else if(T=="byte")  addr+=1;
            g[++cnt]=addr-1;rev[addr-1]=name;
        }
        if(op==3)
        {
            cin>>T;
            cout<<mp[T]<<endl;
        }
        if(op==4)
        {
            cin>>pl;
            if(pl>addr-1)  cout<<"ERR"<<endl;
            for(int j=cnt;j>=1;j--)  if(pl<=g[j])  cout<<rev[g[j]]<<endl;
        } 
    }
    return 0;
}
//����һ���͸�Ϊ��short ���͵ĳ�Ա aa ռ�ݵ� 0��1 �ֽڣ�int ���͵ĳ�Ա ab ռ�ݵ� 4��7 �ֽڡ�