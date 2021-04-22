#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int tail = people.size() - 1;
    
    sort(people.begin(), people.end(), comp);
    
    for(int i=0; i<people.size(); i++){
        answer++;
        
        if(limit >= people[i] + people[tail]) tail--;
        if(i >= tail) break; 
    }
    
    return answer;
}
