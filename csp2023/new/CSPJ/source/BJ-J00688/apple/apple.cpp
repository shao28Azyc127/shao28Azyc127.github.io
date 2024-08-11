#include<iostream>
using namespace std;
int n,a[100010],cnt,x,tot,tot1;
bool empty(){
    for(int i=1;i<=n;i++) if(a[i]!=-1) return 1;
    return 0;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    int tot=n;
    while(empty()){
        cnt++;
        x=n;
        for(int i=1;i<=n;i+=3){
            if(a[i]==tot) tot1=cnt;
            a[i]=-1;
            x--;
        }
        for(int i=2;i<=n;i++){
            if(a[i-1]==-1){
                a[i-1]=a[i];
            }
        }
    }
    cout<<cnt<<" "<<tot1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
