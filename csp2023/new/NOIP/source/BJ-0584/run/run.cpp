#include<iostream>
#include<algorithm>
using namespace std;

struct chal{
	int x, y, v;
}cha[100005];
int lef[100005];
int dp[100005];

bool cmp1(chal l, chal r){
	return l.y<r.y;
}

bool cmp2(int l, int r){
	return cha[l].x<cha[r].x;
}

int bins(int r, int des){
    /*
	int l = 0;
	while(l!=r){
		int mid = ((l+r+1)>>1);
		if(cha[lef[mid]].x>=des)
			l = mid;
		else r = mid+1;
	}
	return l;*/
	for(;cha[lef[r]].x>=des&&r>=0; r--);
	return r+1;
}

int bins2(int r, int des){
    /*
	int l = 0;
	while(l!=r){
		int mid = (l+r)>>1;
		if(cha[mid].y<=des){
			r = mid+1;
		}
		else l = mid;
	}
	return l;*/
	for(;cha[r].y>=des&&r>=0; r--);
	return r+1;
}

int mian(){

	int m, n, k, d;
	cin>>n>>m>>k>>d;
	for(int i = 1; i<=m ;i++){
		int x, y, v;
		if(x>k) v = 0;
		cin>>x>>y>>v;
		cha[i].x = x-y+1;
		cha[i].y = x, cha[i].v = v;
	}
	std::sort(cha+1, cha+m+1, cmp1);
	for(int i = 1; i<=m; i++){
		lef[i] = i;
	}
	std::sort(lef+1, lef+m+1, cmp2);
	cha[0].x = 0, cha[0].y = 0, cha[0].v = 0;
	//before r-k
	int prevmaxptr=0;
	int beforekptr=0;
	for(int i = 1; i<=m; i++){
		while(cha[beforekptr].y<cha[i].y-k/* +1 */){
			if(dp[beforekptr]>dp[prevmaxptr]) prevmaxptr = beforekptr;
			beforekptr++;
		}

		int l = bins(cha[i].y, cha[i].y-k+1);
		int afterkptr = bins2(cha[i].y, cha[i].y-k-1);
		int aftermaxptr = afterkptr;

		int sumof =0 ;
		for(int j = l; cha[lef[j]].x<=cha[i].y&&j<=m; j++){
			if(cha[lef[j]].y>cha[i].y) continue;
			sumof += cha[lef[j]].v;
		}

		int lastx = 0;
		for(int j = l; cha[lef[j]].x<=cha[i].y&&j<=m; j++){
			if(cha[lef[j]].y>cha[i].y) continue;

			if(lastx == cha[lef[j]].x) continue;
			lastx = cha[lef[j]].x;
			while(cha[afterkptr].y<cha[lef[j]].x-1){
				if(dp[aftermaxptr]<dp[afterkptr]) aftermaxptr = afterkptr;
				afterkptr++;
			}


			int res = max(dp[prevmaxptr], dp[aftermaxptr])+sumof-d*(cha[i].y-cha[lef[j]].x+1);
			dp[i]= max(dp[i], res);
			sumof -=cha[lef[j]].v;
		}
	}
	int res = 0;
	for(int i = 1; i<=m; i++){
        res = max(res, dp[i]);
        //cout<<dp[i]<<endl;
	}
	cout<<res<<endl;
	return 0;
}

int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
    int q,T;
    cin>>q>>T;
    while(T--)
    mian();
    return 0;
}
