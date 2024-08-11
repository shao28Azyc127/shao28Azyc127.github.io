#include <bits/stdc++.h>
using namespace std;
const int N=10;
int t,n=5,a[N][N],tmp[N];
bool vis[100000+10];
long long ans;
bool check(){
    for(int id=1;id<=t;id++){
        int pos1=-1,pos2=-1;
        for(int i=1;i<=n;i++){
            if(a[id][i]!=tmp[i]){
                if(pos1==-1) pos1=i;
                else if(pos2==-1) pos2=i;
                else return false;
            }
        }
        if(pos1==-1) return false;
        else if(pos2==-1) continue;
        else if(pos2==pos1+1 && (tmp[pos1]-a[id][pos1]+10)%10==(tmp[pos2]-a[id][pos2]+10)%10) continue;
        else return false;
    }
    int num=0;
    for(int i=1;i<=n;i++) num=num*10+tmp[i];
    if(vis[num]==1) return false;
    vis[num]=1;
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&t);
    for(int id=1;id<=t;id++)
        for(int i=1;i<=n;i++) scanf("%d",&a[id][i]);
    if(t==1){printf("%lld\n",(long long)(2*n-1)*9);return 0;}
    for(int id=1;id<=t;id++){
        for(int i=1;i<=n;i++){
            memcpy(tmp,a[id],sizeof(a[id]));
            for(int num=0;num<=9;num++) if(tmp[i]!=num){
                tmp[i]=num;
                if(check()) ans+=1;
                tmp[i]=a[id][i];
            }
        }
        for(int i=1;i<=n-1;i++){
            memcpy(tmp,a[id],sizeof(a[id]));
            for(int num=-9;num<=9;num++){
                tmp[i]=(a[i][id]+num+10)%10;tmp[i+1]=(a[id][i+1]+num+10)%10;
                if(tmp[i]==a[id][i] || tmp[i+1]==a[id][i+1]) continue;
                if(check()) ans++;
                tmp[i]=a[id][i],tmp[i+1]=a[id][i+1];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}