#include <bits/stdc++.h>
using namespace std;
const int N=10,M=6;
int Lock[N][M];
int l[M];
int n,ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>Lock[i][j];
    for(l[1]=0;l[1]<10;l[1]++){
        for( l[2]=0;l[2]<10;l[2]++){
            for(l[3]=0;l[3]<10;l[3]++){
                for(l[4]=0;l[4]<10;l[4]++){
                    for(l[5]=0;l[5]<10;l[5]++){
                        int flag=1;
                        for(int i=1;i<=n;i++){
                            int cnt=0;
                            for(int j=1;j<=5;j++){
                                if(l[j]!=Lock[i][j]) cnt++;
                            }
                            if(cnt==0) {flag=0;break;}
                            if(cnt>2) {flag=0;break;}
                            if(cnt==1) continue;
                            for(int j=1;j<5;j++){
                                if(l[j]!=Lock[i][j]){
                                    if((l[j]-l[j+1]+10)%10!=(Lock[i][j]-Lock[i][j+1]+10)%10) {flag=0;break;}
                                }
                            }
                        }
                        if(flag) ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
