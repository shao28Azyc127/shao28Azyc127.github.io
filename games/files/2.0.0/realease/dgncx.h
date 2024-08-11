#ifndef DGNCX_H
#define DGNCX_H
#include<bits/stdc++.h>
//include from dgncx-snakev1.3.1.cpp
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
using namespace std;
class dgncx{
	public:
	void color(const int a) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); }
	void SetPos(COORD a) { HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(out, a); }
	void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
	void clear(int x, int y) {
		swap(x, y);
		SetPos(x+1, y + 1);
		putchar(' ');
	}
	void cl(){system("cls");}
	void clear(const pair<int, int> p) { clear(p.first, p.second); }
	void print(int x, int y, const int col = 2) {
		swap(x, y);
		SetPos(x + 1, y + 1);
		color(col);
		putchar('#');
		color(15);
	}
	void print(const pair<int, int> p, const int col = 2) { print(p.first, p.second, col); }
	int ri(int start,int end){
		return (rand()%(end-start+1))+start;
	}char homet(){
			cout<<"28AZYC做的硫代硫酸钠（之后准备加点别的）\n"; 
			cout<<"小提示：这里有5个彩蛋，实测均可以达成，达成方式已经公开。\n\n"; 
			char c;cout<<"====Menu===="<<endl;
			cout<<"1. 硫代硫酸钠"<<endl;
			cout<<"i. 一些信息"<<endl;
			cout<<"s. 放出声音"<<endl;
			//cout<<"c. Changelog"<<endl;
			cout<<"q. 退出游戏"<<endl;
			cout<<"选一个吧：";c=_getch();return tolower(c);
		}
		
};
/*MCServer:
1.starmc.vip:25560
2.Mc233.Cn
3.mc.cosmicmc.com
4.Kinus.cc
5.play.mcsytt.com
6.mc.remiaft.com
7.kcmc.icu
8.play.centrixpvp.eu
9.redesky.com
10.redestone.com
11.mc.minemora.net
12.mc.skycraft.com.br
13.herobrine.org
14.play.pika-network.net
15.cn-zj-bgp.sakurafrp.com:41493
16.playminecraftworld.nl:25565
17.play.mc-haze.com:25565
18.playhc.ms:25565
19.play.minemc.cn
20.MC.PIXELHAR.CN
21.jartexnetwork.com
22.omegacraft.cl
23.mc.universocraft.com
24.mumc.top
25.mc.kinomc.cn
26.librecraft.com
27.play.guldcraft.org:25565
28.play.extremecraft.net:25565
29.play.randomcraft.org:25565
30.us.play-ml.ru
31.skykingdoms.net:25565
32.nc.blockdrop.org:25565
33.LyxyCraft.cc
34.cn.mimiblock.cn
35.mcbilibili.cn
mcyc.win*/
#endif
