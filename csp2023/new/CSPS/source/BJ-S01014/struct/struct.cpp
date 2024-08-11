#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
map<string,int> s;
map<string,string> c;
map<string,int> e;
map<int,string> f;
int d[N];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int t,op,len=0,x=0,maxn=-1;
    cin>>t;
    while(t--)
    {
        cin>>op;
        if(op==2)
        {
            string a,b;
            cin>>a>>b;
            c[b]=a;
            if(a=="byte")
            {
                s[b]=1;
                len++;
                d[len]=1;
                maxn=max(maxn,1);
            }
            if(a=="short")
            {
                s[b]=2;
                len++;
                d[len]=2;
                maxn=max(maxn,2);
            }
            if(a=="int")
            {
                s[b]=4;
                len++;
                d[len]=4;
                maxn=max(maxn,4);
            }
            if(a=="long")
            {
                s[b]=8;
                len++;
                d[len]=8;
                maxn=max(maxn,8);
            }
            e[b]=len;
            f[len]=b;
            cout<<(len-1)*maxn<<endl;
        }
        else if(op==3)
        {
            string a;
            cin>>a;
            cout<<(e[a]-1)*maxn<<endl;
        }
        else if(op==4)
        {
            long long x;
            scanf("%lld",&x);
            long long n=x/maxn;
            x%=maxn;
            string a=f[n+1];
            int p=s[a];
            x++;
            if(x<=p) cout<<a<<endl;
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}
