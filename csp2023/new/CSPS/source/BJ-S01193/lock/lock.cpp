#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int n;
int may[1000][10],cnt,ans;
int flag[1000];
int x[10];
int cha[10],num;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=5;i++){
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=5;i++){
        for(int add=1;add<=9;add++){
            cnt++;
            for(int k=1;k<=5;k++)may[cnt][k]=x[k];
            may[cnt][i]=(may[cnt][i]+add)%10;
            if(i<=4){
                cnt++;
                for(int k=1;k<=5;k++)may[cnt][k]=x[k];
                may[cnt][i]=(may[cnt][i]+add)%10;
                may[cnt][i+1]=(may[cnt][i+1]+add)%10;
            }
        }
    }
    ans=cnt;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++)
            scanf("%d",&x[j]);

        for(int j=1;j<=cnt;j++){
            num=0;
            if(flag[j])continue;
            for(int k=1;k<=5;k++){
                if(may[j][k]!=x[k])num++;
                cha[k]=may[j][k]-x[k];
            }

            if(num==0 || num>2){flag[j]=1;ans--;continue;}
            if(num==1)continue;
            for(int k=1;k<=5;k++){
                if(cha[k]!=0 && !(cha[k+1]==cha[k] || cha[k-1]==cha[k]))
                    {flag[j]=1;ans--;break;}
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
