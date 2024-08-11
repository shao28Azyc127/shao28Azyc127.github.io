#include<iostream>
using namespace std;
int u[100000],a[100000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int zongqianshu=0,yuxiadeyou=0;
    for(int i=0;i<n-1;){
        int shu=i+1,xuyaozoudelishu=u[i];
        while(a[i]<a[shu]&&shu<n){
            shu++;
            xuyaozoudelishu+=u[shu];
        }
        int xuyaojiasheng=0;
        xuyaojiasheng=xuyaozoudelishu/d-yuxiadeyou+1;
        if(xuyaozoudelishu<d*xuyaojiasheng+yuxiadeyou==0){
            xuyaojiasheng--;
        }
        if((xuyaojiasheng+yuxiadeyou)*d>xuyaozoudelishu-1){
            xuyaojiasheng--;
        }
        zongqianshu+=xuyaojiasheng*a[i];
        yuxiadeyou=xuyaojiasheng+yuxiadeyou-xuyaozoudelishu/d;
        i=shu;
    }
    cout<<zongqianshu;
    fclose(stdin);
    fclose(stdout);
    return 0;
}