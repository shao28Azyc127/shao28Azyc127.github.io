#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][6];
long long ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int p=0;p<=9;p++){
                    for(int q=0;q<=9;q++){
                        int cnt=0;
                        bool f=true;
                        for(int r=1;r<=n;r++){
                            cnt=0;
                            if(a[r][1]!=i)cnt++;
                            if(a[r][2]!=j)cnt++;
                            if(a[r][3]!=k)cnt++;
                            if(a[r][4]!=p)cnt++;
                            if(a[r][5]!=q)cnt++;
                            if(cnt==0)f=false;
                            if(cnt>=3)f=false;
                            if(cnt==2){

                                int b[6];
                                b[1]=i;
                                b[2]=j;
                                b[3]=k;
                                b[4]=p;
                                b[5]=q;
                                for(int rp=1;rp<=5;rp++){
                                    if(b[rp]<a[r][rp]){
                                        b[rp]=b[rp]+10;
                                    }
                                    b[rp]-=a[r][rp];
                                }
                                for(int rp=1;rp<=4;rp++){
                                    if(b[rp]!=0&&b[rp]!=b[rp+1]){
                                        f=false;
                                    }
                                    if(b[rp]!=0&&b[rp-1]==b[rp]){
                                        f=true;
                                    }
                                }

                            }
                            if(f==false)break;
                        }
                        if(f==true){
                            ans++;
                            //cout<<i<<' '<<j<<' '<<k<<' '<<p<<' '<<q<<endl;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}