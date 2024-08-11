#include <iostream>
#include <cstdio>
using namespace std;
bool lock(int a[6],int b[6]){
    int d1=0,d2=0;
    if(a[1]!=b[1]){
        d1=1;
    }
    if(a[2]!=b[2]){
        if(d1){
            d2=2;
        }
        else{
            d1=2;
        }
    }
    if(a[3]!=b[3]){
        if(d2){
            return false;
        }
        else{
            if(d1){
                if(d1==1){
                    return false;
                }
                else{
                    d2=3;
                }
            }
            else{
                d1=3;
            }
        }
    }
    if(a[4]!=b[4]){
        if(d2){
            return false;
        }
        else{
            if(d1){
                if(d1!=3){
                    return false;
                }
                else{
                    d2=4;
                }
            }
            else{
                d1=4;
            }
        }
    }
    if(a[5]!=b[5]){
        if(d2){
            return false;
        }
        else{
            if(d1){
                if(d1!=4){
                    return false;
                }
                else{
                    d2=5;
                }
            }
            else{
                d1=5;
            }
        }
    }
    if(d1){
        if(d2){
            if((a[d2]-a[d1]+10)%10==(b[d2]-b[d1]+10)%10)
            {
                return true;
            }
            else{
                return false;
            }
        }else{
            return true;
        }
    }
    else{
        return false;
    }
}
int main()
{
    int n,a[10][6],ans=0;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<6;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<6;i++){
        for(int j=1;j<10;j++){
            bool r=true;
            a[1][i]=(a[1][i]+j)%10;
            for(int k=2;k<=n;k++){
                r&=lock(a[1],a[k]);
            }
            if(r){
                ans++;
            }
            a[1][i]=(a[1][i]+10-j)%10;
        }
    }
    for(int i=1;i<5;i++){
        for(int j=1;j<10;j++){
            bool r=true;
            a[1][i]=(a[1][i]+j)%10;
            a[1][i+1]=(a[1][i+1]+j)%10;
            for(int k=2;k<=n;k++){
                r&=lock(a[1],a[k]);
            }
            if(r){
                ans++;
            }
            a[1][i]=(a[1][i]+10-j)%10;
            a[1][i+1]=(a[1][i+1]+10-j)%10;
        }
    }
    cout<<ans;
    return 0;
}
