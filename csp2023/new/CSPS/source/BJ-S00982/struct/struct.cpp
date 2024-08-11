#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s1[15]="byte",s2[15]="short",s3[15]="int",s4[15]="long";

struct node
{
    char nam[15];
    int num,siz,szz;
    char sntp[105][15],snnm[105][15];
}a[105];
int cnt;

struct Node
{
    char nam[15],typ[15];
    int siz,pos;
}b[105];
int tot,pos;

int dfs(int typ,char ss[105],int nw)
{
    if(nw>=strlen(ss)) return 0;
    int i=0,ans=0; char st[15];
    while(ss[++nw]!='.')
        st[i++]=ss[nw];
    nw++;
    for(i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cnt;j++)
            if(!strcmp(a[typ].snnm[i],a[j].nam)) ans+=a[j].szz;
        if(!strcmp(st,a[typ].snnm[i]))
        {
            for(int j=1;j<=cnt;j++)
                if(!strcmp(a[typ].snnm[i],a[j].nam))
                {
                    return ans+dfs(j,ss,nw);
                    break;
                }
            break;
        }
    }

}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,opt;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            cin>>a[++cnt].nam;
            int k; scanf("%d",&k);
            while(k--)
            {
                cin>>a[cnt].sntp[++a[cnt].num]>>a[cnt].snnm[a[cnt].num];
                if(!strcmp(a[cnt].sntp[a[cnt].num],s1)) a[cnt].siz=max(a[cnt].siz,1);
                else if(!strcmp(a[cnt].sntp[a[cnt].num],s2)) a[cnt].siz=max(a[cnt].siz,2);
                else if(!strcmp(a[cnt].sntp[a[cnt].num],s3)) a[cnt].siz=max(a[cnt].siz,4);
                else if(!strcmp(a[cnt].sntp[a[cnt].num],s4)) a[cnt].siz=max(a[cnt].siz,8);
                else
                {
                    for(int i=1;i<=cnt;i++)
                        if(!strcmp(a[cnt].sntp[a[cnt].num],a[i].nam))
                        {
                            a[cnt].siz=max(a[cnt].siz,a[i].szz);
                            break;
                        }
                }
            }
            a[cnt].szz=a[cnt].num*a[cnt].siz;
            printf("%d %d\n",a[cnt].szz,a[cnt].siz);
        }
        else if(opt==2)
        {
            cin>>b[++tot].typ>>b[tot].nam;
            for(int i=1;i<=cnt;i++)
                if(!strcmp(b[tot].typ,a[i].nam))
                    {
                        b[tot].siz=a[i].szz;
                        break;
                    }
            b[tot].pos=pos;
            pos+=b[tot].siz;
            printf("%d\n",b[tot].pos);
        }
        else if(opt==3)
        {
            char ss[105],st[15];
            int nw,ans;
            cin>>ss;
                int i=0
                while(ss[++nw]!='.')
                    st[i++]=ss[nw];
                nw++;
                for(int i=1;i<=cnt;i++)
                    if(!strcmp(st,b[i].nam))
                        {
                            ans=dfs(i,ss,nw)
                            break;
                        }
                    
            }
        }
    }
    return 0;
}
