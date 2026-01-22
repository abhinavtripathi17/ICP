class Solution {
public:
    int countPrimes(int n) {
        vector<int>isprime(n+1 , 0);
        int cnt = 0;

        for(int i = 2 ; i <= n ; i++){
            isprime[i] = 1;
        }

        for(int i = 2 ; i*i <= n ; i++){
            if(isprime[i] == 1){
                for(int j = i*i ; j <= n; j = j+i){
                if(isprime[j] == 1){
                    isprime[j] = 0;
                }
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(isprime[i] == 1){
                cnt++;
            }
        }
        return cnt;
    }
};