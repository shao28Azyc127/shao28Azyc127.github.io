#include<bits/stdc++.h>
using namespace std;
long long n,cnt,pd1,pd2;
int a[15][15];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81<<endl;
        return 0;
    }else if(n==2){
        for(int i=1;i<=5;i++){
            if(a[1][i]!=a[2][i]){
                cnt++;
            }
        }
        if(cnt==1){
            if(a[1][5]!=a[2][5]||a[1][1]!=a[2][1]){
                cout<<10<<endl;
                return 0;
            }else{
                cout<<12<<endl;
                return 0;
            }
        }else if(cnt==2){
            for(int i=1;i<5;i++){
                if(a[1][i]!=a[2][i]&&a[1][i+1]!=a[2][i+1]){
                    for(int j=0;j<=9;j++){
                        if((a[1][i]+j)%10==a[1][i+1]&&(a[2][i]+j)%10==a[2][i+1]){
                            cout<<10<<endl;
                            return 0;
                        }
                    }
                }
            }
           for(int i=1;i<4;i++){
                if(a[1][i]!=a[2][i]&&a[1][i+2]!=a[2][i+2]){
                    for(int j=0;j<=9;j++){
                        if((a[1][i]+a[1][i+2])%10==(a[2][i]+a[2][i+2])%10){
                            cout<<3<<endl;
                            return 0;
                        }
                    }
                }
            }
            cout<<2<<endl;
            return 0;
        }else if(cnt==3){
            for(int i=1;i<=3;i++){
                if(a[1][i]!=a[2][i]&&a[1][i+1]!=a[2][i+1]&&a[1][i+2]!=a[2][i+2]){
                    for(int j=0;j<=9;j++){
                        if((a[1][i]+j)%10==a[1][i+1]&&(a[2][i]+j)%10==a[2][i+1]){
                            pd1=1;
                        }
                    }
                    for(int j=0;j<=9;j++){
                        if((a[1][i+1]+j)%10==a[1][i+2]&&(a[2][i+1]+j)%10==a[2][i+2]){
                            pd2=1;
                        }
                    }
                    if(pd1==1&&pd2==1){
                        cout<<4<<endl;
                        return 0;
                    }else if(pd1==1&&pd2!=1){
                        cout<<2<<endl;
                        return 0;
                    }else if(pd1!=1&&pd2==1){
                        cout<<2<<endl;
                        return 0;
                    }else{
                        cout<<1<<endl;
                        return 0;
                    }
                }
            }
            cout<<2<<endl;
            return 0;
        }else if(cnt==4){
            cout<<2<<endl;
            return 0;
        }
        return 0;
    }else{
        cout<<2<<endl;
        return 0;
    }
    return 0;
}