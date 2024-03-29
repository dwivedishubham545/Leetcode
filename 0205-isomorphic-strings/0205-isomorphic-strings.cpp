class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> v1(128);
    vector<int> v2(128);

    for (int i = 0; i < s.length(); ++i) {
      if (v1[s[i]] != v2[t[i]])
        return false;
      v1[s[i]] = i + 1;
      v2[t[i]] = i + 1;
    }

    return true;
  }
};