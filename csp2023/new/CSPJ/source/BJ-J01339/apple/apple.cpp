#include<iostream>
using namespace std;
const int N=1e9+5;
int a[N]={};
int main(){
    freopen("apple.in",r);
    freopen("apple.out",w);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=1;
    int cnt=1,s;
    int m=n,x=n;
    int j=0;
    while(m>0){
        cnt++;
        for(int i=x;i<=n;i+=2){
            if(i==n&&a[i]!=0)s=cnt;
            if(a[i]!=0){
                j++;
                a[i]=0;
                x=min(x,i);
            }
        }
        m-=j;
        j=0;
        x++;
    }
    cout<<cnt<<" "<<s;
    fclose();
    return 0;
}