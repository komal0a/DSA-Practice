class Solution {
public:
    bool checkIthBit(int n, int i) {
        // Your code goes here
        int mask=1<<(i-1);
        return (n & mask) !=0;
    }
};