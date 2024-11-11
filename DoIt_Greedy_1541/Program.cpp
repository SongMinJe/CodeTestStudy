#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;



static vector<string> split(string input, char delimiter) {
    istringstream ss(input);
    string stringBuffer;
    vector<string> x;
    x.clear();

    while (getline(ss, stringBuffer, delimiter)) {
        x.push_back(stringBuffer);
    }
    return x;
}
static int sum(string str) {
    int result = 0;
    vector<string> temp = split(str, '+');

    for (int i = 0; i < temp.size(); i++) {
        result += stoi(temp[i]);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    vector<string> str = split(N, '-');
    int answer = sum(str[0]);

    for (int i = 1; i < str.size(); i++) {
        int tmp = sum(str[i]);
        answer -= tmp;
    }
    cout << answer << "\n";
}