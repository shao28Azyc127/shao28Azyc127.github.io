#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
    x=0;char c=getchar();int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename T,typename ...Args>
inline void read(T &x,Args &...rest){read(x);read(rest...);}

int n,a[100][10],ans,k[10];

inline int check(){
    int diff,t,pos1,s;
    for(int i=1;i<=n;i++){
        diff=0,t=0,pos1=0;
        for(int j=1;j<=5;j++){
            s=(k[j]-a[i][j]+10)%10;
            if(s){
                diff++;
                if(diff>2)return 0;
                if(pos1){
                    if(j!=5&&pos1!=j-1)return 0;
                    if(j==5&&pos1!=1)return 0;
                    if(t!=s)return 0;
                }
                else pos1=j,t=s;
            }
        }
        if(!diff)return 0;
    }
//    for(int i=1;i<=5;i++)printf("%d ",k[i]);
//    printf("\n");
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)read(a[i][j]);
    for(int r1=0;r1<=9;r1++){
     k[1]=r1;
     for(int r2=0;r2<=9;r2++){
      k[2]=r2;
      for(int r3=0;r3<=9;r3++){
       k[3]=r3;
       for(int r4=0;r4<=9;r4++){
        k[4]=r4;
        for(int r5=0;r5<=9;r5++){
        k[5]=r5;
        ans+=check();
        }
       }
      }
     }
    }
    printf("%d",ans);
    return 0;
}
