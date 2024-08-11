#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int s=0;s<=9;s++){
                    for(int t=0;t<=9;t++){
                        int tot=1;
                        for(int m=1;m<=n;m++){
                            int flag=0;
                            int cag=0;
                            int v[6];
                            v[1]=100004;
                            v[2]=100005;
                            v[3]=100006;
                            v[4]=100007;
                            v[5]=100008;
                            if(i!=a[m][1]){
                                v[1]=i-a[m][1];
                                flag++;
                            }
                            if(j!=a[m][2]){
                                v[2]=j-a[m][2];
                                flag++;
                            }
                            if(k!=a[m][3]){
                                v[3]=k-a[m][3];
                                flag++;
                            }
                            if(s!=a[m][4]){
                                v[4]=s-a[m][4];
                                flag++;
                            }
                            if(t!=a[m][5]){
                                v[5]=t-a[m][5];
                                flag++;
                            }
                            if(flag==1){
                                cag=1;
                            }else if(flag==2){
                                if(v[1]==v[2]||v[2]==v[3]||v[3]==v[4]||v[4]==v[5]){
                                    cag=1;
                                }
                            }
                            if(cag==0){
                                tot=0;
                                break;
                            }
                        }
                        sum+=tot;
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
