#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[10][6],flag,now=1,ans;
bool check(int a,int b,int c,int d,int e, int f,int g,int h,int i,int j){
    flag=0;
    int v[6];
    v[1]=(a-f+10)%10,v[2]=(b-g+10)%10,v[3]=(c-h+10)%10,v[4]=(d-i+10)%10,v[5]=(e-j+10)%10;
    for(int p=1;p<=5;p++){
        if(v[p]){
            if(v[p]==v[p+1])
                flag++,p++;
            else    flag++;
        }
    }
    if(flag==1) return true;
    else return 0;
}
//0 0 0 0 4
//0 0 1 1 5
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        now=1;
                        for(int s=1;s<=n;s++){
                            if(!check(a[s][1],a[s][2],a[s][3],a[s][4],a[s][5],i,j,k,l,m))
                                now=0;
                        }
                        if(now)
                            ans++/*,printf("%d%d%d%d%d\n",i,j,k,l,m)*/;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
