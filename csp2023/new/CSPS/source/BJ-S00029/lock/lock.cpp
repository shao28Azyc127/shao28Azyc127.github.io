#include<bits/stdc++.h>
using namespace std;// 1 2 3 4 5
int a[100000];
int f[6],f1[6];
int quyu(int a,int b){
    return a-a/b*b;
}
int main(){
    int n,s,ans=0;
    cin >>n;
    for(int i=0;i<n;i++){
        for(int p=0;p<5;p++){
            cin >>f[p];
            f1[p]=f[p];
        }

        for(int j=0;j<5;j++){
            for(int k=1;k<=9;k++){
                f[j]+=k;
                f[j]%=10;
                int l=(f[0])*10000+(f[1])*1000+(f[2])*100+(f[3])*10+f[4];
                a[l]++;
                if(j!=0){
                    f[j-1]+=k;
                    f[j-1]%=10;
                    l=f[0]*10000+f[1]*1000+f[2]*100+f[3]*10+f[4];
                    a[l]++;
                }
                f[j-1]=f1[j-1];
                f[j]=f1[j];
            }
        }
    }
    for(int i=0;i<100000;i++){
        if(a[i]==n)ans++;
    }
    cout <<ans;
    return 0;
}
