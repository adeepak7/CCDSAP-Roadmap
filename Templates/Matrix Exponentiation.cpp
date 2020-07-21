#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

template<typename T>
T add(T A, T B) {
    return (A + B >= mod ? A + B - mod : A + B);
}

template<typename T>
T mul(T A, T B) {
    return (1LL * A * B % mod);
}

template<typename T>
vector<vector<T>> multiplyMatrices(vector<vector<T>> & A, vector<vector<T>> & B) {
    int a = (int)A.size(), b = (int)(A[0].size()), c = (int)(B[0].size());
    vector<vector<T>> res(a, vector<T>(c, 0));
    for(int i = 0;i < a;i ++) {
        for(int j = 0;j < c;j ++) {
            for(int k = 0;k < b;k ++) {
                res[i][j] = add<T>(res[i][j], mul<T>(A[i][k], B[k][j]));
            }
        }
    }
    return res;
}

template<typename T>
vector<vector<T>> getPowMatrices(vector<vector<T>> A, long long pow) {
    int a = (int)A.size(), b = (int)(A[0].size());
    vector<vector<T>> res(a, vector<T>(b, 0));
    for(int i = 0;i < min(a, b);i ++) {
        res[i][i] = 1;
    }
    while(pow > 0) {
        if(pow & 1) {
            res = multiplyMatrices<T>(res, A);
        }
        A = multiplyMatrices<T>(A, A);
        pow >>= 1;
    }
    return res;
}

// https://www.spoj.com/problems/MPOW/
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int T;
    cin >> T;
    while(T --) {
        int N, pow;
        cin >> N >> pow;
        vector<vector<int>> matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N;i ++) {
            for(int j = 0;j < N;j ++) {
                cin >> matrix[i][j];
                if(matrix[i][j] == mod) {
                    matrix[i][j] = 0;
                }
            }
        }
        vector<vector<int>> res = getPowMatrices<int>(matrix, pow);
        for(int i = 0;i < N;i ++) {
            for(int j = 0;j < N;j ++) {
                cout << res[i][j] << " \n"[j == N - 1];
            }
        }
    }
    
}