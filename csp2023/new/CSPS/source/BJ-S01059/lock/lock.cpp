#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10];
int f[10][10][10][10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    //memset(f,1,sizeof(f));
    cin>>n;
    for(int I=1;I<=n;I++){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        //f[a[1]][a[2]][a[3]][a[4]][a[5]]--;
        for(int i=0;i<=9;i++){
            if(i!=a[1])f[i][a[2]][a[3]][a[4]][a[5]]++;
            if(i!=a[2])f[a[1]][i][a[3]][a[4]][a[5]]++;
            if(i!=a[3])f[a[1]][a[2]][i][a[4]][a[5]]++;
            if(i!=a[4])f[a[1]][a[2]][a[3]][i][a[5]]++;
            if(i!=a[5])f[a[1]][a[2]][a[3]][a[4]][i]++;
            if(i>0){
                int a1=(a[1]+i)%10;
                int a2=(a[2]+i)%10;
                int a3=(a[3]+i)%10;
                int a4=(a[4]+i)%10;
                int a5=(a[5]+i)%10;
                f[a1][a2][a[3]][a[4]][a[5]]++;
                f[a[1]][a2][a3][a[4]][a[5]]++;
                f[a[1]][a[2]][a3][a4][a[5]]++;
                f[a[1]][a[2]][a[3]][a4][a5]++;
            }
        }
    }
    for(int i1=0;i1<=9;i1++){
        for(int i2=0;i2<=9;i2++){
            for(int i3=0;i3<=9;i3++){
                for(int i4=0;i4<=9;i4++){
                    for(int i5=0;i5<=9;i5++){
                        if(f[i1][i2][i3][i4][i5]==n)ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
