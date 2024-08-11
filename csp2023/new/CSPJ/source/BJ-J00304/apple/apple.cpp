#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)a[i]=0;
    int cnt=n;
    int mark=0,time=0;int m=2;
    while(cnt>0){
        m=2;
        time++;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                m++;
                if(m==3){
                    a[i]=1;
                    cnt--;
                    m=0;
                    if(i+1==n){
                        mark=time;
                    }
                }
            }

        }
    }
    cout<<time<<" "<<mark;
    return 0;
}