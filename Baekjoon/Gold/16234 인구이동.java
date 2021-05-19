import java.io.*;
import java.util.*;
public class Main {
	static int a[][];
	static int v[][];
	static int s[];
	static int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
	static int n, l, r, tc;
	
	static Queue<Pair> q = new LinkedList<>();
	
	static class Pair {
	    int y;
	    int x;	 
	    Pair(int y, int x) {
	        this.y = y;
	        this.x = x;
	    }
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int mv = 0;
		
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		a = new int[n][n];
		v = new int[n][n];
		s = new int[n * n + 1];
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; j++) a[i][j] = Integer.parseInt(st.nextToken());
		}
		
		while (true) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) v[i][j] = 0;

			tc = 0;
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < n; j++) 
					if (v[i][j] == 0) {
						tc++;
						BFS(i, j);
					}

			if (tc == n * n) break;

			for (int i = 0; i < n; i++) 
				for (int j = 0; j < n; j++) 
					if (v[i][j] != 0) a[i][j] = s[v[i][j]];

			mv++;
		}
		
		System.out.print(mv);
	}
	
	static void BFS(int y, int x) {
		int cnt = 0;
		int sum = 0;

		v[y][x] = tc;
		sum += a[y][x];
		cnt++;
		q.add(new Pair(y,x));

		while (!q.isEmpty()) {
			Pair t = q.poll();

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];

				if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
				
				int gap = Math.abs(a[t.y][t.x] - a[ty][tx]);
				if (gap >= l && gap <= r && v[ty][tx]==0) {
					v[ty][tx] = tc;
					sum += a[ty][tx];
					cnt++;
					q.add(new Pair(ty,tx));
				}
			}
		}
		s[tc] = sum / cnt;
	}
}
