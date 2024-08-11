#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define int long long
#define ull unsigned long long
using namespace std;
int n;
int a[10][10];
int ans;
int d[10],k;
struct node{
    int id;
    int num;
};
bool check(){
    node dif[10];
    int kd=0;
    for(int i=1;i<=n;i++){
        kd=0;
        for(int j=1;j<=5;j++){
            if(d[j]!=a[i][j])dif[++kd].id=j,dif[kd].num=a[i][j];
        }
      //  cout<<kd<<endl;
        if(kd>2||kd==0)return false;
        if(kd==1)continue;
        if(dif[2].id-dif[1].id!=1)return false;
        int tmpx=dif[2].num-d[dif[2].id],tmpy=dif[1].num-d[dif[1].id];
        if(tmpx==tmpy)continue;
        if(tmpx*tmpy<0&&abs(tmpx)+abs(tmpy)==10)continue;
        return false;
    }
   // for(int i=1;i<=5;i++){
   //     printf("%lld ",d[i]);
    //}
    //puts("");
    return true;
}
void dfs(){
    for(int i=1;i<=5;i++)d[i]=a[1][i];
    for(int i=1;i<=5;i++){
        int tmp=d[i];
        for(int j=0;j<=9;j++){
            if(d[i]!=j){
                d[i]=j;
                if(check())ans++;
            }
        }
        d[i]=tmp;
    }
    for(int i=1;i<=4;i++){
        int tmp1=d[i],tmp2=d[i+1];
        for(int j=1;j<=9;j++){
            d[i]=tmp1+j,d[i+1]=tmp2+j;
            d[i]%=10;d[i+1]%=10;
            if(check())ans++;
        }
        d[i]=tmp1,d[i+1]=tmp2;
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    dfs();
    printf("%lld\n",ans);
    return 0;
}
