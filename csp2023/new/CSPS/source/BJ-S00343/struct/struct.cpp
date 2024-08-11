#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

map<string,int> len,pos;
string s[105];int sz;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    len["byte"]=1,len["short"]=2,len["int"]=4,len["long"]=8;
    int n,p=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;cin>>op;
        if(op==1){
            string m;int x;
            cin>>m>>x;
            for(int i=1;i<=x;i++)
                cin>>m>>m;
        }
        if(op==2){
            string t,m;
            cin>>t>>m;
            s[++sz]=m;
            cout<<p<<endl;
            pos[m]=p;
            p+=len[t];
        }
        if(op==3)
        {
            string m;
            cin>>m;
            cout<<pos[m]<<endl;
        }
        if(op==4){
            int addr;
            cin>>addr;
            if(addr>=p)puts("ERR");
            else{
                for(int i=1;i<=sz;i++)
                {
                    string m=s[sz];
                    if(pos[m]<=addr&&pos[s[sz+1]]>addr){
                        cout<<m<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
