#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector <int> three;

void change3(int n){
    bool start = false;
    
    for(int i=16; i>=0; i--){
        int p = pow(3, i);

        if(n / p != 0 && start == false) start = true;
        if(start == true) three.push_back(n / p); 

        n %= p;
    }
}

int change10(){
    int ten = 0;
    
    for(int i=three.size()-1; i>=0; i--){
        int p = pow(3, i);
        
        ten += p * three.back();
        three.pop_back();
    }
    
    return ten;
}

int solution(int n) {
    change3(n);
    
    return change10();
}
