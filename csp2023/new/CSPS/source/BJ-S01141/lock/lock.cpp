#include<bits/stdc++.h>
#define gc() getchar()
typedef long long ll;
using namespace std;
const int N=100010;
int n,c[10][10];
inline ll read(){
    ll a=0,b=1;
    char c=gc();
    while(c<'0'||c>'9'){
        if(c=='-'){
            b=-1;c=gc();break;
        }
        c=gc();
    }
    while(c>='0'&&c<='9'){
        a=a*10+(c-'0');c=gc();
    }
    return a*b;
}
int x[10];
bool ck(int x1,int x2,int x3,int x4,int x5){
    x[1]=x1,x[2]=x2,x[3]=x3,x[4]=x4,x[5]=x5;
    bool kd=1;
    int dela,delb,timea;
    for(int i=1;i<=n;i++){
        if(!kd)break;
        dela=-1,delb=-1,timea=-1;
        for(int j=1;j<=5;j++){
            if(x[j]!=c[i][j]){
                if(dela==-1){
                    dela=(x[j]-c[i][j]+10)%10;
                    timea=j;
                }else if(delb==-1){
                    if(timea!=j-1)kd=0;
                    delb=(x[j]-c[i][j]+10)%10;
                }else kd=0;
            }
        }
        if(dela==-1)kd=0;
        if(dela!=-1&&delb!=-1&&dela!=delb)kd=0;
    }
    if(kd)return 1;return 0;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            c[i][j]=read();
        }
    }
    int ans=0;
    for(int x1=0;x1<=9;x1++){
        for(int x2=0;x2<=9;x2++){
            for(int x3=0;x3<=9;x3++){
                for(int x4=0;x4<=9;x4++){
                    for(int x5=0;x5<=9;x5++){
                        if(ck(x1,x2,x3,x4,x5)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
