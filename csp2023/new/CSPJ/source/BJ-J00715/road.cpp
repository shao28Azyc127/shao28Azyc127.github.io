#include<bits/stdc++.h>
using namespace std;
long long n,d,ans,oi;
struct s{
int v,a,p,l;
}w[100005];
bool cmp(s x,s y){
    return x.a<y.a;
}
vector <int> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
   for(int i=1;i<n;i++){
    cin>>w[i].v;
    w[i].p=i;
    w[i].l+=w[i].v;
   }
    for(int i=1;i<=n;i++){
    cin>>w[i].a;
   }
   for(int i=n-1;i>0;i--){
    w[i].l=w[i].v+w[i+1].l;
   }
   for(int i=1;i<n;i++){
        if(q.size()==0||w[q[q.size()-1]].a>w[i].a){
            q.push_back(i);
        }
   }
   q.push_back(n+1);
   int les=0;
   for(int i=0;i<q.size()-1;i++){
        int cnt=w[q[i]].l-w[q[i+1]].l-les;
            if(cnt%d==0){
               ans+= cnt/d*w[q[i]].a;
            }else{
                ans+=(cnt/d+1)*w[q[i]].a;
                les=(cnt/d+1)*d-cnt;
            }


   }
    //sort(w+1,w+n,cmp);
    /*for(int i=1;i<n;i++){
    cout<<w[i].p<<" ";
   }
    */

    cout<<ans;
    return 0;
    }
