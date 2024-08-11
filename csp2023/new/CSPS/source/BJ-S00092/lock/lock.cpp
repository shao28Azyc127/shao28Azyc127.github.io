#include<iostream>
using namespace std;
int n, l[20][20], f[11][11][11][11][11]={0};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w", stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>l[i][j];
        }
    }/*
    if (n==1){
        cout<<81<<endl;
        return 0;
    }*/
    for (int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int b=1;b<10;b++){
                if(j==0){
                    f[(l[i][0]+b)%10][l[i][1]][l[i][2]][l[i][3]][l[i][4]]++;
                }else if(j==1){
                    f[(l[i][0])%10][(l[i][1]+b)%10][l[i][2]][l[i][3]][l[i][4]]++;
                }else if(j==2){
                    f[(l[i][0])%10][(l[i][1])%10][(l[i][2]+b)%10][l[i][3]][l[i][4]]++;
                }else if(j==3){
                    f[(l[i][0])%10][(l[i][1])%10][(l[i][2])%10][(l[i][3]+b)%10][l[i][4]]++;
                }else{
                    f[(l[i][0])%10][(l[i][1])%10][(l[i][2])%10][l[i][3]][(l[i][4]+b)%10]++;
                }
            }
            if(j!=4){
                for(int b=1;b<10;b++){
                                    if(j==0){
                    f[(l[i][0]+b)%10][(l[i][1]+b)%10][l[i][2]][l[i][3]][l[i][4]]++;
                }else if(j==1){
                    f[(l[i][0])%10][(l[i][1]+b)%10][(l[i][2]+b)%10][l[i][3]][l[i][4]]++;
                }else if(j==2){
                    f[(l[i][0])%10][(l[i][1])%10][(l[i][2]+b)%10][(l[i][3]+b)%10][l[i][4]]++;
                }else {
                    f[(l[i][0])%10][(l[i][1])%10][(l[i][2])%10][(l[i][3]+b)%10][(l[i][4]+b)%10]++;
                }
                }
            }
        }
    }
    int ans=0;
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                for (int d=0;d<10;d++){
                    for(int e=0;e<10;e++){
                        if(f[a][b][c][d][e]==n){
                            ans++;
                            //cout<<a<<b<<c<<d<<e<<endl;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return  0;
}
