#include<bits/stdc++.h>
using namespace std;
bool a[1000000002];
int ds;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,w=0,co=0;
    cin>>n;
    while(ans<n){
        int z=0;
        co++;
        //cout<<"co"<<co<<endl;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                continue;
            }
            if(i==n){
                ds++;
            }
            w++;
            if(w==3 or z==0){
                a[i]=1;
                ans++;
                //cout<<"----"<<"6"<<endl;
                w=0;
                z++;
            }
            //cout<<i<<" "<<a[i]<<" "<<w<<endl;
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/
    cout/*<<endl*/<<co<<" "<<ds;
    return 0;
}
