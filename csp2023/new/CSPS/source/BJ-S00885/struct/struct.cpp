#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,fg,k;
    string s,ss;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>fg;
        if(fg==1){
            cin>>s>>k;
            for(int j=1; j<=k; j++){
                cin>>s>>ss;
            }cout<<k*8<<" "<<8<<endl;
        }
    }return 0;
}
