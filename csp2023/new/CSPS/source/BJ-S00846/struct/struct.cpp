#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=1e7+5;
int n;
int addr[N];
int pos;
int st[105];
char na[105][20];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out",'w',stdout);
    n=read();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int opt=read();
        if(opt==2)
        {
            char ty[20];
            cin>>ty>>na[++cnt];
            if(!strcmp(ty,"short"))
            {
                int startpos=pos+(2-pos%2)%2;
                // cout<<startpos<<endl;
                for(int k=startpos;k<=startpos+2;k++) addr[k]=cnt;
                st[cnt]=startpos;
                pos=startpos+2;
            }
            if(!strcmp(ty,"long"))
            {
                int startpos=pos+(8-pos%8)%8;
                // cout<<startpos<<endl;
                for(int k=startpos;k<=startpos+8;k++) addr[k]=cnt;
                st[cnt]=startpos;
                pos=startpos+8;
            }
            if(!strcmp(ty,"int"))
            {
                int startpos=pos+(4-pos%4)%4;
                // cout<<startpos<<endl;
                for(int k=startpos;k<=startpos+4;k++) addr[k]=cnt;
                st[cnt]=startpos;
                pos=startpos+4;
            }
            if(!strcmp(ty,"byte"))
            {
                int startpos=pos;
                // cout<<startpos<<endl;
                for(int k=startpos;k<=startpos+1;k++) addr[k]=cnt;
                st[cnt]=startpos;
                pos=startpos+1;
            }
        }
        if(opt==3)
        {
            char query[20];
            cin>>query;
            for(int k=1;k<=cnt;k++) 
            {
                if(!strcmp(query,na[k])) cout<<st[k]<<endl;
            }
        }
        if(opt==4)
        {
            int p;
            cin>>p;
            if(!addr[p]) puts("ERR");
            else cout<<na[addr[p]]<<endl;
        }
    }
    return 0;
}