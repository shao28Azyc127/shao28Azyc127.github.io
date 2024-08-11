#include <bits/stdc++.h>
using namespace std;
int n,a[10][10],b[10],c[10];
bool check(){
    set <int> s1,s2;
    for (int i=1; i<=5; i++){
        if (c[i]!=0){
            s1.insert(c[i]); s2.insert(i);
        }
    }
    if  (s1.size()!=1) return 0;
    if (s2.size()>2) return 0;
    if (s2.size()==1) return 1;
    auto it=s2.begin();
    int tmp1=*it; it++;
    int tmp2=*it;
    if (tmp1!=tmp2-1) return 0;
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    int ans=0;
    for (b[1]=0;b[1]<=9; b[1]++){
        for (b[2]=0;b[2]<=9; b[2]++){
            for (b[3]=0;b[3]<=9; b[3]++){
                for (b[4]=0;b[4]<=9; b[4]++){
                    for (b[5]=0;b[5]<=9; b[5]++){
                        bool bb=true;
                        for (int i=1; i<=n; i++){
                            for (int j=1; j<=5; j++){
                                if (b[j]<=a[i][j]) c[j]=a[i][j]-b[j];
                                else c[j]=10+a[i][j]-b[j];
                            }
                            if (!check()){
                                bb=false;break;
                            }
                        }
                        if (bb) ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}