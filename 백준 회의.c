#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
int _max;


void dfs(vector<pair<int, int>> time, int last, int idx, int cnt){
      
      if(idx==time.size()) {
            _max = max(_max, cnt);
      }
      if(time[idx].first<last) return;
      ++cnt;
      
      for(int i=idx;i<time.size();++i){
            dfs(time, time[idx].second, i+1, cnt);
      }
}

int main(void){
      
      int n;
      _max=-1;
      vector<pair<int, int>> time;
      cin >> n;
      while(n--){
            int x;
            int y;
            cin >> x >> y;
            time.push_back(make_pair(x, y));
      }
      
      sort(time.begin(), time.end());
      dfs(time, 0, 0, 0);
      
      cout<<_max<<endl;
      
      
      return 0;
}
