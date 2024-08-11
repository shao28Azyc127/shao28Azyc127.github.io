#include<cstdio>
using namespace std;
int a[10],c[10][10];
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=read(),ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) c[i][j]=read();
    for(a[1]=0;a[1]<10;a[1]++)
    for(a[2]=0;a[2]<10;a[2]++)
    for(a[3]=0;a[3]<10;a[3]++)
    for(a[4]=0;a[4]<10;a[4]++)
    for(a[5]=0;a[5]<10;a[5]++){
        int fl=1;
        for(int i=1;i<=n;i++){
            int t1=-1,t2=-1;
            for(int j=1;j<=5;j++) if(a[j]!=c[i][j]){
                if(t1==-1) t1=j;
                else if(t2==-1) t2=j;
                else fl=0;
            }
            if(t1==-1) fl=0;
            if(t2!=-1){
                if(t2-t1!=1) fl=0;
                if((c[i][t2]-a[t2]+10)%10!=(c[i][t1]-a[t1]+10)%10) fl=0;
            }
        }
        ans+=fl;
    }
    printf("%d\n",ans);
    return 0;
}