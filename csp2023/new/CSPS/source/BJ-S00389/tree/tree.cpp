#include<iostream>
using namespace std;
long long max(long long x,int y){
    if(x>y) return x;
    return y;
}
long long a[510],l[510];
int b[510];
int c[510], u[510], v[510];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        l[i] = 0;
    }
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
    }
    long long cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l[i]+=max(b[i],1);

            if(l[i]>=a[i]){
                continue;
            }
            cnt++;
        }


    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}