#include<iostream>
using namespace std;
int a[15][10];
int b[6];
int main(){
    ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(b[1]=0;b[1]<=9;b[1]++){
        for(b[2]=0;b[2]<=9;b[2]++){
            for(b[3]=0;b[3]<=9;b[3]++){
                for(b[4]=0;b[4]<=9;b[4]++){
                    for(b[5]=0;b[5]<=9;b[5]++){
                        bool f=true;
                        for(int i=1;i<=n;i++){
                            int cnt1=0,cnt2=0;
                            for(int j=1;j<=5;j++){
                                if(b[j]==a[i][j]){
                                    cnt2++;
                                }
                            }
                            if(cnt2==4){
                                continue;
                            }
                            cnt1=0;
                            for(int j=1;j<=4;j++){
                                if((b[j]-a[i][j]+20)%10==(b[j+1]-a[i][j+1]+20)%10&&b[j]-a[i][j]!=0){
                                    cnt1++;
                                }
                            }
                            if(cnt1==1&&cnt2==3){
                                continue;
                            }
                            f=false;
                            break;
                        }
                        ans+=f;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
/*rp+=inf*/
