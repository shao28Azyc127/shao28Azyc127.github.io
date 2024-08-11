#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[1000];
    int a[1000];
    long long sum=0;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    int s=v[0];
    int c;
    for(int i=0;i<n;i++){
            t=a[0];
            if(t<a[i]){
                s+=v[i];
            }
            else if(t>a[i]){
                if(s%d==0){
                    sum+=s/d*t;
                }
                else{
                    sum+=s/d*t+t;
                    c=(s/d+1)*d-s;
                }
                t=a[i];
            }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}