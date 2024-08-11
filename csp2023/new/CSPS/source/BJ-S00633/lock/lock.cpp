#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool pwdv[100005];
int pwdT(vector<int> ori){
    return ori[0]*10000+ori[1]*1000+ori[2]*100+ori[3]*10+ori[4];
}
void getPwd(vector<int> ori){
    bool pwdu[100005];
    memset(pwdu,0,sizeof(pwdu));
    for(int i=0;i<5;i++){
        for(int j=1;j<=9;j++){
            ori[i]++;
            if(ori[i]==10){
                ori[i]=0;
            }
            pwdu[pwdT(ori)]=1;
        }
        ori[i]++;
        if(ori[i]==10){
            ori[i]=0;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=9;j++){
            ori[i]++;
            ori[i+1]++;
            if(ori[i]==10){
                ori[i]=0;
            }
            if(ori[i+1]==10){
                ori[i+1]=0;
            }
            pwdu[pwdT(ori)]=1;
        }
        ori[i]++;
        ori[i+1]++;
        if(ori[i]==10){
            ori[i]=0;
        }
        if(ori[i+1]==10){
            ori[i+1]=0;
        }
    }
    for(int i=0;i<100000;i++){
        pwdv[i]=pwdv[i]&&pwdu[i];
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    memset(pwdv,1,sizeof(pwdv));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> a;
        for(int j=0;j<5;j++){
            int t;
            cin>>t;
            a.push_back(t);
        }
        pwdT(a);
        getPwd(a);
    }
    int c=0;
    for(int i=0;i<100000;i++){
        c+=pwdv[i];
    }
    cout<<c;
    return 0;
}