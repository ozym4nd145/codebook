// string s as input outputs in z vector the length of  
// longest common prefix of substring starting at i 
// and s in o(n) time
void Z(string &s,vector<int> &z){
  int n = s.length();
  z.resize(n);
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    } else {
      int k = i-L;
      if (z[k] < R-i+1) z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      }
    }
  }
}