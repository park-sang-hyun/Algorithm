import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        Map <String, Integer> map = new HashMap<>();
        
        int[] answer = {0, 0};
        int cnt = 0, num = 0;
        char preLastWord;
        
        for(int i=0; i<words.length; i++){
            num = i % n;
            if(i % n == 0) cnt++;
            
            if(map.containsKey(words[i]) == false){
                if(words[i].length() < 2){
                    answer[0] = num + 1;
                    answer[1] = cnt;
                    return answer;
                }
                
                if(i > 0){
                    int len = words[i - 1].length() - 1;
                    
                    preLastWord = words[i - 1].charAt(len);
                    
                    if(preLastWord != words[i].charAt(0)){
                        answer[0] = num + 1;
                        answer[1] = cnt;
                        return answer;
                    }
                }
                
                map.put(words[i], num);
            }
            else{
                answer[0] = num + 1;
                answer[1] = cnt;
                return answer;
            }
            
        }
        
        return answer;
    }
}
