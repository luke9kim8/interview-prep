bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
    vector<int> numArr = {0,0,0};
    map<char, int> numMap;
    for (int i = 0; i < solution.size(); i++) {
        numMap.insert(pair<char, int> (solution[i][0], solution[i][1] - '0'));
    }
    for (int n = 0; n < crypt.size(); n++) {
        int base = 1;
        for (int i = crypt[n].size() - 1; i >= 0; i--) {
            if (i == 0 && !numMap[crypt[n][i]] && crypt[n].size() != 1) {
                return false;
            }
            numArr[n] += base * numMap[crypt[n][i]];
            base *= 10;
        }
    }
    return numArr[0] + numArr[1] == numArr[2];
}

