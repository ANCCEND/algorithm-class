#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string number;
    int k;
    if (!(cin >> number >> k)) return 0;

    stack<char> s;
    int count = 0;

    for (char c : number) {
        while (count < k && !s.empty() && s.top() > c) {
            s.pop();
            count++;
        }
        s.push(c);
    }

    // 如果删够了 k 个还没结束
    while (count < k && !s.empty()) {
        s.pop();
        count++;
    }

    string res = "";
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    // 反转字符串
    reverse(res.begin(), res.end());

    // 处理前导零
    string final_res = "";
    bool is_leading_zero = true;
    for (char c : res) {
        if (is_leading_zero && c == '0') continue;
        is_leading_zero = false;
        final_res += c;
    }

    // 输出结果
    if (final_res == "") cout << "0" << endl;
    else cout << final_res << endl;

    return 0;
}