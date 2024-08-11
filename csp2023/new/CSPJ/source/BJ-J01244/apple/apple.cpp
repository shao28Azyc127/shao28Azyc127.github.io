#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long n2=n,k=2,s=0;
    bool a[n+1]={0};
    long long date=1,time=0;
    while(n2>0){
        if(s==0){
            k=2;
        }
        s++;
        if(s>n){
            s=0;
            date++;
            k=0;
        }
        if(a[s]){
            continue;
        }
        k++;
        if(k==3){
            k=0;
            a[s]=true;
            n2--;
            if(s==n){
                time=date;
            }
        }
    }
    cout<<date<<" "<<time;
    return 0;
}
