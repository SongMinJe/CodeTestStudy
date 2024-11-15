#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

static vector<string> split(string value, char std) {
    string tmp;
    stringstream ss(value);
    vector<string> v;
    v.clear();
    while (getline(ss, tmp, std)) {
        v.push_back(tmp);
    }
    return v;
}

static int sum(string s) {
    vector<string> str = split(s, '+');
    int n = 0;
    for (int i = 0; i < str.size(); i++) {
        n += stoi(str[i]);
    }
    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    string N;
    cin >> N;

    vector<string> str = split(N, '-');
    for (int i = 0; i < str.size(); i++) {
        int tmp = sum(str[i]);
        if (i == 0) {
            answer += tmp;
        }
        else {
            answer -= tmp;
        }
    }
    cout << answer << "\n";
}