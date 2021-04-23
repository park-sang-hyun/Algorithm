#include <vector>

using namespace std;

int boxing[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<results.size(); i++){
        boxing[results[i][0]][results[i][1]] = 1;
        boxing[results[i][1]][results[i][0]] = -1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(boxing[i][j] == 1){
                for(int k=1; k<=n; k++){
                    if(boxing[j][k] == 1) {
                        boxing[i][k] = 1;
                        boxing[k][i] = -1;   
                    }
                }
            }
            
            if(boxing[i][j] == -1){
                for(int k=1; k<=n; k++){
                    if(boxing[j][k] == -1) {
                        boxing[i][k] = -1;
                        boxing[k][i] = 1;   
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        bool know = true;
        
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            
            if(boxing[i][j] == 0) {
                know = false;
                break;
            }
        }
        
        if(know == true) answer++;
    }
    
    return answer;
}
