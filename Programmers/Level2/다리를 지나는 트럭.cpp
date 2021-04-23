#include <string>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int order = 0, complete = 0;
    
    for(int i=0; i<bridge_length; i++) q.push(0);
    
    while(truck_weights.size() > complete){
        if(q.front() != 0) {
            weight += q.front();
            complete++;
        }
        q.pop();
        
        if(order < truck_weights.size() && weight >= truck_weights[order]) {
            weight -= truck_weights[order];
            q.push(truck_weights[order]);
            order++;
        }else{
            q.push(0);
        }      
        
        answer++;
    }
    
    return answer;
}
