#include <bits/stdc++.h>
using namespace std;

int a[100020];
struct tmp{
    char type;
    int x,y
}ty[100020];

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);

    for(int i=0;i<t;i++){
        for(int i=0;i<100005;i++)
            a[i]=i;
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++){
            char as;
            scanf("%s",&as);
            if(as>='A'&&as<='Z') {
                int k;
                scanf("%d",&k);
                if(as=='T') a[k]=100005;
                else if(as=='F') a[k]=-100005;
                else if(as=='U') a[k]=0;
                ty[j].x=k; ty[j].type=as;
            } else if(as=='+') {
                int k,l;
                scanf("%d%d",&k,&l);
                a[k]=a[l];
                ty[j].x=k; ty[j].y=l; ty[j].type=as;
            } else if(as=='-') {
                int k,l;
                scanf("%d%d",&k,&l);
                a[k]=-a[l];
                ty[j].x=k; ty[j].y=l; ty[j].type=as;
            }
            
            if(a[j]==-j)
                a[j]=0;
        }
        for(int j=1;j<=m;j++){
            if(a[j]==0)
                ans++;
        }
        printf("%d\n",ans);


    }
}
