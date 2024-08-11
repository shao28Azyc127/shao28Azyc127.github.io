include<bits/cstd.h++>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,little=1000000,sum,all=0;
    cin>>n>>d;
    int v[n-1];
    int a[n];
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<little){
            if(sum%little==0){
                all+=int(sum/little);
            }else{
                all+=int(sum/little)+1;
            }
            little=a[i];
        }
        if(i!=n-1){
            sum+=v[i];
        }
    }
    cout<<all;
    return 0;
}
