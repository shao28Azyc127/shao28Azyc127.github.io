#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("uqe.in","r",stdin);
  freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }else{
            cout<<max((-1*b+sqrt(b*b-4*a*c))/(2*a),(-1*b-sqrt(b*b-4*a*c))/(2*a));
        }
    }
   fclose(stdin);
    fclose(stdout);
    return 0;
}
