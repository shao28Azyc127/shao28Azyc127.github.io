#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int f[200011];
bool can[8011][8011];
ull hs[200011];
ull revhs[200011];
const ull base=1e9+7;
ull mi[200011];
int n;
string s;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> s;
	s=" "+s;
	//cout << s << endl;
	mi[0]=1;
	for(int i=1;i<=n;i++){
        hs[i]=hs[i-1]*base+s[i];
        mi[i]=mi[i-1]*base;
	}
	for(int i=n;i>=1;i--){
        revhs[i]=revhs[i+1]*base+s[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=i-2;2*j-i+1>=1&&j>=1;j-=2){
            ull hashr=hs[i]-hs[j]*mi[i-j];
            ull hashl=revhs[2*j-i+1]-revhs[j+1]*mi[i-j];
            //cout << hashl << ' ' << hashr << endl;
            if(hashr==hashl){
                f[i]=2*j-i+1;
                break;
            }
        }
        //cout << f[i] << ' ' << hs[i] << ' ' << revhs[i] << endl;
        //cout << f[i] << endl;
	}
    for(int r=2;r<=n;r++){
        for(int l=r-1;l>=1;l-=2){
            //if((r-l+1)%2==1) continue;
            if(s[l]==s[r]){
                if(l+1==r){
                    can[l][r]=true;
                    //cout << "!" << ' ' << l << ' ' << r << endl;
                }
                else
                {
                    can[l][r]=can[l+1][r-1];
                    //cout << l << ' ' << r << ' ' << l+1 << ' ' << r-1 << ' ' << can[l+1][r-1]<< ' ' << can[l][r] << endl;
                }
                if(can[l][r]==true) f[r]=max(f[r],l);
                //cout << f[6] << endl;
            } else {
                if(l==f[r]) can[l][r]=true;
                else if(f[r]==0) can[l][r]=false;
                else can[l][r]=can[l][f[r]-1];
                if(can[l][r]==true) f[r]=max(f[r],l);
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(can[i][j]){
            ans++;
            //cout << i << ' ' << j << endl;
        }
    //cout << endl;//
    //for(int i=1;i<=n;i++) cout << f[i] << endl;
    //cout << endl;//
    cout << ans << endl;
	return 0;
}
/*
using long long !!!
*/
