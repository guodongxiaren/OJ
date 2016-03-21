class Matrix {
  public:
    vector<vector<int>> a;
};
Matrix operator+ (const Matrix& lm, const Matrix& rm) {
    Matrix res;
    int size = lm.a.size();
    int ssize = lm.a[0].size();
    res.a.reserve(size);
    vector<int> v;
    
    for (int i = 0; i < size; i++) {
        vector<int> b;
        for (int j = 0; j < ssize; j++) {
            b.push_back(lm.a[i][j] + rm.a[i][j]);
        }
        res.a.push_back(b);
    }
    return res;
}