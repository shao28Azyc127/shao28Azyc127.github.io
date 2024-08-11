#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,tookn,mod,days,ntook;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    bool took[n+1];

    memset(took,0,sizeof(took));
    while(tookn<n) {
        days++;
        mod=0;
        for(int i=1;i<=n;i++) {
            if(took[i]) {
                continue;
            }
            mod++;
            if(mod%3==1) {
                took[i]=1;
                tookn++;
                if(i==n) {
                    ntook=days;
                }
            }
        }

    }
    cout<<days<<" "<<ntook<<endl;

    return 0;
}
