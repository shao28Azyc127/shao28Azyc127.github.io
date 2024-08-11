#include<iostream>
using namespace std;
int n,a[10][10],nw[5],s,ans,p1,p2,ans1,ans2,cnt,d1,d2;
bool f;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i<10;i++){
        nw[1]=i;
        for(int j = 0;j<10;j++){
            nw[2]=j;
            for(int k = 0;k<10;k++){
                nw[3]=k;
                for(int l = 0;l<10;l++){
                    nw[4]=l;
                    for(int m = 0;m<10;m++){
                        nw[5]=m;
                        f=false;
                        for(int nn=1;nn<=n;nn++){
                            cnt=p1=p2=d1=d2=0;
                            for(int x=1;x<=5;x++){
                                if(nw[x]!=a[nn][x]){
                                    cnt++;
                                    if(p1==0){
                                        p1=x;
                                        d1=nw[x]-a[nn][x];
                                    }
                                    else if(p2==0&&p1==x-1){
                                        d2=nw[x]-a[nn][x];
                                        int y=(nw[p1]-d2+10)%10;
                                        if(y==a[nn][p1])p2=x;
                                        else{
                                            f=true;
                                            break;
                                        }
                                    }
                                    else{
                                        f=true;
                                        break;
                                    }
                                }
                            }
                            if(cnt==0){
                                f=true;
                                break;
                            }
                        }
                        if(!f){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
