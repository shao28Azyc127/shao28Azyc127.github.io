#include<bits/stdc++.h>
using namespace std;
double juli[100001];
int qian[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	double d;
	cin >> n >> d;
	for(int i = 0;i < n - 1;i ++) cin >> juli[i];
	for(int i = 0;i < n;i ++) cin >> qian[i];
	int minn = 9999;
	for(int i = 0;i < n;i ++) minn = min(minn,qian[i]);
	if(minn == qian[0]){
		double a = 0;
		for(int i = 0;i < n - 1;i ++) a += juli[i];
		cout << ceil(a / d) * qian[0];
	}else{
		int jiage = qian[0],oil = ceil(juli[0] / d),zongqian = 0,zonglu = juli[0];
		for(int i = 1;i < n;i ++){
			if(jiage <= qian[i]){
				oil += ceil(juli[i - 1] / d);
				zonglu += juli[i - 1];
			}else{
				zongqian += jiage * oil;
				jiage = qian[i];
				oil = oil * d - zonglu;
				zonglu = 0;
			}
		}
		cout << zongqian;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}