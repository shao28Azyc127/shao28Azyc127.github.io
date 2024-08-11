#include <iostream>
#include <cstdio>
using namespace std;
int n,tp,pp[130],x[2000005],p[2000005];
string s2[105];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int i,j;
    cin>>n;
    pp['b']=1;
    pp['s']=2;
    pp['i']=4;
    pp['l']=8;
    for(i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            char c=getchar();
            while(c<'0'&&c>'9')
                c=getchar();
            c=getchar();
            while(c<'0'&&c>'9')
                c=getchar();
            op=c-48;
            i++;
        }
        if(op==2)
        {
            string s1;
            cin>>s1>>s2[i];
            int s=0;
            for(j=0;j<s1.size();j++)
                s=s*10+(s1[j]-96)*53;
            p[s]=tp;
            cout<<tp<<endl;
            tp+=pp[s1[0]];
            for(j=p[s];j<tp;j++)
                x[j]=i;
        }
        if(op==3)
        {
            string s;
            cin>>s;
            int ss=0;
            for(j=0;j<s.size();j++)
                ss=ss*10+s[j]*108;
            cout<<p[ss]<<endl;
        }
        if(op==4)
        {
            int xx;
            cin>>xx;
            if(x[xx]==0)
                cout<<"ERR"<<endl;
            else
                cout<<s2[x[xx]]<<endl;
        }
    }
    return 0;
}

