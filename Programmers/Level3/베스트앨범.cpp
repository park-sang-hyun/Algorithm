#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> cnt;
map <string, vector<pair<int, int> > > m;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int> > v;
    vector<pair<int, int> > vv;
    
    for(int i=0;i<genres.size();i++){
        cnt[genres[i]] += plays[i];
        
        m[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    for(auto i=cnt.begin();i!=cnt.end();i++) v.push_back(make_pair(i->first, i->second));
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++){
        string gr = v[i].first;

        for(int j=0; j<m[gr].size();j++) vv.push_back(make_pair(m[gr][j].first, m[gr][j].second));
        
        sort(vv.begin(), vv.end(), cmp2);
        
        for(int j=0;j<vv.size();j++) {
            answer.push_back(vv[j].second);
            if(j == 1) break;
        }
        
        vv.clear();
    }
    
    return answer;
}
