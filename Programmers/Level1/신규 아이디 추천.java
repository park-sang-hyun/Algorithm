import java.util.*;

class Solution {
    public String solution(String new_id) {
        ArrayList<Character> str = new ArrayList<>();
        
        String answer = "";
        
        for(int i=0; i<new_id.length(); i++){
            char word = new_id.charAt(i);
            
            if(word >= 'A' && word <= 'Z') {
                word += 32;
                str.add(word);
            }
            else str.add(word);
        }
        
        for(int i=0;i<str.size();i++){
            char word = str.get(i);
            
            if((word >= 'a' && word <='z') || (word >= '0' && word <= '9') || word == '-' || word == '_' || word == '.'){
                continue;
            }
            else{
                str.remove(i);
                i--;
            }
        }
        
        for(int i=0; i<str.size(); i++){
            if(i < str.size() - 1 && str.get(i) == '.' && str.get(i + 1) == '.'){
                str.remove(i);    
                i--;   
            }
        }
        
        for(int i=0; i<str.size(); i++){            
            if(i == 0 || i == str.size() - 1)
                if(str.get(i) == '.') {
                    str.remove(i);
                    i--;
                }
        }
        
        if(str.size() == 0) str.add('a');
        
        if(str.size() > 15) {
            for(int i=15; i<str.size(); i++) {
                str.remove(i);
                i--;
            }
            
            if(str.get(14) == '.') str.remove(14);
        }
        
        if(str.size() < 3){
            char last = str.get(str.size() - 1);
            
            while(str.size() < 3) str.add(last);
        }
        
        for(int i=0; i<str.size(); i++) answer += str.get(i);
        
        return answer;
    }
}
