#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=10;
char s[N][10];
int a[N][10];
int n,sum=0;
void ipt(){
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,5) scanf("%d",&a[i][j]);
}
bool cot(int a1,int a2,int b1,int b2){
    if(a1==b1||a2==b2) return false;
    FOR(i,0,9){
        int p1=(a1+10+i)%10,p2=(a2+10+i)%10;
        if(p1==b1&&p2==b2) return true;
    }
    return false;
}
bool check(int x[]){
    FOR(i,1,n){
        bool flg=false;
        int cnt=0;
        FOR(j,1,5){
            if(x[j]!=a[i][j]) cnt++;
            if(cnt>=3) return false;
        }
        if(cnt==0) return false;
        if(cnt==2){
            bool flg=false;
            FOR(j,1,4){
                if(cot(x[j],x[j+1],a[i][j],a[i][j+1])){
                    //printf("%d \n",j);
                    flg=true;
                    break;
                }
            }
            if(flg==false) return false;
        }
        //FOR(j,1,5) printf("%d",a[i][j]);
        //FOR(j,1,5) printf("%d",x[j]);
        //printf(",%d\n",cnt);
    }
    //FOR(j,1,5) printf("%d",x[j]);
    //printf(",%d\n",++sum);
    return true;
}
void solve(){
    int ans=0;
    FOR(d1,0,9){
        FOR(d2,0,9){
            FOR(d3,0,9){
                FOR(d4,0,9){
                    FOR(d5,0,9){
                        int now[6]={0,d1,d2,d3,d4,d5};
                        if(check(now)) ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ipt();
    solve();
    return 0;
}