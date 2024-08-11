#include<bits/stdc++.h>
using namespace std;
double daa,sa;
int n,n1[100005],n2[100005],sasq[100005],min12=1000000,d;
long long lu,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>n1[i];
        sasq[i]+=sasq[i-1]+n1[i];
        lu+=n1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>n2[i];
        if(min12>n2[i]) min12=n2[i];
    }
    if(n2[1]==min12){
        if(lu%d==0) cout<<lu/d*n2[1];
        else cout<<(lu/d+1)*n2[1];
        return 0;
    }
    int i=1,j=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            while(n2[j]>=n2[i]){
                j++;
            }
            if(sasq[i]%d==0)daa+=sasq[i]/d;
            else daa+=sasq[i]/d+1;
            ans+=n2[1]*daa;
            sa=daa*d;
            sa-=sasq[i];
        }
        else{
            int assa=0;
            if(j>i) continue;
            j++;
            while(n2[i]<=n2[j]){
                j++;
                assa+=n1[j-1];
            }
            cout<<j;
            if(assa%d==0){
                if((assa/d-1)*d+sa>=assa){
                    sa+=(assa/d-1)*d;
                    ans+=(assa/d-1)*n2[i];
                }
                else{
                    sa+=assa/d;
                    ans+=assa/d*n2[i];
                }
            }
            else ){
                if((assa/d)*d+sa>=assa){
                    sa+=(assa/d)*d+d;
                    ans+=(assa/d)*n2[i]+1;
                }
                else{
                    sa+=assa/d+d;
                    ans+=assa/d*n2[i]+1;
                }
            }
        }
    }
    cout<<ans;
	return  0;
}