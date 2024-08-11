#include<bits/stdc++.h>
using namespace std;
long long n=0,d=0;
const int N=100010;
long long v[N],a[N];
//tanxin ai<a i+1 next bumai jiansuo a i+2 zhidao ai> a i+n
long long ans;
long long h=0;//sheng yu gonglishu

int m(int x,int y){//cong x zhan kaidao y zhan
    int l=0,an=0;
    for(int i=x;i<y;i++){
        l+=v[i];
    }
    if(l<h){
        h-=l;
    }else{
        l-=h;
        an=l/d;
        if(l%d){
            an++;
            h=an*d-l;
        }
    }
    return an*a[x];
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int i=1,j=0;
    while(j<n){//while j=n ans+= m(i,n) return;
        j=i+1;
        while(a[i]<a[j]){
            j++;
        }
        ans+=m(i,j);
        i=j;
    }
    cout<<ans;
    return 0;
}
