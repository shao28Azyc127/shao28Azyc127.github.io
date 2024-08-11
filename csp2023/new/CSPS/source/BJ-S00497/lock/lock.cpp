#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int a[5][n]={0},b[5];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            int tmp;
            cin>>tmp;
            a[j][i]=tmp;
        }
    }
    for(b[0]=0;b[0]<10;b[0]++)
    for(b[1]=0;b[1]<10;b[1]++)
    for(b[2]=0;b[2]<10;b[2]++)
    for(b[3]=0;b[3]<10;b[3]++)
    for(b[4]=0;b[4]<10;b[4]++)
    {
        bool o=1;
        for(int i=0;i<n;i++){
            bool z[5]={0};
            int s=0,mi=0;
            for(int j=0;j<5;j++)
            if(a[j][i]!=b[j]){
                z[i]=1;
                mi=j;
                s++;
            }
            for(int j=0;j<4;j++){
                if(z[j-1]&&!z[j])s++;
            }
            if(z[4])s++;
            if(s>3)o=0;
            if(s==0)o=0;
            if(s==3){
                int d1=(a[mi][i]+10-b[mi])%10;
                int d2=(a[mi-1][i]+10-b[mi-1])%10;
                if(d1!=d2)o=0;
            }
        }
        if(o)sum++;
    }
    cout<<sum;
    return 0;
}
