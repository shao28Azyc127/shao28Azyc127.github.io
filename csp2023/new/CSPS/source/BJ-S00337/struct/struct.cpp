#include<bits/stdc++.h>
using namespace std;
const int M=105;
int N,tmps;map<string,long long> s,e,sz;
vector<string> t,n;
int main()
{
    freopen("struct.in","r",stdin);freopen("struct.out","w",stdout);
    sz["byte"]=1;sz["short"]=2;sz["int"]=4;sz["long"]=8;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int op;cin>>op;
        if(op==2)
        {
            string x,y;
            cin>>x>>y;
            t.push_back(x);n.push_back(y);
            s[y]=tmps;e[y]=tmps+sz[x]-1;tmps=e[y]+1;
        }
        else if(op==3)
        {
            string nn;cin>>nn;cout<<s[nn]<<endl;
        }
        else
        {
            long long addr;cin>>addr;
            bool flag=false;
            for(int j=0;j<t.size();j++){if(addr>=s[n[j]]&&addr<=e[n[j]]) cout<<n[j]<<endl,flag=true;}
            if(!flag) cout<<"ERR"<<endl;
        }
    }
    return 0;
}
