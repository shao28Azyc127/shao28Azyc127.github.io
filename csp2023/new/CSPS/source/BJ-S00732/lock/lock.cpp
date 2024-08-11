#include<iostream>
using namespace std;
int a[10][10];
int ans[10005],cnt=0;
int n;
int l[7];
bool p(){
    int l1=-1,l2=-1;
    int d;
    for(int i=1;i<=n;i++){
        d=0;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=l[j]){
                d++;
                if(d>2) return 0;
                if(d==1) l1=j;
                else l2=j;
            }
        }
        if(d==1) continue;
        if(a[i][l1]-l[l1]!=a[i][l2]-l[l2] || l2-l1!=1) return 0;
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }

    }
    for(l[1]=0;l[1]<=9;l[1]++){
        for(l[2]=0;l[2]<=9;l[2]++){
            for(l[3]=0;l[3]<=9;l[3]++){
                for(l[4]=0;l[4]<=9;l[4]++){
                    for(l[5]=0;l[5]<=9;l[5]++){
                        if(p()){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
