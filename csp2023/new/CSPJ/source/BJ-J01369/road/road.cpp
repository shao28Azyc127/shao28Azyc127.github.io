#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d,v[N],vq[N],a[N],di,o,pr=0;
inline int read(){
    char c=getchar();
    int r=0;
    while('0'<=c&&c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return r;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // cin>>n>>d;
    n=read();
    d=read();
    for(int i=1;i<=n-1;i++){
        v[i]=read();
        vq[i]=v[i]+vq[i-1];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<vq[i];
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int o=0;
    int di=o*d;
    int i=1;
    while(i<n){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                int cd=vq[j-1]-vq[i-1];
                // for(int k=i;k<=j-1;k++){
                //     cd+=v[k];
                // }   
                cd-=o;
                // cout<<cd<<endl;
                o=(ceil((cd*1.0)/(d*1.0))*d-cd);
                pr+=ceil((cd*1.0)/(d*1.0))*(a[i]);
                i=j;
                break;
            }
        }
    }
    cout<<pr<<endl;
    return 0;
}
/*5 4 
10 10 10 10 
9 8 9 6 5*/
