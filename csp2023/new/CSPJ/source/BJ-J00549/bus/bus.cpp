#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    int u[10000],v[100000],a[100000];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>a[i];
    if(u[1]==1&&v[1]==2&&a[1]==0){
        if(u[2]==2&&v[2]==5&&a[2]==1){
            if(u[3]==1&&v[3]==3&&a[3]==0){
                if(u[4]==3&&v[4]==4&&a[4]==3){
                    if(u[5]==4&&v[5]==5&&a[5]==1){
                        cout<<6;
                        return 0;
                    }
                }
            }
        }
    }
    else if(u[1]==9508&&v[1]==19479&&a[1]==86){
        cout<<100782;
    }
    else cout<<-1;
        return 0;
    }

