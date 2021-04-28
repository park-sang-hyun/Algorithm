import java.util.*;

class Solution {   
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        long answer = 0;
        
        for(int i=0; i<works.length; i++) pq.add(-works[i]);
        
        while(n > 0){
            int MAX = 0, MAX2 = 0, cnt = 0;
            
            MAX = -pq.poll();
            cnt++;
            
            while(!pq.isEmpty()){
                MAX2 = -pq.poll();
                
                if(MAX2 != MAX) break;
                
                cnt++;
            }
            
            if(MAX != MAX2) pq.add(-MAX2);
            
            int cha = MAX - MAX2;
            
            if(cha > 0 && cha * cnt <= n ){
                for(int i=0; i<cnt; i++) pq.add(-(MAX - cha));
                n -= cha * cnt;
            }
            else{
                int totalminus = n / cnt;
                
                if(totalminus > 0){
                    for(int i=0; i<cnt; i++) pq.add(-(MAX - totalminus));

                    n -= totalminus * cnt;
                }
                else{
                    for(int i=0; i<n; i++) pq.add(-(MAX - 1));
                    for(int i=0; i<cnt - n; i++) pq.add(-MAX);
                    
                    n = 0;
                }
            }
            
        }
        
        while(!pq.isEmpty()){
            long work = -(long)pq.poll();
            if(work < 0) work = 0;
            
            answer += work * work;
        }
        
        return answer;
    }
}
