#include <vector>
#include <iostream>
using namespace std;

vector<int> findSpiralOrdering(vector< vector<int> > &A) {
  int r = 0, c = 0, curr_dir = 0, n = A.size();
  int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
  vector<int> res;

  for (int i = 0; i < n*n; i++) {
    res.emplace_back(A[r][c]);
    A[r][c] = 0;
    if (r + directions[curr_dir][0] >= n || c + directions[curr_dir][1] >= n
        || r + directions[curr_dir][0] < 0 || c + directions[curr_dir][1] < 0
        || A[r + directions[curr_dir][0]][ c + directions[curr_dir][1]] == 0) { // if next one is 0 or oob, shift direction
      curr_dir = (curr_dir + 1) % 4;

    } 
    r += directions[curr_dir][0];
    c += directions[curr_dir][1];   
  }
  return res;
}

vector< vector<int> > getNxNMatrix(int n) {
  vector< vector<int> > res;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < n; j++) {
      row.emplace_back(counter);
      counter++;
    }
    res.emplace_back(row);
  }
  return res;
}

void print_matrix(vector< vector<int> > A) {
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      cout << A[i][j] << " ";
    }
    cout << endl; 
  }
}

void print_array(vector<int> A) {
  for (int j = 0; j < A.size(); j++) {
    cout << A[j] << " ";
  }
}

int main() {
  print_matrix(getNxNMatrix(4)); 
  vector<vector<int>> A = getNxNMatrix(4);
  print_array(findSpiralOrdering(A));
}