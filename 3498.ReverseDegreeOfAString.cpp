class Solution { 
  public:
    int reverseDegree(string su) { 
      int res = 0;
      for (int i = 0; i < (int)su.size(); i++) { 
        res += (26 - (su[i] - 'a')) * (i + 1); 
      }
      return res;
    } 
};

