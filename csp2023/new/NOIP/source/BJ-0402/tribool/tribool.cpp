

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Number{
  int _place;
  bool _same;
  int _step;
  int _myNum;
};

struct Binary{
  char _do;
  int _one;
  int _two;
};

int _point;
int _group;
int _num,_maxi;
int _res = 0;
vector<Number> _array;
vector<Number> _sortArray;

vector<Binary> _binaryList;

void Clear(int solo) {
  Number curStruct;
  _array.clear();
  _sortArray.clear();
  
  for(int i = 0; i < solo + 5; i++) {
    _array.push_back(curStruct);
    _array[i]._place = i;
    _array[i]._same = true;
    _array[i]._step = 0;
    _array[i]._myNum = i;
  }
}

bool CompareStep(Number one,Number two) {
  return one._step < two._step;
}

bool CheckSolo(string curString) {
  for(int i = 0; i < curString.length(); i++) {
    if(curString[i] != '2') {
      return true;
    }
  }

  return false;
}

int main () {
  char solo;
  int curInt,curIntTwo;
  
  ifstream inFile("tribool.in");
  ofstream outFile("tribool.out");

  inFile >> _point >> _group;
  // cout << _point << " " << _group << endl;
  
  if(_point ==1 || _point == 2) {
    string curString,curStringTwo;
    Binary curStruct;
    
    for(int i = 0; i < _group; i++) {
      inFile >> _num >> _maxi;

      curString = "";
      curStringTwo = "";
      _res = 1000000009;
      _binaryList.clear();

      for(int m = 0; m < _num; m++) {
	curString += '0';
      }
      
      for(int m = 0; m < _maxi; m++) {
	inFile >> curStruct._do;
	
	switch(curStruct._do) {
	case 'T':
	  inFile >> curStruct._one;
	  break;
	  
	case 'F':
	  inFile >> curStruct._one;
	  break;
	
	case 'U':
	  inFile >> curStruct._one;
	  break;
	  
	case '+':
	  inFile >> curStruct._one >> curStruct._two;
	  break;
	
	case '-':
	  inFile >> curStruct._one >> curStruct._two;
	  break;
	}

	curStruct._one --;
	curStruct._two--;
	_binaryList.push_back(curStruct);
      }
      
      curStringTwo = curString;
      while(CheckSolo(curString)) {
	curStringTwo = curString;
	//	cout << curStringTwo << endl;
	
	for(int m = 0; m < _binaryList.size(); m++) {
	  //	  cout << _binaryList[m]._do << endl;
	  
	  switch(_binaryList[m]._do) {
	  case 'T':
	    curStringTwo[_binaryList[m]._one] = '0';
	    break;
	    
	  case 'F':
	    cout << 2 << endl;
	    curStringTwo[_binaryList[m]._one] = '1';
	    break;
	    
	  case 'U':
	    curStringTwo[_binaryList[m]._one] = '2';
	    break;
	    
	  case '+':
	    curStringTwo[_binaryList[m]._one] = curStringTwo[_binaryList[m]._two];
	    break;
	    
	  case '-':
	    if(curStringTwo[_binaryList[m]._two] =='0') {
	      curStringTwo[_binaryList[m]._one] = '1';
	      break;
	    }
	    
	    if(curStringTwo[_binaryList[m]._two] == '1') {
	      curStringTwo[_binaryList[m]._one] = '0';
	      break;
	    }
	    
	    curStringTwo[_binaryList[m]._one] = '2'; 
	    break;
	  }
	}
	
	//	cout << curString << " " << curStringTwo << endl;
	
	if(curStringTwo == curString) {
	  int cc = 0;
	  
	  for(int m = 0; m < curString.length(); m++){
	    if(curString[m] == '2') {
	      cc++;
	    }
	  }

	  _res = min(_res,cc);
	}
	
	curString[curString.length() - 1]++;
	
	for(int m = curString.length() - 1; m > -1; m--) {
	  if(curString[m] == '3') {
	      curString[m] = '0';
	      curString[m - 1] ++;
	      continue;
	  }
	  break;
	}
	
      }
      //+++++++++++++++++++++++++++++++++++++++++++++++++++


      curStringTwo = curString;

      
      for(int m = 0; m < _binaryList.size(); m++) {
	switch(_binaryList[m]._do) {
	case 'T':
	  curStringTwo[_binaryList[m]._one] = '0';
	  break;
	    
	case 'F':
	  curStringTwo[_binaryList[m]._one] = '1';
	  break;
	  
	case 'U':
	  curStringTwo[_binaryList[m]._one] = '2';
	  break;
	  
	case '+':
	  curStringTwo[_binaryList[m]._one] = curStringTwo[_binaryList[m]._two];
	  break;
	  
	case '-':
	  if(curStringTwo[_binaryList[m]._two] == '0') {
	      curStringTwo[_binaryList[m]._one] = '1';
	      break;
	  }
	  
	  if(curStringTwo[_binaryList[m]._two] == '1') {
	    curStringTwo[_binaryList[m]._one] = '2';
	  }
	  
	  curStringTwo[_binaryList[m]._one] = '2'; 
	  break;
	}
      }
      
      if(curStringTwo == curString) {
	int cc = 0;
	
	for(int m = 0; m < curString.length(); m++){
	  if(curString[m] == '2') {
	    cc++;
	  }
	}
	
	_res = min(_res,cc);
	
      }
        outFile << _res << endl;
    }
    
    return 0;
  }
  
  
  
  //__________________________________________________________________
  
  



  
  for(int i = 0; i < _group; i++) {
    inFile >> _num >> _maxi;
    
    _res = 0;
    Clear(_num);
    
    for(int m = 0; m < _maxi; m++) {
      inFile >> solo;
   
      switch(solo) {
      case 'T':
	inFile >> curInt;
	_array[curInt]._place = -1;
	_array[curInt]._same = true;
	_array[curInt]._step = m;
	break;

      case 'F':
	inFile >> curInt;
	_array[curInt]._place = -2;
	_array[curInt]._same = true;
	_array[curInt]._step = m;
	break;

      case 'U':
	inFile >> curInt;
	//	cout << curInt << endl;
	_array[curInt]._place = -3;
	_array[curInt]._same = true;
	_array[curInt]._step = m;
	break;

      case '+':
	inFile >> curInt >> curIntTwo;
	_array[curInt]._place = _array[curIntTwo]._place;
	_array[curInt]._same = _array[curIntTwo]._same;
	_array[curInt]._step = m;
	break;

      case '-':
	inFile >> curInt >> curIntTwo;
	_array[curInt]._place = _array[curIntTwo]._place;
	_array[curInt]._same = !(_array[curIntTwo]._same);
	_array[curInt]._step = m;
	break;
      }
    }

     // cout << solo << endl;
    
    for(int m = 1; m < _num + 1; m++) {
      if(_array[m]._place == -3) {
	_res++;
      }
      
      if(_array[m]._place == m && !_array[m]._same) {
	_res ++;
	_array[m]._place = -3;
	_array[m]._step = -1;
      }
    }

    _sortArray = _array;
    sort(_sortArray.begin(),_sortArray.end(),CompareStep);

    for(int m = 1; m < _num + 1; m++) {
      if(_array[_array[m]._place]._place < 0 && _array[m]._step > _array[_array[m]._place]._step) {
	if(_array[_array[m]._place]._place == -3) {
	  _res++;
	  continue;
	}
      }
    }
    
    outFile << _res << endl;
  }
  
  inFile.close();
  outFile.close();
  
  return 0;
}
