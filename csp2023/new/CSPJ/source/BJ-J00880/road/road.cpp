#include<bits/stdc++.h>
using namespace std;
int n,d;
int to_Up(int a,int b){
    if(a%b==0){
        return a/b;
    }
    return a/b+1;
}
struct node{
    int dis;
    int pri;
}a[100005];
int b[100005]={};
int find_Up(int idx){
    for(int i=idx;i<=n;i++){
        if(a[i].pri<a[idx].pri){
            return i;
        }
    }
}
int find_Dis(int s,int e){
    int sum=0;
    for(int i=s+1;i<=e;i++){
        sum+=a[i].dis;
    }
    return sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int loc=1;
    cin>>n>>d;
    int ans=0;
    int tot=0
    for(int i=2;i<=n;i++){
        cin>>a[i].dis;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].pri;
        b[i]=a[i].pri;
    }
    sort(b+1,b+n+1);
    if(a[1].pri==b[1]){
        cout<<a[1].pri*to_Up(find_Dis(1,n),d);
        return 0;
    }
    ans+=a[1].pri*to_Up(find_Dis(1,find_Up(1)),d);
    loc=find_Up(1);
    while(a[loc].pri!=b[1]){
        ans+=a[loc].pri*to_Up(find_Dis(loc,find_Up(loc)),d);
        loc=find_Up(loc);
    }
    ans+=a[loc].pri*to_Up(find_Dis(loc,n),d);
    cout<<ans;
    return 0;
}
