class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq; 
        pq.push({a,'a'}); 
        pq.push({b,'b'}); 
        pq.push({c,'c'}); 
        string ans = ""; 
        while(pq.top().first > 0){
            auto p = pq.top(); 
            pq.pop(); 
            if(ans.size() && ans.back() == p.second){
                if(pq.top().first == 0 ){
                    pq.push(p); 
                    break ;
                }
                auto temp = p; 
                p = pq.top(); 
                pq.pop(); 
                pq.push(temp); 
            }
            ans += p.second; 
            p.first -= 1;  
            pq.push(p); 
        }
        while(pq.size() && pq.top().first){
            auto p = pq.top(); 
            pq.pop(); 
            string s = ""; 
            for(char &ch : ans){
                s += ch; 
                if(p.first && ch == p.second){
                    s += ch; 
                    p.first -= 1; 
                }
            }
            ans = s; 
        }
        return ans ; 
    }
};