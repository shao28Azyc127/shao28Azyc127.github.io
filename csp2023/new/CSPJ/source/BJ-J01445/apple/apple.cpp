#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
int cmp(int q,int p){
    return q<p;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,tian=0,dijitian;
    cin>>n;
    bool b=0;
    int m=n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(m>0){
        int k=0;
        for(int i=1;i<=m;i+=3){
            if(a[i]=n&&b==0){
                dijitian=tian+1;
                b=1;
            }
            a[i]=n+5;
            k++;
        }
        m-=k;
        sort(a+1,a+n+1,cmp);
        tian++;
    }
    cout<<tian<<" "<<dijitian;
    return 0;
}


