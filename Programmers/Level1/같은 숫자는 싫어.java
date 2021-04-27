import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> list = new ArrayList<>();
        int[] answer = {};
 
        int same = arr[0];
        list.add(same);
        
        for(int i=1;i<arr.length;i++){
            same = arr[i];
            
            if(arr[i] == arr[i-1]) continue;
            
            list.add(same);   
        }

        answer = new int[list.size()];
        for(int i=0;i<list.size();i++) answer[i] = list.get(i);

        return answer;
    }
}
