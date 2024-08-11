#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i<=b;i++)
string a[3010];
string maxs[3010];
string mins[3010];

bool flag = 0;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n, m, j;char tmp;
	scanf("%d%d",&n, &m);
	if(n==1) printf("1"),exit(0);

	//input
	rep(i,1,n)
		cin>>a[i];

	//chu li
	rep(i,1,n){
		j = 1;
		if(m!=2) while(j<m&&a[i][j]>=a[i][j-1]) j++;
		else j = a[i][1] > a[i][0];
		if(j==m||m==1){
			maxs[i] = a[i];
			mins[i] = a[i];
			continue;
		}
		flag = 1;
		int mxi = j, mni = j;char mx = a[i][j], mn = a[i][j];
		rep(k,j,m-1){
			if(a[i][k] >= mx) mx = a[i][k], mxi = k;
			if(a[i][k] <= mn) mn = a[i][k], mni = k;
		}
		mins[i] = a[i];
		rep(k,0,mxi){
			if(mx > a[i][k]){
				tmp = mins[i][k];
				mins[i][k] = mins[i][mxi];
				mins[i][mxi] = tmp;
				break;
			}
		}
	
		maxs[i] = a[i];
		rep(k,0,mni){
			if(mn < a[i][k]){
				tmp = maxs[i][k];
				maxs[i][k] = maxs[i][mni];
				maxs[i][mni] = tmp;
				break;
			}
		}
		//printf("%d : %s %s\n",i, maxs[i].c_str(), mins[i].c_str());
	}

	rep(i,1,n){
		flag = 1;
		rep(k,1,n){
			if(i==k) continue;
			//printf("%s %s\n", maxs[i].c_str(), mins[k].c_str());
			flag = flag && (maxs[i] < mins[k]);
		}
		cout<<flag;
	}
	puts("");
	return 0;
}