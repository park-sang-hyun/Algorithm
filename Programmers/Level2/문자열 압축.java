class Solution {
    public int solution(String s) {
        int answer = 1001;

		for (int cut = 1; cut <= s.length() / 2; cut++) {
			String stand = "", comp = "", newstr = "";
			int cnt = 1;

			stand += s.substring(0, cut);

			for (int i = cut; i < s.length(); i += cut) {
				if(i + cut >= s.length()) comp = s.substring(i, s.length());
				else comp = s.substring(i, i + cut);

				if (stand.equals(comp) == true)
					cnt++;
				else {
					if (cnt > 1) {
						newstr += ("" + cnt);
						cnt = 1;
					}

					newstr += stand;
					stand = comp;
				}
			}
			
			if(cnt > 1) newstr += ("" + cnt);
			newstr += stand;

			if (answer > newstr.length()) answer = newstr.length();
		}
        
        if (answer > s.length()) answer = s.length();

		return answer;
    }
}
