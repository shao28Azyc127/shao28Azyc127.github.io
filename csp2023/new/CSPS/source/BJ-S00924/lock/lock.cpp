#include <iostream>
#include <cstdio>
#define mod 10
#define N 10
using namespace std;
int a[N][5];
int n;

bool check(int f[]){
    bool istrue=true;
    for(int k=0;k<n;k++){
        int change=0;
        for(int c=0;c<5;c++){
            if(f[c] != a[k][c]){
                if(change){
                    istrue = false;
                    break;
                }
                else{
                    change = c+1;
                }
            }
        }

        if(change == 0)
            return false;

        if(!istrue){
            istrue = true;
            change = 0;
            for(int c=0;c<=3;c++){
                if(f[c] != a[k][c]){
                    if((a[k][c]-a[k][c+1]+mod)%mod == (f[c]-f[c+1]+mod)%mod){
                        if(change){
                            istrue = false;
                            break;
                        }
                        else{
                            change = c+1;
                            c++;
                        }
                    }
                    else{
                        istrue = false;
                    }
                }
            }
            if(change != 4  &&  f[4] != a[k][4])
                istrue = false;
        }
    }
    return istrue;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }

    int f[5];
    for(int i=0;i<5;i++){
        f[i] = a[0][i];
    }


    int ans=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<=9;j++){
            f[i] = (f[i]+j)%mod;

            /*
                for(int i=0;i<5;i++)
                    cout<<f[i]<<" ";
                cout<<check(f);
                cout<<endl;
*/
                
            if(check(f)){
                ans++;
            }


            f[i] = (f[i]+mod-j)%mod;
        }
    }

    for(int i=0;i<=3;i++){
        for(int j=1;j<=9;j++){
            f[i] = (f[i]+j)%mod;
            f[i+1] = (f[i+1]+j)%mod;
/*
            for(int i=0;i<5;i++)
                cout<<f[i]<<" ";
            cout<<check(f);
            cout<<endl;
*/
            if(check(f)){
                ans++;
            }

            f[i] = (f[i]+mod-j)%mod;
            f[i+1] = (f[i+1]+mod-j)%mod;
        }
    }

    cout<<ans<<endl;
    return 0;
}
