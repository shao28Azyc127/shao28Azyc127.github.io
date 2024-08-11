#include<bits/stdc++.h>
using namespace std;
int n,a[15][10],safe[10],cnt;
bool xxx(int a,int b,int c,int d){
    for(int i=1;i<=16;i++){
        int r1=a,r2=c;
        a=(a+i)%10;c=(c+i)%10;
        if(a==b&&c==d)return true;
        a=r1,c=r2;
    }
    return false;
}
bool check(int h){
    vector<int>vec;
    for(int i=1;i<=5;i++)
        if(safe[i]!=a[h][i])
            vec.push_back(i);
    if(vec.size()>=3||vec.size()==0)return false;
    if(vec.size()==1)return true;
    if(vec.size()==2){
        int m1=vec[0],m2=vec[1];
        if(abs(m1-m2)!=1)return false;
        int ax=a[h][m1],b=safe[m1],c=a[h][m2],d=safe[m2];
        return xxx(ax,b,c,d);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    for(int k1=0;k1<=9;k1++)
        for(int k2=0;k2<=9;k2++)
            for(int k3=0;k3<=9;k3++)
                for(int k4=0;k4<=9;k4++)
                    for(int k5=0;k5<=9;k5++){
                        safe[1]=k1,safe[2]=k2,safe[3]=k3,safe[4]=k4,safe[5]=k5;
                        bool f=true;
                        for(int i=1;i<=n;i++)
                            if(!check(i)){
                                f=false;break;
                            }
                        cnt+=f;
                    }
    printf("%d",cnt);
    return 0;
}