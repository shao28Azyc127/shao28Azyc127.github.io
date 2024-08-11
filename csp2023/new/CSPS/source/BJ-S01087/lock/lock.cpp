#include<bits/stdc++.h>
using namespace std;
int ans,n,a[15][10],l[5];
bool check(){
    for(register int i=1;i<=n;++i){
        int cha[5],samsum=0;
        bool f[5]={0,0,0,0,0};
        for(register int j=0;j<5;++j){
            cha[j]=l[j]-a[i][j];
            if(cha[j]==0)f[j]=1,++samsum;
        }
        if(samsum<3||samsum==5)return 0;
        if(samsum==3)for(register int j=0;j<5;++j){
            if(!f[j]){
                if(cha[j]==cha[j+1])break;
                else if(l[j]+10-a[i][j]==cha[j+1])break;
                else if(l[j+1]+10-a[i][j+1]==cha[j])break;
                else return 0;
            }
        }
    }
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)for(register int j=0;j<5;++j)
        scanf("%d",&a[i][j]);
    for(l[0]=0;l[0]<=9;++l[0])for(l[1]=0;l[1]<=9;++l[1])
    for(l[2]=0;l[2]<=9;++l[2])for(l[3]=0;l[3]<=9;++l[3])
    for(l[4]=0;l[4]<=9;++l[4])if(check()){
        ++ans;//cout<<l[0]<<l[1]<<l[2]<<l[3]<<l[4]<<"\n";
    }
    return printf("%d",ans),0;
}