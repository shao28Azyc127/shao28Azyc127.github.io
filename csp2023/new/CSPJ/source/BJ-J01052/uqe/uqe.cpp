#include <bits/stdc++.h>
using namespace std;
#define LL long long
bool zheng(double a){
    return ceil(a)==floor(a);
}
int gcd(int a,int b){
    int minn = min(a,b),maxn = max(a,b);
    if(maxn%minn==0)    return minn;
    else{
        int ans = 0;
        for(int i=1;i<=floor(sqrt(minn));i++){
            if(minn%i==0 && maxn%i==0 && i>ans){
                ans = i;
                if(minn%(minn/i)==0 && maxn%(minn/i)==0 && (minn/i)>ans)    ans = minn/i;
            }
        }
        return ans;
    }
}
int pfs(int a){
    if(zheng(sqrt(a)))  return a;
    for(int i=ceil(sqrt(a));i>=2;i--){
        if(a%(i*i)==0)  return i;
    }
    return 1;
}
int main(){
    //ios::sync_with_stdio(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    string ans = "";
    int t,maxXi;    //number of questions,max |a|
    cin >> t >> maxXi;
    int a,b,c,del,ans_up,ans_down,gcd1,sd,mpfs,gcdtmp;
    long double ansfin;
    string tmp = "";
    bool ans_0;
    for(int i=0;i<t;i++){
        cin >> a >> b >> c;
        del = b*b-4*a*c;
        if(del<0)   ans+="NO";
        else{
            if(zheng(sqrt(del))){   //解为有理数
                sd = sqrt(del);
                ans_up = sd-b;
                ans_down = 2*a;
                ansfin = ans_up*1.0/ans_down;
                ans_0 = (ansfin<0);
                ans_up = abs(ans_up);ans_down = abs(ans_down);ansfin = abs(ansfin);
                if(ans_up==0)  ans+="0";
                else{
                    gcd1 = gcd(ans_up,ans_down);
                    if(ans_0)  ans+="-";
                    if(zheng(ansfin)){    //解为整数
                        ans+=to_string((int)ansfin);
                    }
                    else{
                        ans_up/=gcd1;ans_down/=gcd1;
                        ans+=to_string(ans_up);ans+="/";ans+=to_string(ans_down);
                    }
                }
            }
            else{
                ans_up = -b;
                ans_down = 2*a;
                ansfin = ans_up*1.0/ans_down;
                ans_0 = (ansfin<0);
                ans_up = abs(ans_up);ans_down = abs(ans_down);ansfin = abs(ansfin);
                if(ans_up!=0){
                    gcd1 = gcd(ans_up,ans_down);
                    if(ans_0 && b!=0 && b!=-0)   ans+="-";
                    if(zheng(ansfin)){
                        ans+=to_string((int)ansfin);
                    }
                    else{
                        ans_up/=gcd1;ans_down/=gcd1;
                        ans+=to_string(ans_up);ans+="/";ans+=to_string(ans_down);
                    }
                }
                mpfs = pfs(del);
                del/=mpfs*mpfs;
                if(b!=0 && b!=-0){
                    if(ans_down<0)  ans+="-";
                    else   ans+="+";
                }
                ans_down = abs(ans_down);
                //cout << mpfs << " " << gcd(mpfs,ans_down) << " " << ans_down << endl;
                if(gcd(mpfs,ans_down)==1){
                    if(mpfs!=1) {ans+=to_string(mpfs);ans+="*";}
                    ans+="sqrt(";ans+=to_string(del);ans+=")";
                    if(ans_down!=1) {ans+="/";ans+=to_string(ans_down);}
                }
                else{
                    gcdtmp = gcd(mpfs,ans_down);
                    mpfs/=gcdtmp;ans_down/=gcdtmp;
                    if(mpfs!=1) {ans+=to_string(mpfs);ans+="*";}
                    ans+="sqrt(";ans+=to_string(del);ans+=")";
                    if(ans_down!=1) {ans+="/";ans+=to_string(ans_down);}
                }
            }
        }
        ans+="\n";
    }
    cout << ans;
    return 0;
}
