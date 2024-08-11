#include<bits/stdc++.h>
using namespace std;
#define rint register int

inline int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-f;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
struct lin{

};
struct yu{
    string a;
    int b;
    int c;
} jgt[105];
int k,n,x,b;

signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    n=read();
    jgt[1].a="byte",jgt[1].b=1;
    jgt[2].a="short",jgt[2].b=2;
    jgt[3].a="int",jgt[3].b=4;
    jgt[4].a="long",jgt[4].b=8;
    k=4;
    while(n--)
    {
        cin>>x;
        if(x==1)
        {
            k++;
            string s2,s3;
            int a,ans=0;
            cin>>jgt[k].a>>a;
            while(a--)
            {
                cin>>s2>>s3;
                for(int i=1;i<=k-1;++i)
                    if(s2==jgt[i].a)
                    {
                        if(jgt[k].b<jgt[i].b)
                            jgt[k].b=jgt[i].b;
                        if(ans%jgt[i].b==0) ans+=jgt[i].b;
                        else ans+=jgt[i].b*2-ans%jgt[i].b;
                        break;
                    }
            }
            if(ans%jgt[k].b==0) cout<<ans<<" "<<jgt[k].b;
                else cout<<ans+ans%jgt[k].b+2*jgt[k].b<<" "<<jgt[k].b;
        }
    }
    return 0;
}
