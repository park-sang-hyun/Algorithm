#include <vector>
using namespace std;

int map[61][61];
int tkey[4][21][21];
int keylen, locklen;

bool check(){
    for(int i=keylen; i<keylen+locklen; i++)
        for(int j=keylen; j<keylen+locklen; j++)
            if(map[i][j] != 1) return false;
    
    return true;
}

void takeIn(int k, int y, int x){
    for(int i=0; i<keylen; i++)
        for(int j=0; j<keylen; j++) map[i+y][j+x] += tkey[k][i][j];
}

void takeOut(int k, int y, int x){
    for(int i=0; i<keylen; i++)
        for(int j=0; j<keylen; j++) map[i+y][j+x] -= tkey[k][i][j];
}

void turn90(int from, int to){
    for(int i=0; i<keylen; i++)
        for(int j=0; j<keylen; j++) tkey[to][i][j] = tkey[from][keylen-1-j][i];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keylen = key.size();
    locklen = lock.size();
    
    for(int i=0; i<keylen; i++)
        for(int j=0; j<keylen; j++) tkey[0][i][j] = key[i][j];
    
    turn90(0, 1);
    turn90(1, 2);
    turn90(2, 3);
    
    for(int i=0; i<locklen; i++)
        for(int j=0; j<locklen; j++) map[i+keylen][j+keylen] = lock[i][j];
            
    for(int i=0; i<keylen+locklen; i++)
        for(int j=0; j<keylen+locklen; j++){
            for(int k=0; k<4; k++){
                takeIn(k, i, j);
                if(check() == true) return true;
                takeOut(k, i, j);
            }  
        }
    
    return false;
}
