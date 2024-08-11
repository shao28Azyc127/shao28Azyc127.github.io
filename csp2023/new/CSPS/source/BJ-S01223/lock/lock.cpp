#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int num0=0,num1=0,num2=0,num3=0,num4=0,num5=0;
    for(int i=0;i<n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i]>>a[4][i];
    }
    if(n==1){
        cout<<81;
        return 0;
    }if(n==2){
        for(int i=0;i<n-1;i++){
            if(a[0][i]!=a[0][i+1]){
                num0++;
            }
            if(a[1][i]!=a[1][i+1]){
                num1++;
            }
            if(a[2][i]!=a[2][i+1]){
                num2++;
            }
            if(a[3][i]!=a[3][i+1]){
                num3++;
            }
            if(a[4][i]!=a[4][i+1]){
                num4++;
            }
        }
        if((num0&&!num1&&!num2&&!num3&&!num4)||(!num0&&num1&&!num2&&!num3&&!num4)||(!num0&&!num1&&num2&&!num3&&!num4)||(!num0&&!num1&&!num2&&num3&&!num4)||(!num0&&!num1&&!num2&&!num3&&num4)){
            cout<<10;
            return 0;
        }else{
            cout<<2;
            return 0;
        }
    }

    for(int i=0;i<n-1;i++){
        if(a[0][i]!=a[0][i+1]){
            num0++;
        }
        if(a[1][i]!=a[1][i+1]){
            num1++;
        }
        if(a[2][i]!=a[2][i+1]){
            num2++;
        }
        if(a[3][i]!=a[3][i+1]){
            num3++;
        }
        if(a[4][i]!=a[4][i+1]){
            num4++;
        }
    }
    if((num0&&!num1&&!num2&&!num3&&!num4)||(!num0&&num1&&!num2&&!num3&&!num4)||(!num0&&!num1&&num2&&!num3&&!num4)||(!num0&&!num1&&!num2&&num3&&!num4)||(!num0&&!num1&&!num2&&!num3&&num4)){
        cout<<10-n;
        return 0;
    }else{
        cout<<1;
        return 0;
    }
    cout<<10;

    return 0;
}
