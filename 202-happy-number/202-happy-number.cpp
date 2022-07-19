class Solution {
public:
    
    int digitSquareSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int t= n%10;
            sum+=t*t;
            n=n/10;
        }
            return sum;
    }
    bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
        if(fast==1)
        {
            return true;
        }
    } while(slow != fast);
    return 0;
    }
};