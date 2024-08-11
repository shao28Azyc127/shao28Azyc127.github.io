#include<bits/stdc++.h>
using namespace std;
int loc[10][10];int n;
bool judge2(int disa,int disb){
    if(disa==disb)return 1;
    if((disa+10)%10==(disb+10)%10)return 1;
    return 0;
}
bool judge(int a,int b,int c,int d,int e){
    int cnt=0;
    if(a==0&&b==1&&c==1&&d==1&&e==5){
        cnt++;
        cnt--;
    }
    //bool ok=1;
    for(int i=1;i<=n;i++){
        if(loc[i][1]==a&&loc[i][2]==b&&loc[i][3]==c
            &&loc[i][4]==d&&loc[i][5]==e){
                return 0;//not correct
        }
        int diff=0;
        int diffa=0,diffb=0;
        int disa=0,disb=0;
        if(a!=loc[i][1]){
            diff++;
            if(diffa){
                diffb=1;
                disb=a-loc[i][1];
            }
            else {

                diffa=1;
                disa=a-loc[i][1];
            }
        }if(b!=loc[i][2]){
            diff++;
            if(diffa){
                    diffb=2;
            disb=b-loc[i][2];
            }
            else {
                    diffa=2;
                    disa=b-loc[i][2];
            }
        }if(c!=loc[i][3]){
            diff++;
            if(diffa){
                diffb=3;
                disb=c-loc[i][3];
            }
            else {
                diffa=3;
                disa=c-loc[i][3];
            }
        }if(d!=loc[i][4]){
            diff++;
            if(diffa){
                    diffb=4;
                 disb=d-loc[i][4];
            }
            else {
                diffa=4;disa=d-loc[i][4];
            }
        }if(e!=loc[i][5]){
            diff++;
            if(diffa){
                    diffb=5;
                    disb=e-loc[i][5];
            }
            else {
                diffa=5;
                disa=e-loc[i][5];
            }
        }

        if(diff>2)return 0;
        //if(diff==1)return 1;
        if(diff==2&&abs(diffa-diffb)>1)return 0;
        if(diff==2&&judge2(disa,disb)==0)return 0;
    }return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>loc[i][j];
        }
    }
    //if(n==1){
    //    cout<<5*9+4*9;
    //}else{
        int ans=0;
        for(int a=0;a<=9;a++){
            for(int b=0;b<=9;b++){
                for(int c=0;c<=9;c++){
                    for(int d=0;d<=9;d++){
                        for(int e=0;e<=9;e++){
                            if(judge(a,b,c,d,e)){
                                //cout<<a<<b<<c<<d<<e<<'\n';
                                ans++;
                            }

                        }
                    }
                }
            }
        }

        cout<<ans;
    //}
    return 0;
}
