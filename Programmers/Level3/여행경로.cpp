#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool v[10001];
int maxx;
vector<string> answer, temp;

bool cmp(vector<string> &a, vector<string> &b){
	return a < b;
}

void dfs(vector<vector<string>> &tickets, string start){
    for(int i=0;i<tickets.size();i++){
        if(v[i]==false && tickets[i][0]==start){
            v[i] = true;
            temp.push_back(tickets[i][1]);
            if(maxx < temp.size()){
                maxx = temp.size();
                answer.clear();
                for(int j=0;j<temp.size();j++) answer.push_back(temp[j]);
            }
            dfs(tickets, tickets[i][1]);
            temp.pop_back();
            v[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    
    temp.push_back("ICN");
    dfs(tickets, "ICN");
    
    return answer;
}
