#include <bits/stdc++.h>
using namespace std;

struct node{
    char v;
    int x;
    int y;
}a[10005];

int main(){

    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    //  10000->U   20000->T   30000->F

    int num[10005]={0};
    int h[10005]={0};
    int c,t;
    int n,m;
    int s[10005]={0};
    cin>>c>>t;
    int i,j;
    int o;
    for(o=0;o<t;o++){
        cin>>n>>m;//n bianliang(UTF+-) geshu   m yuju geshu
        for(j=0;j<m;j++){
            s[j]=j+1;
        }
        for(i=0;i<n;i++){
            cin>>a[i].v;
            if(a[i].v=='+'){
                cin>>a[i].x>>a[i].y;
                if(h[a[i].x-1]==0){
                    s[a[i].x-1]=s[a[i].y-1];//x=y
                    h[a[i].x-1]=1;
                }
                else{
                    if(s[a[i].x-1]!=s[a[i].y-1]){
                        num[o]++;
                    }
                }
                /*for(j=0;j<n;j++){
                    cout<<s[j]<<" ";
                }
                cout<<endl;*/
            }
            else if(a[i].v=='-'){
                cin>>a[i].x>>a[i].y;
                if(h[a[i].x-1]==0){
                    s[a[i].x-1]=-s[a[i].y-1];//x=-y
                    h[a[i].x-1]=1;
                }
                else{
                    if(s[a[i].x-1]!=-s[a[i].y-1]){
                        num[o]++;
                    }
                }
                /*for(j=0;j<n;j++){
                    cout<<s[j]<<" ";
                }
                cout<<endl;*/
            }
            else{
                cin>>a[i].x;
                if(a[i].v=='U'){
                    num[o]++;
                }
            }

        }
    }
    for(o=0;o<t;o++){
        cout<<num[o]<<" ";
    }
    return 0;
}
