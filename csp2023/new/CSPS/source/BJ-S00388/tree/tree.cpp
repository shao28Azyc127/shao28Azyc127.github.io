#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+5;
int n;
long long a[M];//mu biao 
int b[M],c[M];//pan duan tiao jian

int u[M],v[M];//ju li

int ans = 0;
int day[M];//day[i]:di i ke shu xu doushao tian da dao mu biao
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    //srand(time(NULL));
    //cout<<rand()%1000000000;
    //return 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i = 1;i<=n-1;i++){
        cin>>u[i]>>v[i];
    }
    for(int i = 1;i<=n;i++){
        int h = 0;
        while(h<a[i]){
            ++day[i];
            h+=max(b[i]+day[i]*c[i],1);

        }
        
        
    }
    ++ans;


    sort(day+1,day+1+n);

    ans+=n-1;

    ans+=day[1];

     

    cout<<ans;


    return 0;
}
