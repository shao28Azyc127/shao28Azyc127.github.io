#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _distance;
vector<int> _oil;
int minOil;
int oilDis;
int pointNum;
int cost;


void ParseIn(){
  ifstream inFile("road.in");
  int curInt;
  inFile >> pointNum >> oilDis;
  for(int i = 1; i < pointNum; i++){
    inFile >> curInt;
    _distance.push_back(curInt);
  }
  inFile >> minOil;
  for(int i = 1 ;i < pointNum; i++){
    inFile >> curInt;
    _oil.push_back(curInt);
  }
  inFile.close();
}

void Core(){
  int Oilleft = 0;
  int Oilneed;
  for(int i = 0; i < _distance.size(); i++){
    Oilleft -= _distance[i];
    if(Oilleft < 0){
      Oilneed = -1*Oilleft/oilDis;
      cost+=Oilneed*minOil;
      Oilleft +=Oilneed*oilDis;
    }
    if(Oilleft<0){
      Oilleft+=oilDis;
      cost+=minOil;
    }
    if(_oil[i]<minOil){
      minOil = _oil[i];
    }
  }
}

void WriteOut(){
  ofstream outFile("road.out");
  outFile << cost << endl;
  outFile.close();
}

int main(){
  ParseIn();
  Core();
  WriteOut();
  return 0;
}
