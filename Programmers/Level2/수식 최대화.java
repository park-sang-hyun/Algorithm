import java.util.*;

class Solution {
    String[] ex = new String[101];
    char[] kind = {'+', '-', '*'};
    boolean[] v = new boolean[3];
    String[] cases = new String[6];
    String subcase = new String();
    int len = 0, kindcnt = 0, casecnt = 0;
    long MAX = 0;

    public long solution(String expression) {
        long answer = 0;
        
        setting(expression);
        permute(0);
        answer = cal();
        
        return answer;
    }
    
    public long cal(){
        Stack <String> stk = new Stack<>();
        ArrayList <String> list = new ArrayList<>();
        
        for(int i=0; i<casecnt; i++){
            list.clear();
	        for(int j=0;j<len; j++) list.add(ex[j]);
            
            for(int j=0; j<cases[i].length(); j++){
                for(int k=list.size()-1; k>=0; k--) {
                    stk.push(list.get(k));
                    list.remove(k);
                }
                
                if(cases[i].charAt(j) =='+'){
                    long a = Long.parseLong(stk.peek());
                    stk.pop();
                    
                    while(!stk.empty()){
                        String buho = stk.peek();
                        stk.pop();
                        long b = Long.parseLong(stk.peek());
                        stk.pop();
                        
                        if(buho.equals("+")) {
                            a += b;    
                        }
                        else{
                            list.add(Long.toString(a));
                            list.add(buho);
                            
                            a = b;
                        }
                    }
                    
                    list.add(Long.toString(a));
                }
                else if(cases[i].charAt(j) =='-'){
                    long a = Long.parseLong(stk.peek());
                    stk.pop();
                    
                    while(!stk.empty()){
                        String buho = stk.peek();
                        stk.pop();
                        long b = Long.parseLong(stk.peek());
                        stk.pop();
                        
                        if(buho.equals("-")) {
                            a -= b;    
                        }
                        else{
                            list.add(Long.toString(a));
                            list.add(buho);
                            
                            a = b;
                        }
                    }
                    
                    list.add(Long.toString(a));
                }
                else if(cases[i].charAt(j) =='*'){
                    long a = Long.parseLong(stk.peek());
                    stk.pop();
                    
                    while(!stk.empty()){
                        String buho = stk.peek();
                        stk.pop();
                        long b = Long.parseLong(stk.peek());
                        stk.pop();
                        
                        if(buho.equals("*")) {
                            a *= b;    
                        }
                        else{
                            list.add(Long.toString(a));
                            list.add(buho);
                            
                            a = b;
                        }
                    }
                    
                    list.add(Long.toString(a));
                }
            }
            
            MAX = Math.max(MAX, Math.abs(Long.parseLong(list.get(0))));
        } 
        
        return MAX;
    }
    
    public void permute(int cnt){
        if(cnt == kindcnt){
            cases[casecnt++] = subcase;

            return;
        }
        
        for(int i=0; i<v.length; i++){
            if(v[i] == false) continue;
            
            subcase += kind[i];
	        v[i] = false;
	        permute(cnt + 1);
	        subcase = subcase.substring(0,subcase.length() - 1);
            v[i] = true;
        }
    }
    
    public void setting(String expression){
        String temp = "";
        
        for(int i=0; i<expression.length(); i++){
            if(expression.charAt(i) != '*' && expression.charAt(i) != '+' && expression.charAt(i) != '-' ){
                temp += expression.charAt(i);
            }
            else{
                if(expression.charAt(i) == '+') v[0] = true;
                else if(expression.charAt(i) == '-') v[1] = true;
                else if(expression.charAt(i) == '*') v[2] = true;
                
                ex[len++] = temp;
                temp = "";
                
                 ex[len++] = "" + expression.charAt(i);
            }
        }
        
        ex[len++] = temp;
        
        for(int i=0; i<v.length; i++) 
            if(v[i] == true) kindcnt++;
    }
}
