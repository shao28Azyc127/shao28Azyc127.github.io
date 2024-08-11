#include<iostream>
#include<cstdio>
using namespace std;
struct da{
    int p,v;

};
int n,d,zanc;
da au[100007];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>au[i].p;
    }
    for(int i=1;i<n;i++){
        cin>>au[i].v;
    }
    for(int i=1;1<n;i++){
        for(int j=1;j<n;j++){
            for(int k=1;k<n;k++){
                if(au[i].p*au[j].p)
                    zanc+=au[i].p*au[j].p;
            }
        }
    }
    cout<<zanc;
    return 0;
}

