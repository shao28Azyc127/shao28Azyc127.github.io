#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],b[10],ans=0;
int upz(int x,int y){
    if(x<y)return y-x;
    else{
        return 9-x+1+y;
    }
}
int downz(int x,int y){
    if(x>y)return x-y;
    else{
        return x-0+1+(9-y);
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        int wza=-1,wzb=-1;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=b[j]){
                if(wza==-1)wza=j;
                else if(wzb==-1)wzb=j;
                else return false;
            }
        }
        if(wza==-1)return false;
        else if(wzb==-1);
        else{
            if(wzb-wza!=1)return false;
            int za,zb;
            za=upz(a[i][wza],b[wza]);
            zb=upz(a[i][wzb],b[wzb]);
            if(za==zb)continue;
            za=downz(a[i][wza],b[wza]);
            zb=downz(a[i][wzb],b[wzb]);
            if(za==zb)continue;
            return false;
        }
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int l=0;l<=9;l++){
                for(int r=0;r<=9;r++){
                    for(int k=0;k<=9;k++){
                        b[1]=i,b[2]=j,b[3]=l,b[4]=r,b[5]=k;
                        if(check()){
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
