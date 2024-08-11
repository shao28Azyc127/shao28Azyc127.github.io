#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,m;
string w[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }else if(m==1){
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(w[i][0]>w[j][0]){
                    flag=false;
                    break;
                }
            }
            cout<<flag;
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            bool flag1=true,flag2=true;
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(w[i][0]>w[j][0] or w[i][0]==w[j][0] and w[i][1]>w[j][1]){
                    if(w[i][0]>w[j][1] or w[i][0]==w[j][1] and w[i][1]>w[j][0]){
                        flag1=false;
                        break;
                    }
                }
            }
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(w[i][1]>w[j][0] or w[i][1]==w[j][0] and w[i][0]>w[j][1]){
                    if(w[i][1]>w[j][1] or w[i][1]==w[j][1] and w[i][0]>w[j][0]){
                        flag2=false;
                        break;
                    }
                }
            }
            cout<<(flag1 or flag2);
        }
    }
    cout<<endl;
    return 0;
}
/*ICAgICAqKioqKioqKioqKioqKiAgICAgICAgICAqICAgICAgICoKICAgICAqICAgICAgKiAgICAg
ICAgICAgICAgICAgKiAgICAgICoKICAgICogICAgICAqICAgICAgICAgICAgICAqKioqKiAgICAg
ICoKICAgICogICAgKioqKiogICAgICAgICAgICAgICAqICAgICAgICoKICAgKiAgICAgKiAgICog
ICAgICAgICAgICAgICogICAgICAqKioqKgogICAqICAgICAqKioqKiAgICAgICAgICAgICAqKiog
ICAgICogKiAqCiAgKiAgICAgICogICAqICAgICAgICAgICAgKiAqICogICAgKioqKioKICAqICAg
ICAgKioqKiogICAgICAgICAgICAgICogICogICAqICogKgogKiAgICAgICAgICogICAgICAgICAg
ICAgICAgKiAgICAgICoqKioqCiAqICAgICAqICAgKiAgICogICAgICAgICAgICAqICAgICAgICAq
CiogICAgICogICogKiAgICAqICAgICAgICAgICAqICAgICAgICAqCiogICAgICAgICAqKiAgICAg
ICAgICAgICAgICAqICAgICAgICAqCgogICAgICAgICAgKiAgICAgICAgICAgICAgICoqKiAgICAg
ICAqCiAgICAgICAgICAgKiAgICAgICAgICAgICAgICAgICAgICAgICoKICAgICAgICAqKioqKioq
ICAgICAgICAgICAqKiogICAgICoqKioqKgogICAgICAgKiAgICAgICogICAgICAgICAgICAqICAg
ICAgICAqICAqCiAgICAgICoqKioqKioqKiAgICAgICAgICAgICogICAgICAgICogICoKICAgICAq
ICAgICAgICAgICAgICAgICAgICAqICAgICAgICAqICAgKgogICAgKiAgICAgICAgICAgICAgICAg
ICAgICogICAgICAgKiAgICAqCiAgICogICAgKioqKioqICAgICAgICAgICAqICAqICAgICogICAq
ICoKICAqICAgICAqICAgICogICAgICAgICAgKioqKioqICAgICAgICAqKgogKiAgICAgICoqKioq
KiAgICAgICAgICAgICAgICAqICAgICAgICAqCio=*/