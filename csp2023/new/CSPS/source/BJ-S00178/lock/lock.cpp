#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][6];
int wei[6]={};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) cin >>a[i][j];
    }
    if(n==1){
        long long ans=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    for(int p=0;p<=9;p++){
                        for(int s=0;s<=9;s++){
                            int ci=0;
                            //int kn=0;
                            bool flag=0;
                            for(int lo=1;lo<=n && flag==0;lo++){
                                if(i!=a[lo][1] && j==a[lo][2] && k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j!=a[lo][2] && k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k!=a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p!=a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p==a[lo][4] && s!=a[lo][5]) ci++;
                                else if(i!=a[lo][1] && j!=a[lo][2] &&((10+i-a[lo][1])%10==(10+j-a[lo][2])%10)&& k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j!=a[lo][2] && k!=a[lo][3] &&((10+j-a[lo][2])%10==(10+k-a[lo][3])%10)&& p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k!=a[lo][3] && p!=a[lo][4] &&((10+k-a[lo][3])%10==(10+p-a[lo][4])%10)&& s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p!=a[lo][4] && s!=a[lo][5] &&((10+p-a[lo][4])%10==(10+s-a[lo][5])%10)) ci++;
                                if(ci<lo) flag=1;
                            }
                            if(ci==n){
                                ans++;
                            }

                        }
                    }
                }
            }
        }
        cout <<ans;
    }else{
        int xian[6]={};
        bool vis[6]={};
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int dif=0,weis[6]={};
                for(int s=1;s<=5;s++){
                    if(a[i][s]!=a[j][s]) dif++,weis[s]=1;
                }
                if(dif>=2){
                    for(int s=1;s<=5;s++){
                        if(a[i][s]==a[j][s]) wei[s]=a[i][s],vis[s]=1;
                    }
                }else if(dif==1){
                    for(int s=1;s<=5;s++){
                        if(a[i][s]!=a[j][s]){
                            int po=s-2;
                            while(po>0) wei[po]=a[i][po],vis[po]=1,po--;
                            po=s+2;
                            while(po<6) wei[po]=a[i][po],vis[po]=1,po++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++){
            if(vis[i]==1) xian[i]=wei[i];
            else xian[i]=9;
        }
        int t=0;
        long long ans=0;
        for(int i=wei[1];i<=xian[1];i++){
            for(int j=wei[2];j<=xian[2];j++){
                for(int k=wei[3];k<=xian[3];k++){
                    for(int p=wei[4];p<=xian[4];p++){
                        for(int s=wei[5];s<=xian[5];s++){
                            int ci=0;
                            //int kn=0;
                            bool flag=0;
                            for(int lo=1;lo<=n && flag==0;lo++){
                                if(i!=a[lo][1] && j==a[lo][2] && k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j!=a[lo][2] && k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k!=a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p!=a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p==a[lo][4] && s!=a[lo][5]) ci++;
                                else if(i!=a[lo][1] && j!=a[lo][2] &&((10+i-a[lo][1])%10==(10+j-a[lo][2])%10)&& k==a[lo][3] && p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j!=a[lo][2] && k!=a[lo][3] &&((10+j-a[lo][2])%10==(10+k-a[lo][3])%10)&& p==a[lo][4] && s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k!=a[lo][3] && p!=a[lo][4] &&((10+k-a[lo][3])%10==(10+p-a[lo][4])%10)&& s==a[lo][5]) ci++;
                                else if(i==a[lo][1] && j==a[lo][2] && k==a[lo][3] && p!=a[lo][4] && s!=a[lo][5] &&((10+p-a[lo][4])%10==(10+s-a[lo][5])%10)) ci++;
                                if(ci<lo) flag=1;
                            }
                            if(ci==n){
                                ans++;
                            }
                            t++;
                            //cout <<i <<" " <<j <<" " <<k <<" " <<p <<" " <<s <<'\n';
                        }
                    }
                }
            }
        }
        cout <<ans  <<'\n';//<<t;
    }
    return 0;
}
