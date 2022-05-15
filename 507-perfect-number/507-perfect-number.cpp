class Solution {
public:
    long perfect(int p){
        // of course I didnt know this formula before, but I promise I'll remember it
        // for the rest of my life
        long long o{1};
        long long o2{1};
        return (o << (p-1)) * ((o2 << p) - 1);
    }
    bool checkPerfectNumber(int num) {
        int primes[]{2,3,5,7,13,17,19,31};
        
        for(int p : primes){
           if(num == perfect(p)) return true;
        }
        return false;
    }
};