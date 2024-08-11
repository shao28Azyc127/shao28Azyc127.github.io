#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005

string s[MAXN];

int n,m;

int cnt[MAXN][26];
int lst[MAXN];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);

    ios::sync_with_stdio(false);

	memset(cnt,0,sizeof(cnt));

	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            cnt[i][s[i][j]-'a']++;
            lst[i]=max(lst[i],s[i][j]-'a');
        }
	}

	for(int i=1;i<=n;i++){
        bool ans=true;
        for(int j=1;j<=n;j++){
            bool now=false;
            if(i==j){
                continue;

            }

            int cj=lst[j];
            int alli=0,allj=cnt[j][lst[j]];

            for(int ci=0;ci<=25;ci++){
                if(!cnt[i][ci]){
                    continue;
                }

                if(ci<cj){
                    now=true;

                    break;
                }

                alli+=cnt[i][ci];

                for(cj;allj<=alli && cj>=0;cj--){
                    allj+=cnt[j][cj];
                }
            }

            ans=ans&now;
        }

        if(ans){
            printf("1");
        }else{
            printf("0");
        }
	}

	printf("\n");

	return 0;
}
