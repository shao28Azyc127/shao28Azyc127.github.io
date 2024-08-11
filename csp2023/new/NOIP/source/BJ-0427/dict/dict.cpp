#include<iostream>
using namespace std;
struct node{
    int ax;
    int in;
};
node a[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    char ch;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ch;
        a[i].in=(ch-'0');
        a[i].ax=(ch-'0');
        for(int j=2;j<=m;j++){
            cin>>ch;
            if((ch-'0')<a[i].in){
                a[i].in=(ch-'0');
            }
            if((ch-'0')>a[i].ax){
                a[i].ax=(ch-'0');
            }
        }
    }
    for(int i=1;i<=n;i++){
        int ff=1;
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(a[j].ax<=a[i].in){
                ff=0;
                break;
            }
        }
        cout<<ff;
    }
    return 0;
}
