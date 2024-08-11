#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long w[100001],v[100001];
long long car=0,pos=0,pri=0;
long long up(long long a,long long b){
    if(a%b==0)return a/b;
    else return a/b+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<long long,vector<long long>,greater<long long> >q;
    for(int i=0;i<n-1;i++){
        q.push(v[i]);
        if(car<w[i]){
            pri+=q.top()*up(w[i]-car,d);
            car+=d*up(w[i]-car,d);
        }
        car-=w[i];
    }
    cout<<pri<<endl;
    return 0;
}