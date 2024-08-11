#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int NR=3010;

int cnt[NR][40];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	if(n==1){
		cout << "1" << endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		char c;
		for(int j=1;j<=m;j++){
			cin >> c;
			cnt[i][c-'a']++;
		}
	}
	for(int i=1;i<=n;i++){
		bool jud=true;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int temp1=0,temp2=25;
			while(temp1<=25&&cnt[i][temp1]==0)temp1++;
			while(temp2>=0&&cnt[j][temp2]==0)temp2--;
			if(temp1>=temp2){
				jud=false;
				break;
			}
		}
		cout << jud;
	}
}