#include<iostream>
using namespace std;
int n;
int a,b,c;
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a>>b>>c;
        if(a==0) {
            if(c==0) cout<<0;
            else {
                if(a<0) cout<<"sqrt(-c/a)";
                else cout<<"NO";
            }
        }
    }
    return 0;
}
