#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans;
int a[10];
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2){
        int g1=a[1]%10,s1=a[1]/10%10,b1=a[1]/100%10,q1=a[1]/1000%10,w1=a[1]/10000;
        int g2=a[2]%10,s2=a[2]/10%10,b2=a[2]/100%10,q2=a[2]/1000%10,w2=a[2]/10000;
        int cnt=0;
        if(g1!=g2) cnt++;
        if(s1!=s2) cnt++;
        if(b1!=b2) cnt++;
        if(q1!=q2) cnt++;
        if(w1!=w2) cnt++;
        if(cnt==1) cout<<10;
        else if(cnt==2){
            if(g1==g2&&s1==s2&&b1==b2){
                if(abs(w1-q1)==abs(w2-q2)){
                    ans=10;
                }
            }
            else if(g1==g2&&s1==s2&&w1==w2){
                if(abs(q1-b1)==abs(q2-b2)){
                    ans=10;
                }
            }
            else if(g1==g2&&w1==w2&&q1==q2){
                if(abs(b1-s1)==abs(b2-s2)){
                    ans=10;
                }
            }
            else if(w1==w2&&q1==q2&&b1==b2){
                if(abs(s1-g1)==abs(s2-g2)){
                    ans=10;
                }
            }
            cout<<ans;
        }else{
            cout<<0;
        }
        return 0;
    }
    int sz[10][10];//表示第i个数的第J位是几
    for(int i=1;i<=n;i++){
        sz[i][5]=a[i]%10;
        sz[i][4]=a[i]/10%10;
        sz[i][3]=a[i]/100%10;
        sz[i][2]=a[i]/1000%10;
        sz[i][1]=a[i]/10000;
    }
    int cnt=5;
    if(n==3){
        if(sz[1][1]==sz[2][1]==sz[3][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]) cnt--;
    }
    if(n==4){
        if(sz[1][1]==sz[2][1]==sz[3][1]==sz[4][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]==sz[4][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]==sz[4][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]==sz[4][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]==sz[4][5]) cnt--;
    }
    if(n==5){
        if(sz[1][1]==sz[2][1]==sz[3][1]==sz[4][1]==sz[5][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]==sz[4][2]==sz[5][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]==sz[4][3]==sz[5][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]==sz[4][4]==sz[5][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]==sz[4][5]==sz[5][5]) cnt--;
    }
    if(n==6){
        if(sz[1][1]==sz[2][1]==sz[3][1]==sz[4][1]==sz[5][1]==sz[6][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]==sz[4][2]==sz[5][2]==sz[6][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]==sz[4][3]==sz[5][3]==sz[6][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]==sz[4][4]==sz[5][4]==sz[6][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]==sz[4][5]==sz[5][5]==sz[6][5]) cnt--;
    }
    if(n==7){
        if(sz[1][1]==sz[2][1]==sz[3][1]==sz[4][1]==sz[5][1]==sz[6][1]==sz[7][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]==sz[4][2]==sz[5][2]==sz[6][2]==sz[7][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]==sz[4][3]==sz[5][3]==sz[6][3]==sz[7][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]==sz[4][4]==sz[5][4]==sz[6][4]==sz[7][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]==sz[4][5]==sz[5][5]==sz[6][5]==sz[7][5]) cnt--;
    }
    if(n==8){
        if(sz[1][1]==sz[2][1]==sz[3][1]==sz[4][1]==sz[5][1]==sz[6][1]==sz[7][1]==sz[8][1]) cnt--;
        if(sz[1][2]==sz[2][2]==sz[3][2]==sz[4][2]==sz[5][2]==sz[6][2]==sz[7][2]==sz[8][2]) cnt--;
        if(sz[1][3]==sz[2][3]==sz[3][3]==sz[4][3]==sz[5][3]==sz[6][3]==sz[7][3]==sz[8][3]) cnt--;
        if(sz[1][4]==sz[2][4]==sz[3][4]==sz[4][4]==sz[5][4]==sz[6][4]==sz[7][4]==sz[8][4]) cnt--;
        if(sz[1][5]==sz[2][5]==sz[3][5]==sz[4][5]==sz[5][5]==sz[6][5]==sz[7][5]==sz[8][5]) cnt--;
    }

    cnt=n-cnt;
    if(cnt==1) ans=10;
    if(cnt==2) ans=10;
    cout<<ans;
    return 0;
}
