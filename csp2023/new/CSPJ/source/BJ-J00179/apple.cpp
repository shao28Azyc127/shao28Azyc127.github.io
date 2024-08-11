#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream fin ("apple.in");
	ofstream fout ("apple.out");
	
	int n,cnt = 0,cnt_n = 0;
	vector <int> a;
	
	fin >> n;
	
	for(int i = 1;i <= n;i++){
		a.push_back(i);
	}
	
	while(!a.empty()){
		for(int i = 0;i < (int)a.size();i++){
			if(a[i] == n){
				cnt_n = cnt + 1;
			}
			a.erase(a.begin() + i++);
		}
		cnt++;
	}
	
	fout << cnt << " " << cnt_n << endl;

	fin.close();
	fout.close();
	
	return 0;
}
