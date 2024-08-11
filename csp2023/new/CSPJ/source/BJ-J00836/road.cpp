#include<bits/stdc++.h>
using namespace std;
struct asd{
int f=0;
int d=999999;
int y;
}p[100001],r[100001];
int a,s,l=0,c=0,k=0;
double m=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>s;
    for(int i=0;i<a-1;i++){
        cin>>r[i].f;

        r[i].y=i+1;

    }
    for(int i=0;i<a;i++){
        cin>>r[i].d;

    }


        for(int j=0;j<a;j++){
            if(r[j].f%s!=0){
                k+=r[j-c].d*(r[j].f/4+1-m);
                m+=r[j].f/4+1-m;
                m=(m*4-r[j].f)/4;
            }else{
                k+=r[j-c].d*(r[j].f/4-m);
                m+=4*(r[j].f/4-m);
                m=(m*4-r[j].f)/4;
            }
            if(r[j-c].d<=r[j+1].d){
                c++;
            }else{
            c=0;
            }
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}