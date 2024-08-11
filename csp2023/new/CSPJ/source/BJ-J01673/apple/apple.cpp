#include<iostream>
#include<cstdio>
using namespace std;
int a[10001];
bool abc(int n){
    bool flag=false;
for(int i=1;i<=n;i++){
        if(a[i]==0)flag=true;
        else flag=false;
    }
    return flag;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,k=-1,sum=0,nm=0,g=0;
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=1;
    while(abc(n)==0){
        sum++;
        g++;
        for(int i=g;i<=n;i++){
            k++;
            if(i==n||i==n-1)nm=sum;
            if(a[i]!=0){
                if(i==g||k==3){
                    a[i]-=1;
                    k=0;
                }
            }else k--;
        }
    }
    cout<<sum-1<<" "<<nm-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}