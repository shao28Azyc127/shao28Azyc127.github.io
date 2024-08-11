#include<bits/stdc++.h>
using namespace std;
const int N=3030;
string s[N],ft[N];
bool cmp(char x,char y)
{
    return x>y;
}
string tmp;
struct nod
{
    string str;int pos;
}lt[N];
bool cmp1(nod x,nod y)
{
    return x.str<y.str;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        tmp=s[i];
        sort(tmp.begin(),tmp.end(),cmp);
        lt[i].str=tmp;lt[i].pos=i;
        tmp=s[i];
        sort(tmp.begin(),tmp.end());
        ft[i]=tmp;
        //cout<<lt[i]<<endl<<ft[i]<<endl;
    }
    sort(lt+1,lt+n+1,cmp1);
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        if(ft[i]>lt[1].str)  flag=0;
        else if(ft[i]==lt[1].str)
        {
            if(lt[1].pos==i)
            {
                if(lt[2].str<ft[i])  flag=0;
            }
            else  flag=0;
        }  
        if(flag)  cout<<1;
        else  cout<<0;
    }
    return 0;
}