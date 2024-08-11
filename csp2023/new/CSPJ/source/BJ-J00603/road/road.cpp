#include<iostream>
#include<cstdio>
using namespace std;
int n,d,a[100001],u[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int mo;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int aj=100001;
    for(int j=1;j<=n;j++){
        if(a[j]<aj){
            aj=a[j];
        }
    }
    for(int i=1;i<=n;i++){
        if(aj==a[i]){
            int ui=0;
            for(int j=1;j<n;j++){
                ui+=u[i];
            }
            if(ui%d==0){
                mo+=(ui/d)*aj;
            }else{
                mo+=(ui/d+1)*aj;
            }
            cout<<mo;
            return 0;
        }else{
            if(u[i]%d==0){
                mo+=(u[i]/d)*a[i];
            }else{
                mo+=(u[i]/d+1)*a[i];
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}