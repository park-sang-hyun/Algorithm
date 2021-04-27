import java.util.*;

class Point{
    int y;
    int x;
}

class Solution {
    int map[][] = new int[11][11];
    int v[][][][] = new int[11][11][11][11];
    
    public int solution(String dirs) {
        int answer = 0;
        Point p = new Point();
        p.y = 5;
        p.x = 5;
        
        for(int i=0; i<dirs.length(); i++){
            int ty = 0;
            int tx = 0;
            
            if(dirs.charAt(i) == 'U'){
                ty = p.y - 1;
                tx = p.x;
            }
            else if(dirs.charAt(i) == 'D'){
                ty = p.y + 1;
                tx = p.x;
            }
            else if(dirs.charAt(i) == 'R'){
                ty = p.y;
                tx = p.x + 1;
            }
            else if(dirs.charAt(i) == 'L'){
                ty = p.y;
                tx = p.x - 1;
            }
            
            if(ty < 0 || tx < 0 || ty > 10 || tx > 10) continue;
            
            if(v[p.y][p.x][ty][tx] != 1 && v[ty][tx][p.y][p.x] != 1) answer++;
            v[p.y][p.x][ty][tx] = 1;
            v[ty][tx][p.y][p.x] = 1;
            p.y = ty;
            p.x = tx;
        }

        return answer;
    }
}
