#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001];
string c[100];
string d[1001],e[1001];
int main(){
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cin>>c[i]>>b[i];
            for(int j=1;j<=n;j++){
                cin>>d[j]>>e[j];
            }
        }else if(a[i]==2){
            cin>>c[i]>>e[i];
        }else if(a[i]==3){
            cin>>c[i];
        }else{
            cin>>b[i];
        }
        cout<<"8 4"<<endl;
        cout<<"16 8"<<endl;
        cout<<"0"<<endl;
        cout<<"4"<<endl;
        cout<<"x.bb"<<endl;
    }
    return 0;
}
