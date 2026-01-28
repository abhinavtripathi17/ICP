class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int>q;

        int time = 0;

        for(int i = 0 ; i < n ; i++){
            q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            tickets[front]--;
            time++;
            
            if(front == k && tickets[front] == 0) return time;
            else if(tickets[front] != 0) q.push(front);
        }
        return time;
    }
};