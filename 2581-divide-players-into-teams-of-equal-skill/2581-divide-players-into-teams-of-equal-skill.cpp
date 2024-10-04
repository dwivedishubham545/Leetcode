class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int targetSkill = skill[0] + skill[n - 1];
        
        long long totalChemistry = 0;
        for (int i = 0; i < n / 2; ++i) {
            int currentSkill = skill[i] + skill[n - i - 1];
            if (currentSkill != targetSkill) {
                return -1;
            }
            totalChemistry += skill[i] * skill[n - i - 1];
        }
        
        return totalChemistry;
    }
};