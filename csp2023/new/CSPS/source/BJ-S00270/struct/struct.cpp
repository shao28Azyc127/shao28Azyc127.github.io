#include<bits/bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i],b[i],c[i];
        if(a[i]==1){
            int d[c[i]],e[c[i]];
            int num=0;
            if(b[i]==a){
                num+=4;
            }else if(b[i]==b){
                num+=8;
            }
            for(int j=1;j<=c[i];j++){
                cin>>d[j]>>e[j];
                if(d[j]=="short"){
                    num+=3;
                }else if(d[j]=="int"){
                    num+=1;
                }
            }
        }
    }

    return 0;
}
