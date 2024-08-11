#include<cstdio>
using namespace std;
int code=0, ans=0;
int n,st[10][6];
int d(int n){
    if(n==5) return code%10;
    if(n==4) return (code%100)/10;
    if(n==3) return (code%1000)/100;
    if(n==2) return (code%10000)/1000;
    if(n==1) return code/10000;
    return -1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d%d",st[i]+1,st[i]+2,st[i]+3,st[i]+4,st[i]+5);
    }
    while(code<100000){
        int possible=0;
        for(int i=0;i<n;++i){
            int diff[6], diffnum=0, diff1=0, diff2=0;
            for(int j=1;j<6;++j){
                diff[j]=st[i][j]-d(j);
                diffnum+=!!diff[j];
                if(!diff1 && diff[j]) diff1=j;
                else if(!diff2 && diff[j]) diff2=j;
            }
            if(diff1 && diff[diff1]<0) diff[diff1]+=10;
            if(diff2 && diff[diff2]<0) diff[diff2]+=10;
            if(diffnum>2 || !diffnum) break;
            if(diffnum==1){
                ++possible; continue;
            }
            if(diffnum==2){
                if((diff1-diff2==1 || diff1-diff2==-1) && diff[diff1]==diff[diff2]){
                    ++possible; continue;
                }
                else break;
            }
        }
        if(possible==n) ++ans;
        ++code;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
