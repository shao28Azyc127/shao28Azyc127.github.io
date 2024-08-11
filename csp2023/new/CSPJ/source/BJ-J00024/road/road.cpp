#include<iostream>
using namespace std;
int v[100005],a[100005];
int mark[100005];
int main(){
	freopen("road.in","r",stdin);
	freopne("road.out","w",stdout);
	int n, d;
	cin >> n >> d;
	for(int i = 0;i < n - 1;i++){
		cin >> v[i];
	}
	cin >> a[0];
	int temp = a[0];
	mark[0] = 0;
	int cnt = 1;
	for (int i = 1;i < n; i++){
		cin >> a[i];
		if(a[i] < temp){
			mark[cnt] = i;
			temp = a[i];
			cnt++;
		}
	}
	int sum = 0;
	int dis = 0;
	int more = 0;
	for (int i = 0; i < cnt - 1; i++)
	{
		dis = 0;
		for(int j = mark[i];j < mark[i+1]; j++){
			dis+=v[j];
		}
		dis-=more;
		if(dis%d!=0) 
		{
			sum+=a[mark[i]]*(dis/d+1);
			more = (dis/d+1)*d - dis;
		}
		else 
		{
			sum+=a[mark[i]]*dis/d;
		}
		
	}
	cout << sum;
	return 0;
}
