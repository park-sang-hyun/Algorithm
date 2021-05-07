#include <string>
#include <vector>
#include <map>
using namespace std;

struct PERSON{
    string id;
    bool doing;
};

vector <PERSON> v;
map <string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0; i <record.size(); i++){
        string ord="", id="", nick="";
        
        int cnt = 0;
        for(int j=0;j<record[i].size(); j++){
            if(record[i].at(j) == ' ') {
                cnt++;
                continue;
            }
            
            if(cnt == 0) ord += record[i].at(j);
            if(cnt == 1) id += record[i].at(j);
            if(cnt == 2) nick += record[i].at(j);
        }
        
        if(ord == "Enter"){
            v.push_back({id, false});
            m[id] = nick;
        }
        else if(ord == "Change"){
            m[id] = nick;
        }
        else{
            v.push_back({id, true});
        }  
    }
    
    for(int i=0; i<v.size(); i++){
        string res="";
        
        res += m[v[i].id];
        res += "님이 ";
        if(v[i].doing == false) res += "들어왔습니다.";
        else res += "나갔습니다.";
        
        answer.push_back(res);
    }
    
    return answer;
}
