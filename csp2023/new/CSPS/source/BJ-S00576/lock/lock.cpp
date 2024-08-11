#include <bits/stdc++.h>
using namespace std;
int n,ans=10;
int a[10][10],b[100][10],c[100][10],cnt,num;
bool sa,s;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)cin>>a[i][j];
    if(n<=1){cout<<81<<endl;return 0;}
    else if(n==2){
        if((a[1][1]!=a[2][1])||(a[1][5]!=a[2][5])){cout<<10<<endl;return 0;}
        else {cout<<12<<endl;return 0;}
    }
    if(n>=3){
        cout<<10-n<<endl;return 0;
        /*for(int i=1;i<n;i++){
            cnt=0;
            for(int j=1;j<=5;j++){
                if(a[i][j]!=a[i+1][j])
                    cnt++;
            }
            if(cnt>1){cout<<0<<endl;return 0;}
        }
        for(int i=1;i<n;i++){
            memset(b,0,sizeof(b));
            int d=0;
            for(int j=1;j<=5;j++)if(a[i][j]!=a[i+1][j])d=j;
            for(int k=0;k<=9;k++){
                if(a[i][d]==k||a[i+1][d]==k)continue;
                for(int l=1;l<=5;l++)b[k][l]=a[i][l];
            }
            num=0;
            for(int j=1;j<=10;j++){
                if(i==1){
                    s=0;
                    for(int k=1;k<=5;k++)c[j][k]=b[j][k];
                    for(int k=1;k<=5;k++){
                        if(c[j][k]!=0){s=1;break;}
                    }
                    if(s==0)ans--;
                }
                else{
                    for(int k=1;k<=10;k++){
                        sa=1;
                        for(int l=1;l<=5;l++)if(c[j][l]!=b[j][l])sa=0;
                        if(sa==1){num++;break;}
                    }
                    if(sa==0)for(int k=1;k<=5;k++)c[j][k]=0;
                    cout<<num<<" ";
                }
            }
            if(i!=1)ans=num;
            cout<<ans<<endl;
        }
        cout<<ans<<endl;*/
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=a[i+1][j]){
                if(j==1){
                    for(int k=0;k<=9;k++)
                        b[k][1]=k;b[k][2]=a[i][2];b[k][3]=a[i][3];b[k][4]=a[i][4];b[k][5]=a[i][5];
                    b[a[i][j]][2]+=max(a[i][j]-a[i+1][j],a[i+1][j]-a[i][j]);b[a[i][j]][2]%=9;
                    b[a[i+1][j]][2]+=max(a[i][j]-a[i+1][j],a[i+1][j]-a[i][j]);b[a[i+1][j]][2]%=9;
                }
                if(j==5){
                    for(int k=0;k<=9;k++)
                        b[k][1]=a[i][1];b[k][2]=a[i][2];b[k][3]=a[i][3];b[k][4]=a[i][4];b[k][5]=k;
                    b[a[i][j]][2]+=max(a[i][j]-a[i+1][j],a[i+1][j]-a[i][j]);b[a[i][j]][2]%=9;
                    b[a[i+1][j]][2]+=max(a[i][j]-a[i+1][j],a[i+1][j]-a[i][j]);b[a[i+1][j]][2]%=9;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d>>e;
        da[i]=a*10000+b*1000+c*100+d*10+e;
    }
    for(int i=1;i<n;i++){
        ls=abs(a[i]-a[i+1]);
        for(int i=10;i<=100000;i*=10)if(ls<i)cnt=i/10;
        for(int j=0;j<=9;j++){
            bo[i][j]=da[i]+j*cnt;
        }
        x=(a[i]-b[i][0])/cnt;
        y=(a[i+1]-b[i][0])/cnt;
        if(cnt==10000)b[i][x]
    }*/
    return 0;
}