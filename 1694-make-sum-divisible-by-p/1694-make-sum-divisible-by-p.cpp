class Solution {
public:
     int minSubarray(vector<int>& nums, int p) {

        long total_sum = 0;
        
        for (int num : nums) {
            total_sum += num;
        }
        int mod = total_sum % p;

        if (mod == 0)
            return 0;

        unordered_map<int, int> mod_index;
        mod_index[0] = -1;

        unsigned long  local_sum = 0;
        int array_lenght = nums.size();
        int min_lenght = array_lenght;
        
        for (int i = 0; i < array_lenght; i++) {
           
            local_sum += nums[i];

            int current_mod = local_sum % p;

            int need_mod = (current_mod - mod + p) % p;

            if(mod_index.count(need_mod)){
                int lenght = i - mod_index[need_mod];
                if(lenght < min_lenght){
                    min_lenght = lenght;
                }
            }
   
            mod_index[current_mod] = i;
        }
        if (min_lenght == array_lenght)
            return -1;
        return min_lenght;
     }
};