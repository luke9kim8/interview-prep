class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        uint64_t length = bits.size();
        
        while (i < length) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                if (i == length - 1) {
                    return true;
                } else {
                    i += 1;
                }
            }
        }
        return false;
    }
};







