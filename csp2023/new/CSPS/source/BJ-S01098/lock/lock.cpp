#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10][10],b[10];
bool t1[100010];
int ans=0,cnt=0;
bool check(){
    for(int i=1;i<=n;i++){
        int tmp[10]={};
        for(int j=1;j<=5;j++){
            if(b[j]<a[i][j]){
                tmp[j]=b[j]+10-a[i][j];
            }else{
                tmp[j]=b[j]-a[i][j];
            }
        }
        int t=0;
        for(int j=1;j<=5;j++){
            if(tmp[j]!=0&&t==0){
                t++;
            }else if(tmp[j]!=0&&t==1){
                t++;
                if(tmp[j]!=tmp[j-1]){
                    return false;
                }
            }else if(tmp[j]!=0&&t>=2){
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
        if(t1[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5]]==false){
            cnt++;
            t1[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5]]=true;
        }
    }
    for(b[1]=0;b[1]<10;b[1]++){
        for(b[2]=0;b[2]<10;b[2]++){
            for(b[3]=0;b[3]<10;b[3]++){
                for(b[4]=0;b[4]<10;b[4]++){
                    for(b[5]=0;b[5]<10;b[5]++){
                        if(check()==true){
                            ans++;
                            if(t1[b[1]*10000+b[2]*1000+b[3]*100+b[4]*10+b[5]]==true){
                                ans--;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
