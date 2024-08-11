#include<bits/stdc++.h>//maybe15
using namespace std;
string fd[1000];
map<string,long long> size,st;
map<string,int> mp,nm;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,cnt=0;
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
    cin>>n;
    //if A
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        /*if(op==1)
        {
            string s;
            cin>>s;
            int nq;
            cin>>nq;
            for(int j=1
        }*/
        if(op==2)
        {
            string s,s1;
            cin>>s>>s1;
            size[s1]=mp[s];
            fd[++cnt]=s1;
            nm[s1]=cnt;
            if(cnt==1) st[s1]=0;
            else 
            {
                int qaq=st[fd[cnt-1]]+size[fd[cnt-1]];
                st[s1]=(qaq%size[s1]==0)?qaq:(qaq/4+1)*4;
            }
            cout<<st[s1]<<'\n';
        }
        
        if(op==3)
        {
            string s;
            cin>>s;
            cout<<st[s]<<'\n';
        }
        if(op==4)
        {
            long long add;
            cin>>add;
            bool flag=0;
            for(int j=1;j<=cnt;j++)
            {
                string s=fd[j];
                if(st[s]<=add&&st[s]+size[s]-1>=add) 
                {
                    cout<<s<<'\n';
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<"ERR"<<'\n';
        }
    }
    return 0;
}

