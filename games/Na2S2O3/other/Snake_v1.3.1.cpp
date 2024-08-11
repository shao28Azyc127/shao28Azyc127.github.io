#ifndef __SNAKE__
#define __SNAKE__
#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bits/stl_set.h>
#include <bits/vector.tcc> 
using namespace std;
const int maxb = 40;
set<pair<int, int> > snakebodies, apples, my,op, my_body[maxb];
const int maxn = 100;
int dis[maxn][maxn], reds, greens;
void color(const int a) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); }
void SetPos(COORD a) { HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(out, a); }
void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
void clear(int x, int y) {
	swap(x, y);
	SetPos(x+1, y + 1);
	putchar(' ');
}
void clear(const pair<int, int> p) { clear(p.first, p.second); }
void print(int x, int y, const int col = 2) {
	swap(x, y);
	SetPos(x + 1, y + 1);
	color(col);
	putchar('#');
	color(15);
}
void print(const pair<int, int> p, const int col = 2) { print(p.first, p.second, col); }
void printhead(int x, int y) {
	swap(x, y);
	SetPos(x + 1, y + 1);
	color(3);
	putchar('@');
	color(15);
}
void putapple(int x, int y) {
	swap(x, y);
	SetPos(x + 1, y + 1);
	apples.emplace(y, x);
	color(12);
	putchar('X');
	color(15);
}
void putapple(const pair<int, int> p) { putapple(p.first, p.second); }
#if _HAS_CXX17 || _HAS_CXX20
#define unpackpair(x,y,a) auto [x, y] = a;
#else
#define unpackpair(x,y,a) int x = a.first, y = a.second;
#endif
#ifndef _TEST_
#define _TEST_ 1
#endif
#define st(x) (x==1?op:my)
int length = 4;
namespace judge {
	const int dx[] = { -1, 1, 0,0 }, dy[] = { 0, 0,-1,1 };
	const int nxt[] = { 1,0,3,2 };
	const int nxtpos[] = { 1,2,3,0 };
	template<class _Ty>
	struct RMove {
		string type = "HM";
		_Ty operator() (_Ty x, int& dir, const int xmax, const int ymax) {
			if (_kbhit()) {
				fflush(stdin);
				char c = _getch();
				if (c == 'W' || c == 'w') dir = 0;
				else if (c == 'S' || c == 's') dir = 1;
				else if (c == 'A' || c == 'a') dir = 2;
				else if (c == 'D' || c == 'd') dir = 3;
				else if (c == 'q' || c == 'Q') dir = -1;
				else if (c == 't' || c == 'T') return { -1,0 };
			}
			unpackpair(X, Y, x);
			if (dir == -1) return { -1,-1 };
			return { X + dx[dir], Y + dy[dir] };
		}
	};
	template<class _Ty>
	struct __illegal_move {bool operator()(const int x, const int y, const int n, const int m) {return x < 0 || x >= n || y < 0 || y >= m || snakebodies.count({x,y});}};
	template <class _Ty>
	struct RandAccessAI {
		string type = "AI";
		_Ty operator() (_Ty x, int& dir, const int xmax, const int ymax) {
			unpackpair(X, Y, x);
			int w = rand() % 2 + 1;
			int v = rand() % 12;
			if (!v) return { x.first + dx[dir],x.second + dy[dir] };
			int cnt = 0;
			int nxtdir = rand() % 4;
			for (int i = 0; i < 4; i++) if (apples.count({ X + dx[i], Y + dy[i] })) nxtdir = i;
			if (w==2 && !(X + dx[nxtdir] < 0 || X + dx[nxtdir] >= xmax || Y + dy[nxtdir] < 0 || Y + dy[nxtdir] >= ymax || snakebodies.count({ X + dx[nxtdir], Y + dy[nxtdir] }))) {
				dir = nxtdir;
				return { X + dx[nxtdir], Y + dy[nxtdir] };
			}
			while ((X+dx[dir] < 0 || X+dx[dir] >= xmax || Y + dy[dir] < 0 || Y + dy[dir] >= ymax || snakebodies.count({X+dx[dir], Y+dy[dir]})) && cnt<10) dir = nxtpos[dir], cnt++;
			return { X + dx[dir], Y + dy[dir] };
		}
	};
	template<class _Ty>
	struct AI {
		string type = "AI";
		_Ty operator() (_Ty x, int& dir, const int xmax, const int ymax) {
			vector<_Ty> mxpnt(apples.size(), { x.first + dx[dir], x.second + dy[dir] });
			vector<int> mn(apples.size(), 1e9);
			for (int d=0;d<4;d++) {
				memset(dis, 0, sizeof(dis));
				if (x.first+dx[d] < 0 || x.first+dx[d] >= xmax || x.second+dy[d] < 0 || x.second+dy[d] >= ymax || snakebodies.count({x.first + dx[d],x.second + dy[d]})) continue;
				queue<_Ty> q;
				q.emplace(x.first + dx[d], x.second + dy[d]);
				while (!q.empty()) {
					unpackpair(X,Y,q.front()); q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = X + dx[i], ny = Y + dy[i];
						if (nx < 0 || nx >= xmax || ny < 0 || ny >= ymax || dis[nx][ny] || snakebodies.count({ nx,ny })) continue;
						q.emplace(nx, ny);
						dis[nx][ny] = dis[X][Y] + 1;
					}
				}
				int dist = 0;
				for (auto it = apples.begin(); it != apples.end(); it++) {
					if (dis[it->first][it->second] < mn[dist]) {
						mxpnt[dist] = { x.first + dx[d], x.second + dy[d] };
						mn[dist] = dis[it->first][it->second];
					}
					dist++;
				}
			}
			return mxpnt[min_element(mn.begin(), mn.end()) - mn.begin()];
		}
	};
	template<class _Ty, const int tp>
	struct VS_AI {
		string type = "AI";
		_Ty operator() (_Ty x, int& dir, const int xmax, const int ymax) {
			vector<_Ty> mxpnt(apples.size(), { x.first + dx[dir], x.second + dy[dir] });
			vector<int> mn(apples.size(), 1e9);
			for (int d = 0; d < 4; d++) {
				memset(dis, 0, sizeof(dis));
				if (x.first + dx[d] < 0 || x.first + dx[d] >= xmax || x.second + dy[d] < 0 || x.second + dy[d] >= ymax || st(tp).count({ x.first + dx[d],x.second + dy[d] }) || st((tp == 1 ? 2 : 1)).count({ x.first + dx[d],x.second + dy[d] })) continue;
				queue<_Ty> q;
				q.emplace(x.first + dx[d], x.second + dy[d]);
				while (!q.empty()) {
					unpackpair(X, Y, q.front()); q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = X + dx[i], ny = Y + dy[i];
						if (nx < 0 || nx >= xmax || ny < 0 || ny >= ymax || dis[nx][ny] || st(tp).count({nx,ny})) continue;
						q.emplace(nx, ny);
						dis[nx][ny] = dis[X][Y] + 1;
					}
				}
				int dist = 0;
				for (auto it = apples.begin(); it != apples.end(); it++) {
					if (dis[it->first][it->second] < mn[dist]) {
						mxpnt[dist] = { x.first + dx[d], x.second + dy[d] };
						mn[dist] = dis[it->first][it->second];
					}
					dist++;
				}
			}
			return mxpnt[min_element(mn.begin(), mn.end()) - mn.begin()];
		}
	};
	pair<int, int> apple(const int xmax, const int ymax) {
		int w = rand() % 3;
		pair<int, int> pr;
		auto rangepair = [&]() {
			if (!w)pr = { rand() % (xmax - 2) + 1, rand() % (ymax - 2) + 1 };
			else pr = { rand() % (xmax - 3) + 2, rand() % (ymax - 3) + 2 };
		};
		while (snakebodies.count(pr) || apples.count(pr)) rangepair();
		return pr;
	}
	const int random_startsnake(deque<pair<int, int> > &s, const int xmax, const int ymax, const short len, const short col = 2) {
		s.clear();
		int x = rand() % (xmax - len - 3) + 3, y = rand() % (ymax - len - 3) + 3;
		snakebodies.emplace(x, y);
		s.emplace_back(x, y);
		printhead(x, y);
		const int d = rand() % 4;
		for (short i = 1; i < len; i++) {
			x = x + dx[d], y = y + dy[d];
			s.emplace_back(x, y);
			print(x, y, col);
			snakebodies.emplace(x, y);
		}
		return nxt[d];
	}
}
template<
	const size_t _Size = 10,
	class _GenMove = judge::RMove<pair<int, int> >,
	class _EngineMove = judge::AI<pair<int, int> >,
	const size_t EngineVal = 0,
	class _CTy = vector<string>,
	class _Container = deque<pair<int, int> >,
	class _DeathJudge = judge::__illegal_move<pair<int,int> > >
struct Snake {
	_Container  _Body;
	_GenMove       f;
	_EngineMove    eng;
	_DeathJudge die;
	const size_t      SnakeSize;
	vector<int> engines, red;
	vector<_Container> engine_body, red_body;
	const int (*init)(deque<pair<int, int> >&, const int, const int, const short, const short) = judge::random_startsnake;
	pair<int, int> (*apple)(const int xmax, const int ymax) = judge::apple;
	judge::RMove<pair<int,int> > human_const;
	size_t      Delay;
	const size_t      Size = _Size;
	_CTy        _SnakeMap;
	const size_t      val = EngineVal;
	void initmap() {
		_SnakeMap = vector<string>(Size);
		for (int i = 0; i < Size; i++) for (int j = 0; j < Size; j++)
			if (i == 0 || j == 0 || i == Size - 1 || j == Size - 1) _SnakeMap[i].push_back('#');
			else _SnakeMap[i].push_back(' ');
		for (int i = 0; i < Size; i++) cout << _SnakeMap[i] << '\n';
	}
	void start(const int _Delay) {
		_SnakeMap.clear();
		snakebodies.clear();
		apples.clear();
		_Body.clear();
		engine_body.clear();
		engines.clear();
		Delay = _Delay;
		initmap();
		srand(time(0));
		int nxtd = 0;
		nxtd = init(_Body, Size - 2, Size - 2, (short)SnakeSize, 12);
		for (int i = 0; i < val; i++) engine_body.emplace_back(), engines.emplace_back(init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2));
		for (int i=0;i<3;i++)putapple(apple(Size-2, Size-2));
		for (int step=6;;step++) {
			if(step==6)step=0,putapple(apple(Size - 2, Size - 2));
			unpackpair(x, y, f(_Body.front(), nxtd, Size - 2, Size - 2));
			if (x == -1 && y == -1) return;
			else if (x == -1) {
				SetPos(1, Size);
				system("pause");
				SetPos(1, Size);
				printf("                        ");
				continue;
			}
			if (die(x, y, Size - 2, Size - 2)) {
				system("cls");
				SetPos(0, 0);
				fflush(stdout);
				color(12);
				if (f.type == "AI")cout << "AI DIE\n分数: "<<_Body.size();
				else cout << "YOU DIE\n分数: "<<_Body.size();
				color(15);
				system("pause");
				fflush(stdin);
				fflush(stdout);
				return;
			}
			snakebodies.emplace(x, y);
			if (!apples.count({ x,y })) {
				snakebodies.erase(_Body.back());
				clear(_Body.back());
				_Body.pop_back();
			}
			else apples.erase({x,y});
			print(_Body.front(), 12);
			printhead(x,y);
			_Body.emplace_front(x, y);
			for (int i = 0; i < val; i++) {
				pair<int,int> pr = engine_body[i].front();
				unpackpair(X, Y, eng(pr, engines[i], Size - 2, Size - 2));
				if (die(X, Y, Size - 2, Size - 2)) {
					color(12);
					while (!engine_body[i].empty()) putapple(engine_body[i].front()), snakebodies.erase(engine_body[i].front()), engine_body[i].pop_front();
					engines[i] = init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2);
					continue;
				}
				snakebodies.emplace(X, Y);
				if (!apples.count({ X,Y })) {
					snakebodies.erase(engine_body[i].back());
					clear(engine_body[i].back());
					engine_body[i].pop_back();
				}
				else apples.erase({ X,Y });
				print(engine_body[i].front());
				printhead(X, Y);
				engine_body[i].emplace_front(X, Y);
			}
			Sleep(Delay);
		}
	}
	void vs(const int _My, const int _Opp, const int _Delay) {
		my.clear(); op.clear();apples.clear();engines.clear();engine_body.clear();red.clear();Delay = _Delay;_SnakeMap.clear();
		reds = greens = 0;
		initmap();
		srand(time(0));
		for (int i = 0; i < _My; i++) red_body.emplace_back(), red.emplace_back(init(red_body[i], Size - 2, Size - 2, (short)SnakeSize, 12));
		for (int i = 0; i < _Opp; i++) engine_body.emplace_back(), engines.emplace_back(init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2));
		for (int i = 0; i < 3; i++)putapple(apple(Size-2, Size-2));
		for (int step = 6;; step++) {
			if (step == 6)step = 0, putapple(apple(Size - 2, Size - 2));
			if (reds >= 300) {
				printf("红方胜利\n");
				system("pause");
				break;
			}
			if (greens >= 300) {
				printf("绿方胜利\n");
				system("pause");
				break;
			}
			for (int i = 0; i < _My; i++) {
				pair<int, int> pr = red_body[i].front();
				unpackpair(X, Y, f(pr, red[i], Size - 2, Size - 2));
				if (X < 0 || X >= Size-2 || Y < 0 || Y >= Size-2 || op.count({ X,Y })) {
					color(12);
					while (!red_body[i].empty()) putapple(red_body[i].front()), my.erase(red_body[i].front()), red_body[i].pop_front();
					red[i] = init(red_body[i], Size - 2, Size - 2, (short)SnakeSize, 12);
					continue;
				}
				my.emplace(X, Y);
				if (!apples.count({ X,Y })) {
					my.erase(red_body[i].back());
					clear(red_body[i].back());
					red_body[i].pop_back();
				}
				else apples.erase({ X,Y }), reds++;
				print(red_body[i].front(), 12);
				printhead(X, Y);
				red_body[i].emplace_front(X, Y);
			}
			for (int i = 0; i < _Opp; i++) {
				pair<int, int> pr = engine_body[i].front();
				unpackpair(X, Y, eng(pr, engines[i], Size - 2, Size - 2));
				if (X < 0 || X >= Size - 2 || Y < 0 || Y >= Size - 2 || my.count({ X,Y })) {
					color(12);
					while (!engine_body[i].empty()) putapple(engine_body[i].front()), op.erase(engine_body[i].front()), engine_body[i].pop_front();
					engines[i] = init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2);
					continue;
				}
				op.emplace(X, Y);
				if (!apples.count({ X,Y })) {
					op.erase(engine_body[i].back());
					clear(engine_body[i].back());
					engine_body[i].pop_back();
				}
				else apples.erase({ X,Y }), greens++;
				print(engine_body[i].front());
				printhead(X, Y);
				engine_body[i].emplace_front(X, Y);
			}
			Sleep(Delay);
		}
	}
	void plrvs(const int _My, const int _Opp, const int _Delay) {
		reds = greens = 0;
		my.clear(); op.clear(); apples.clear(); engines.clear(); engine_body.clear(); red.clear(); Delay = _Delay; _SnakeMap.clear();
		initmap();
		srand(time(0));
		for (int i = 0; i < _My; i++) red_body.emplace_back(), red.emplace_back(init(red_body[i], Size - 2, Size - 2, (short)SnakeSize, i==0?6:12));
		for (int i = 0; i < _Opp; i++) engine_body.emplace_back(), engines.emplace_back(init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2));
		for (int i = 0; i < 3; i++)putapple(apple(Size - 2, Size - 2));
		for (int step = 6;; step++) {
			if (step == 6)step = 0, putapple(apple(Size - 2, Size - 2));
			if (reds >= 300) {
				printf("红方胜利\n");
				system("pause");
				break;
			}
			if (greens >= 300) {
				printf("绿方胜利\n");
				system("pause");
				break;
			}
			for (int i = 0; i < _My; i++) {
				pair<int, int> pr = red_body[i].front();
				pair<int, int> pr1;
				if (i != 0)pr1 = f(pr, red[i], Size - 2, Size - 2);
				else pr1 = human_const(pr, red[i], Size - 2, Size - 2);
				unpackpair(X, Y, pr1);
				if (X < 0 || X >= Size - 2 || Y < 0 || Y >= Size - 2 || op.count({ X,Y })) {
					color(12);
					while (!red_body[i].empty()) putapple(red_body[i].front()), my.erase(red_body[i].front()), red_body[i].pop_front();
					red[i] = init(red_body[i], Size - 2, Size - 2, (short)SnakeSize, i==0?6:12);
					continue;
				}
				my.emplace(X, Y);
				if (!apples.count({ X,Y })) {
					my.erase(red_body[i].back());
					clear(red_body[i].back());
					red_body[i].pop_back();
				}
				else apples.erase({ X,Y }), reds++;
				print(red_body[i].front(), i==0?6:12);
				printhead(X, Y);
				red_body[i].emplace_front(X, Y);
			}
			for (int i = 0; i < _Opp; i++) {
				pair<int, int> pr = engine_body[i].front();
				unpackpair(X, Y, eng(pr, engines[i], Size - 2, Size - 2));
				if (X < 0 || X >= Size - 2 || Y < 0 || Y >= Size - 2 || my.count({ X,Y })) {
					color(12);
					while (!engine_body[i].empty()) putapple(engine_body[i].front()), op.erase(engine_body[i].front()), engine_body[i].pop_front();
					engines[i] = init(engine_body[i], Size - 2, Size - 2, (short)SnakeSize, 2);
					continue;
				}
				op.emplace(X, Y);
				if (!apples.count({ X,Y })) {
					op.erase(engine_body[i].back());
					clear(engine_body[i].back());
					engine_body[i].pop_back();
				}
				else apples.erase({ X,Y }), greens++;
				print(engine_body[i].front());
				printhead(X, Y);
				engine_body[i].emplace_front(X, Y);
			}
			Sleep(Delay);
		}
	}
	Snake(const int siz) : Delay(0), SnakeSize(siz) {}
};
void len() {
lenlen:
	system("cls");
	color(3);
	printf(" | 蛇长设置 | 输入新初始长度 (1-10之间的一个整数): ");
	string st;
	getline(cin, st);
	bool flag = true;
	for (int i = 0; i < st.size(); i++) flag &= st[i] >= '0' && st[i] <= '9';
	if (!flag) {
		printf("蛇长不正确\n"), Sleep(500);
		goto lenlen;
	}
	if (stoi(st) == 0 || stoi(st) > 10) {
		printf("蛇长不正确\n"), Sleep(500);
		goto lenlen;
	}
	length = stoi(st);
	color(2);
	printf(" 设置成功!\n");
	color(15); Sleep(700);
}
void run() {
	color(15);
	system("cls"); printf(" 游戏中内容: [");
	color(12);
	putchar('X');
	color(15);
	printf("]: 苹果, [");
	putchar('#');
	printf("] : 墙, [");
	color(2);
	putchar('#');
	color(15);
	printf("] : 敌方蛇身, [");
	color(12);
	putchar('#');
	color(15);
	printf("] : 我方蛇身, [");
	color(6);
	putchar('#');
	color(15);
	printf("] : 玩家蛇身, [");
	color(3);
	putchar('@');
	color(15);
	printf("] : 蛇头\n"); printf(" 游戏中操作: [W]: 上, [A]: 左, [S]: 下, [D]: 右, [Q]: 退出游戏, [T]: 暂停\n");
	color(10);
	SetPos(1, 3);
	printf("|贪吃蛇游戏| 按   返回"); color(11);
	SetPos(16, 3); printf("[`]"); color(14);
	printf("\n\n ————————————"); SetPos(1, 7);
	printf("|单人模式| [A]"); SetPos(1, 9);
	printf("|单机展示| [S]"); SetPos(1, 11);
	printf("|人机对战| [D]"); SetPos(1, 13);
	printf("|无尽模式| [W]"); SetPos(1, 15);
	printf("|AI团战| [Z]"); SetPos(1, 17);
	printf("|团战模式| [T]"); SetPos(1, 19);
	printf("|设置| [F]"); SetPos(1, 21);
	char c;
	while (1) if (_kbhit()) {
			c = _getch();
			if (c=='a'||c=='A'){
				system("cls");
				printf("请输入刷新时间(ms): ");
				color(15);
				string st;
				getline(cin, st);
				bool flag = true;
				for (int i = 0; i < st.size(); i++) flag &= st[i] >= '0' && st[i] <= '9';
				int time = 100;
				if (!flag) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				else time = stoi(st);
				if (time == 0 || time > 0xffff) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				system("cls");
				Snake<40> s(length);
				s.start(time);
				run();
			}
			else if (c=='s'||c=='S') {
				system("cls");
				Snake<40, judge::AI<pair<int, int> > > s(length);
				s.start(50);
				run();
			}
			else if (c=='d'||c=='D') {
				system("cls");
				printf("请输入刷新时间(ms): ");
				color(15);
				string st;
				getline(cin, st);
				bool flag = true;
				for (int i = 0; i < st.size(); i++) flag &= st[i] >= '0' && st[i] <= '9';
				int time = 100;
				if (!flag) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				else time = stoi(st);
				if (time == 0 || time > 0xffff) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				system("cls");
				Snake<40, judge::RMove<pair<int, int> >, judge::AI<pair<int, int> >, 1> s(length);
				s.start(time);
				run();
			}
			else if (c=='w'||c=='W') {
				system("cls");
				printf("请输入刷新时间(ms): ");
				color(15);
				string st;
				getline(cin, st);
				bool flag = true;
				for (int i = 0; i < st.size(); i++) flag &= st[i] >= '0' && st[i] <= '9';
				int time = 100;
				if (!flag) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				else time = stoi(st);
				if (time == 0 || time > 0xffff) printf("刷新时间不正确, 已设置成默认值(100ms)\n"), Sleep(500);
				system("cls");
				Snake<40, judge::RMove<pair<int, int> >, judge::AI<pair<int, int> >, 5> s(length);
				s.start(time);
				run();
			}
			else if (c=='f'||c=='F') {
			f:
				system("cls");
				color(3);
				printf(" |设置| 按   返回"); color(11);
				SetPos(10, 0); printf("[`]"); color(14);
				printf("\n\n ————————————"); SetPos(1, 5);
				printf("|蛇长设置| [L]");
				color(15);
				while (1) if (_kbhit()) {
					char ch = _getch();
					if (ch == '`') break;
					else if (ch == 'L' || ch == 'l') { len(); goto f; }
				}
				run();
			}
			else if (c == 'z' || c == 'Z') {
				system("cls");
				Snake<40, judge::VS_AI<pair<int, int>, 1>, judge::VS_AI<pair<int, int>, 2>> s(length);
				s.vs(4, 4, 100);
				run();
			}
			else if (c == 't' || c == 'T') {
				system("cls");
				Snake<40, judge::VS_AI<pair<int, int>, 1>, judge::VS_AI<pair<int, int>, 2>> s(length);
				s.plrvs(4, 4, 100);
				run();
			}
			else if (c=='`') break;
		}
}
int main() {
	system("TITLE 贪吃蛇 v1.3.1 release 作者: williamwei, colinxu2020"); system("mode con cols=200");
	run();
}
#endif
