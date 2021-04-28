import java.util.*;

class T{
    int town;
    int len;
    
    T(int town, int len){
        this.town = town;
        this.len = len;
    }
}

class Solution {
    int[][] map = new int[51][51];
    int[] minlen = new int[51];
    int INF = 987654321;
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        for(int i=1; i<=N; i++){
            minlen[i] = INF;
            
            for(int j=1; j<=N; j++) map[i][j] = INF;
        }
        
        for(int i=0; i< road.length; i++){
            int to = road[i][0];
            int from = road[i][1];
            int len = road[i][2];
            
            if(map[to][from] > len) map[to][from] = map[from][to] = len;
        }
        
        answer = go(N, K);
        
        return answer;
    }
    
    public int go(int N, int K){
        int ans = 0;
        
        Queue <T> q = new LinkedList<>();
        
        q.add(new T(1, 0));
        minlen[1] = 0;
        
        while(!q.isEmpty()){
            T r = q.peek();
            q.poll();
            
            if(r.len > K) continue;
            
            for(int i=1; i<=N; i++){
                if(map[r.town][i] != INF){
                    if(minlen[i] > r.len + map[r.town][i]){
                        q.add(new T(i, r.len + map[r.town][i]));
                        minlen[i] = r.len + map[r.town][i];
                    }
                }
            }
        }
        
        for(int i=1; i<=N; i++) 
            if(minlen[i] <= K) ans++;
        
        return ans;
    }
}
