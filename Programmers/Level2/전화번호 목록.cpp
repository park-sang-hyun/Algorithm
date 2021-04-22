#include <string>
#include <vector>
#include <map>
using namespace std;

map <string, int> m;

bool solution(vector<string> phone_book) {
    for(int i=0; i<phone_book.size();i++) m[phone_book[i]] = 1;
    
    for(int i=0; i<phone_book.size(); i++) {
        string substr = "";
        
        for(int j=0; j<phone_book[i].size()-1; j++){
            substr += phone_book[i][j];
            
            if(m.find(substr) != m.end()) return false;
        }
    }
    
    return true;
}
