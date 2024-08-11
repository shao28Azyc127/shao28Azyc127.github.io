#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n=0;
bool a[1000000002]; //ture:有苹果, flase:没有苹果;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	
	cin >> n;
	
	//将1～n的位置放置苹果;
	memset(a, false, sizeof(a));
	for(int i=1; i<=n; i++) {
		a[i]=true;
	}
	
	//处理每一天;
	int day=0; //天数
	int n_day=0; //第n个苹果拿完的天数
	bool x=false; //n_day是否已经存过
	while(true) {
		int t=0; //跳过苹果的个数;
		bool all_false=true; //true:没有苹果了, false:还有苹果
		for(int i=1; i<=n; i++) {
			if(a[i]==true) {
				t++;
			}
			if(t-1==0 && a[i]==true) {
				a[i]=false;
			}
			if(t==2) {
				t=0;
			}
			if(i==n && t==0 && a[i]==true) {
				a[i]=false;
			}
			//判断此位置是否有苹果
			if(a[i]==true) {
				all_false=false; //还有苹果
			}
		}
		
		day++;
		//判断第n个苹果是否拿完;
		if(a[n]==false && x!=true) {
			n_day=day;
			x=true;
		}
		if(all_false==true) {
			day--;
			break;
		}
	}
	
	cout << day << ' ' << n_day << endl;
	
	return 0;
}