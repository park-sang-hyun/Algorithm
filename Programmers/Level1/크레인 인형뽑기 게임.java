import java.util.*;

class Doll{
    int height;
    int dollNum;
    
    Doll(int height, int dollNum){
        this.height = height;
        this.dollNum = dollNum;
    }
}

class Solution {
    Doll[] top = new Doll[31];
    
    public int solution(int[][] board, int[] moves) {
        Stack <Integer> stk = new Stack<>();
        int answer = 0;
        
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[i].length; j++){
                if(board[i][j] != 0 && top[j] == null) 
                    top[j] = new Doll(i, board[i][j]);
            }
        }
        
        for(int i=0; i<moves.length; i++){
            int x = moves[i] - 1;
            int dollNum = top[x].dollNum;
            
            if(dollNum == - 1) continue;
            
            if(top[x].height + 1 >= board.length) top[x].dollNum = -1;
            else {
                top[x].height++; 
                top[x].dollNum = board[top[x].height][x];
            }
            
            if(stk.empty()) stk.push(dollNum);
            else{
                if(stk.peek() == dollNum) {
                    stk.pop();
                    answer += 2;
                }
                else stk.push(dollNum);
            }
        }
        
        return answer;
    }
}
