#include<bits/stdc++.h>
using namespace std;
const int NN=1000;
int n;
int ans=0;
int a[NN],a2[NN];
int b[NN],b2[NN],b3[NN],b4[NN],b5[NN],b6[NN];
//01 01 10 10 11 11
void ff(int x[],int y[]){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(x[i]==y[j]){
                ans++;
            }
        }
    }
}
int main(){

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int z=1;z<=n;z++){
        for(int i=1;i<=5;i++){
            cin>>a2[i];
        }
        if(n==2&&z==1){
            for(int i=1;i<=5;i++){
                a[i]=a2[i];
            }
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    if(n==2){
        int k;
        for(int i=1;i<=5;i++){
            if(a[i]!=a2[i]){
                k=i;
            }
        }
        if(k==5){
            int x=1,j;
            j=0;
            while(x!=10){
                if(a[5]+x>=10){
                    b[++j]=a[4]*10+a[5]+x-10;
                }else{
                    b[++j]=a[4]*10+a[5]+x;
                }
                x++;
            }//a 01;
            x=1;
            j=0;
            while(x!=10){
                if(a2[5]+x>=10){
                    b2[++j]=a2[4]*10+a2[5]+x-10;
                }else{
                    b2[++j]=a2[4]*10+a2[5]+x;
                }
                x++;
            }//b 01;
            j=0;
            x=1;
            while(x!=10){
                if(a[4]+x>=10){
                    b3[++j]=(a[4]+x)*10-100+a[5];
                }else{
                    b3[++j]=(a[4]+x)*10+a[5];
                }
                x++;
            }//a 10;
            x=1;
            j=0;
            while(x!=10){
                if(a2[4]+x>=10){
                    b4[++j]=(a2[4]+x)*10-100+a2[5];
                }else{
                    b4[++j]=(a2[4]+x)*10+a2[5];
                }
                x++;
            }//b 10;

            x=1;
            j=0;
            int s;
            while(x!=10){
                s=(a[4]+x)*10;
                j++;
                if(s>=100){
                    b5[j]=s-100+a[5]+x;
                    s=s-100;
                }
                if(a[5]+x>=10){
                    b5[j]=s+a[5]+x-10;
                }

                else{
                    b5[j]=s+a[5]+x;
                }
                x++;
            }//a 11;

            x=1;
            j=0;
            while(x!=10){
                s=(a2[4]+x)*10;
                j++;
                if(s>=100){
                    b6[j]=s-100+a2[5]+x;
                    s=s-100;
                }
                if(a2[5]+x>=10){
                    b6[j]=s+a2[5]+x-10;
                }
                else{
                    b6[j]=s+a2[5]+x;
                }
                x++;
            }//b 11;
            ff(b,b2);
            ff(b,b4);
            ff(b,b6);

            ff(b3,b2);
            ff(b3,b4);
            ff(b3,b6);

            ff(b5,b2);
            ff(b5,b4);
            ff(b5,b6);
            cout<<ans;

        }

    }
    return 0;
}
