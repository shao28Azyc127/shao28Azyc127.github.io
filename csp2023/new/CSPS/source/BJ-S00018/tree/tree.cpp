#include <iostream>
using namespace std;
int n;
struct trees
{
	int a,b,c;
	int g = 0;
	bool grow = false;
	bool done = false;
};
trees t[100005];
bool r[500][500];
int ans = 1000000000;
void find(int day, int place)
{
	if(day > 1000000000) return;
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		if(!t[i].done){
			flag = false;
			break;
		}
	}
	if(flag){
		if(day < ans){
			ans = day;
		}
		return;
	}
	
	for(int i=0;i<n;i++){
		if(t[i].grow){
			t[i].g+=max(t[i].b + day*t[i].c , 1);
		}
		if(t[i].grow >= t[i].a) t[i].done = true;
	}
	flag = true;
	for(int i=0;i<n;i++)
	{
		if(!t[i].grow){
			flag = false;
			break;
		}
	}
	if(flag){
		find(day+1,place);
	}
	for(int i = 0; i < n;i++)
	{
		if(r[place][i] == true)
		{
			if(t[i].grow == false)
			{
				t[r[place][i]].grow = true;
				find(day+1,i);
				t[i].grow = false;
			}
		}
	}
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i].a >> t[i].b >> t[i].c;
	}
	int s , q;
	for(int i = 0; i <n-1;i++)
	{
		cin >>s;
		cin >> q;
		r[s][q]=true;
		r[q][s] = true;
	}
	t[0].grow = true;
	find(2, 1);
	cout << ans;
	return 0;
}
