#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    long long ans=0;
    int n,d;
    cin>>n>>d;
    int v[n-1],a[n];
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int mn=a[0];
    double oil=0;

    for(int i=1;i<n;i++){
//        cout<<"oil:"<<oil<<" "<<mn<<endl;
        if(oil*d >= v[i-1]){
            oil -= double(v[i-1])/d;
        }
        else{
            ans += (int(v[i-1]-oil*d)/d)*mn;
            oil += int(v[i-1]-oil*d)/d;
            if(oil*d < v[i-1]){
                ans += mn;
                oil++;
            }
            oil -= double(v[i-1])/d;
        }
        mn = min(mn,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
