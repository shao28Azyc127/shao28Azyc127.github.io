#include<bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
int main (){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i+1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0;
    long long sum=0;
    int pos=a[2];
    for(int i=3;i<=n;i++){
        //cout<<pos;
        if(a[i]>=pos){
           int tmp=v[i]/d-l;
           if(v[i]%d!=0) tmp++;
           if(tmp<0) {
                l-=v[i];
                continue;
           }
           sum+=pos*tmp;
           l=tmp-v[i];
           if(l<0) l=0;
           //cout<<pos<<" "<<tmp<<endl;
        }
        else{
           int tmp=v[i]/d-l;
           if(v[i]%d!=0) tmp++;
           if(tmp<0){
                l-=v[i];
                continue;
           }
           sum+=a[i]*tmp;
           l=tmp-v[i];
           if(l<0) l=0;
           pos=a[i];
           //cout<<pos<<" "<<tmp<<endl;
        }
    }
    cout<<sum;
    return 0;
}
