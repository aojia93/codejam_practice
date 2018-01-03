#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void inputIO(ifstream &in, vector<string> &S, vector<int> &K) {
    int T;
    in >> T;
    for(int i = 0; i < T; ++i) {
        int k;
        string s;
        in >> s >> k;
        S.push_back(s);
        K.push_back(k);
    }
}

void outputIO(ofstream &out, vector<string> &results) {
    int cnt = 1;
    for(auto it = results.begin(); it != results.end(); ++cnt, ++it) {
        out << "Case #" << cnt << ": " << *it << endl;
    }
}

void flipFaces(string &curStr, size_t i, int curK) {
    for(size_t j = i; j < i + curK; ++j) {
        curStr[j] = (curStr[j] == '+') ? '-' : '+';
    }
}

string getSol(string curStr, int curK) {
    int flipCount = 0;
    for(size_t i = 0; i < curStr.size(); ++i) {
        if(curStr[i] == '-') {
            if(curStr.size() - i >= curK) {
                flipFaces(curStr, i, curK);
                ++flipCount;
            }
            else {
                return "IMPOSSIBLE";
            }
        }
    }
    return to_string(flipCount);
}

void solvePancake(vector<string> &S, vector<int> &K, vector<string> &results) {
    for(size_t i = 0; i < S.size(); ++i) {
        string curStr = S[i];
        int curK = K[i];
        string res = getSol(curStr, curK);
        results.push_back(res);
    }
}

int main() {
    // Input processing
    ifstream in("A-small-practice.in");
    vector<string> S;
    vector<int> K;
    inputIO(in, S, K);

    // Solving problem
    vector<string> results;
    solvePancake(S, K, results);

    // Output processing
    ofstream out("results.txt");
    outputIO(out, results);

    return 0;
}