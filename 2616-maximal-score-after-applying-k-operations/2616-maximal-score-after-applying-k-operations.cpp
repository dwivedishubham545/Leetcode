class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long score = 0;
        for(auto it : nums){
            pq.push(it);
        }

        while(k){
            int temp = pq.top();
            pq.pop();
            score += temp;

            if(temp%3 ==0 ){
                pq.push(temp/3);
            }
            else{
                pq.push(temp/3 +1 );
            }
            k--;
        }
         return score;
    }
};