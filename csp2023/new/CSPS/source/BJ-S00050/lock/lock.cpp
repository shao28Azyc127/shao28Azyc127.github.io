#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a1[10],a2[10],a3[10],a4[10],a5[10],a[10],ans,k,l1,l2,l3,l4,l5,cnt;
bool flg;
bool check(int ax,int ay,int lx,int ly){
    int tx,ty;
    if(ax-lx==0 || ay-ly==0)return false;
    for(int i=1;i<=9;i++){
        tx=(lx+i)%10;
        ty=(ly+i)%10;
        if(tx==ax){
            if(ty==ay)return true;
        }
    }
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i]>>a3[i]>>a4[i]>>a5[i];
        a[i]=a1[i]*10000+a2[i]*1000+a3[i]*100+a4[i]*10+a5[i];
    }
    for(int i=0;i<=99999;i++){
        flg=true;
        for(int j=1;j<=n;j++){
            cnt=0;
            l1=i/10000;
            l2=i/1000%10;
            l3=i/100%10;
            l4=i/10%10;
            l5=i%10;
            if(l1-a1[j]!=0)cnt++;
            if(l2-a2[j]!=0)cnt++;
            if(l3-a3[j]!=0)cnt++;
            if(l4-a4[j]!=0)cnt++;
            if(l5-a5[j]!=0)cnt++;
            if(cnt==2){
                if(!check(a1[j],a2[j],l1,l2) && !check(a2[j],a3[j],l2,l3) && !check(a3[j],a4[j],l3,l4) && !check(a4[j],a5[j],l4,l5)){
                    flg=false;
                    break;
                }
            }
            else if(cnt!=1){
                flg=false;
                break;
            }
        }
        if(flg)ans++;
    }
    cout<<ans;
    return 0;
}
