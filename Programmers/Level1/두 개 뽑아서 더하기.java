import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        Map <Integer, Boolean> map = new HashMap<>();
        
        int[] answer = {};
        
        for(int i=0; i<numbers.length-1; i++)
            for(int j=i+1; j<numbers.length; j++)
                if(!map.containsKey(numbers[i] + numbers[j])) map.put(numbers[i] + numbers[j], true);
        
        answer = new int[map.size()];
        int i = 0;
        
        for(int key : map.keySet()) answer[i++] = key;
        
        Arrays.sort(answer);
        
        return answer;
    }
}
