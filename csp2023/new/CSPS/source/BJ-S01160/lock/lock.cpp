#include<bits/stdc++.h>
using namespace std;
int a[10],dat[10][10],ans,n;
int minusl(int x,int y){
    if(x-y>0) return x-y;
    return x-y+10;
}
bool cmp(int x){
    int v=0;
    for(int i=1;i<=5;i++)
        if(a[i]==dat[x][i]) v++;
    if(v==4) return true;
    if(v==3){
        if(a[1]==dat[x][1]&&a[2]==dat[x][2]&&a[3]==dat[x][3]&&minusl(a[5],a[4])==minusl(dat[x][5],dat[x][4])) return true;
        if(a[1]==dat[x][1]&&a[2]==dat[x][2]&&a[5]==dat[x][5]&&minusl(a[4],a[3])==minusl(dat[x][4],dat[x][3])) return true;
        if(a[1]==dat[x][1]&&a[4]==dat[x][4]&&a[5]==dat[x][5]&&minusl(a[3],a[2])==minusl(dat[x][3],dat[x][2])) return true;
        if(a[3]==dat[x][3]&&a[4]==dat[x][4]&&a[5]==dat[x][5]&&minusl(a[2],a[1])==minusl(dat[x][2],dat[x][1])) return true;
    }
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) cin>>dat[i][j];
    for(a[1]=0;a[1]<=9;a[1]++)
        for(a[2]=0;a[2]<=9;a[2]++)
            for(a[3]=0;a[3]<=9;a[3]++)
                for(a[4]=0;a[4]<=9;a[4]++)
                    for(a[5]=0;a[5]<=9;a[5]++){
                        bool flag=true;
                        for(int i=1;i<=n;i++)
                            if(!cmp(i)){flag=false;break;}
                        if(flag) ans++;
                    }
    cout<<ans<<endl;
    return 0;
}