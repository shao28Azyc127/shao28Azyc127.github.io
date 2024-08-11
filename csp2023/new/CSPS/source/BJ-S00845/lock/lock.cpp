#include<bits/stdc++.h>
using namespace std;
const int M=100005;
int a[5];
int cnt[M];
inline void add(){
    int now=0;
    for(int i=0;i<5;i++){
        now=now*10+a[i];
    }
    cnt[now]++;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++) scanf("%d",&a[j]);
        for(int j=0;j<5;j++){
            int pre=a[j];
            for(int l=0;l<10;l++){
                if(l!=pre){
                    a[j]=l;
                    add();
                }
            }
            a[j]=pre;
        }
        for(int j=0;j<4;j++){
            for(int l=0;l<9;l++){
                a[j]=(a[j]+1)%10;
                a[j+1]=(a[j+1]+1)%10;
                add();
            }
            a[j]=(a[j]+1)%10;
            a[j+1]=(a[j+1]+1)%10;
        }
    }
    int ans=0;
    for(int i=0;i<M;i++){
        if(cnt[i]==n) ans++;
    }
    cout<<ans;
    return 0;
}