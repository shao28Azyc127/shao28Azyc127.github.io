#include <iostream>
#include <string>
using namespace std;
int n,m;
string w[5000];
int mins[5000];
int maxs[5000];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    if(n==1) cout<<'1';
    else{
        if(m==1){
            int min=1;
            for(int i=2;i<=n;i++){
                if(w[i]==w[min]){
                    min=0;
                    break;
                }
                else if(w[i]<w[min]) min=i;
        
            }
            for(int i=1;i<=n;i++){
                if(i==min) cout<<'1';
                else cout<<'0';
            }
        }
        if(m==2){
            for(int i=1;i<=n;i++){
                if(w[i][0]<=w[i][1]){
                    mins[i]=w[i][0];
                    maxs[i]=w[i][1];
                }
                else{
                    mins[i]=w[i][1];
                    maxs[i]=w[i][0];
                }
            }
            int minmax=1;
            bool rep=false;
            for(int i=2;i<=n;i++){
                if(maxs[i]<maxs[minmax]) {minmax=i;rep=false;}
                if(maxs[i]==maxs[minmax]) rep=true;
            }
            for(int i=1;i<=n;i++){
                if(mins[i]<maxs[minmax] || (minmax==i&&mins[i]==maxs[i]&&!rep)) cout<<'1';
                else cout<<'0';
            }
        }
    }
    return 0;
}