#include<bits/stdc++.h>
long long n,d,l[100005],m[100005],ans=0,e=0;
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1;i<n;i++){
        cin>>l[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>m[i];
    }
    int i = 1;
    while(i!=n){
        int j = i;
        long long  mi = 0;
        while(m[j]>=m[i]&&j!=n){
            mi+=l[j];
            j++;
        }
        if(mi>e){
            ans+=((mi-e-1)/d+1)*m[i];
            e=e+((mi-e-1)/d+1)*d-mi;
        }
        else   e-=mi;
        i=j;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}