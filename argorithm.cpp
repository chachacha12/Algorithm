#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>  // <-- 이 줄을 추가합니다
using namespace std;

// 주어진 문자열 s를 base 진법으로 해석하여 정수로 반환.
// 만약 s에 base 이상의 숫자 문자가 있으면 -1 반환.
int parseInBase(const string &s, int base) {
    int v = 0;
    for (char c : s) {
        if (c < '0' || c > '9') return -1;
        int d = c - '0';
        if (d >= base) return -1;
        v = v * base + d;
    }
    return v;
}

// 정수 v를 base 진법 문자열로 변환
string toBase(int v, int base) {
    if (v == 0) return "0";
    string s;
    while (v > 0) {
        int d = v % base;
        s.push_back(char('0' + d));
        v /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<string> solution(vector<string> expressions) {
    int n = expressions.size();
    struct Expr { string A, op, B, C; bool unknown; };
    vector<Expr> exprs;
    exprs.reserve(n);
    // 파싱
    for (auto &line : expressions) {
        istringstream iss(line);
        Expr e;
        iss >> e.A >> e.op >> e.B;
        string eq;
        iss >> eq >> e.C;
        e.unknown = (e.C == "X");
        exprs.push_back(e);
    }
    
    // 가능한 진법 후보 수집
    vector<int> bases;
    for (int b = 2; b <= 9; b++) {
        bool ok = true;
        for (auto &e : exprs) {
            int va = parseInBase(e.A, b);
            int vb = parseInBase(e.B, b);
            if (va < 0 || vb < 0) { ok = false; break; }
            if (e.unknown) {
                if (e.op == "-" && va < vb) { ok = false; break; }
            } else {
                int vc = parseInBase(e.C, b);
                if (vc < 0) { ok = false; break; }
                int vr = (e.op == "+" ? va + vb : va - vb);
                if (vr != vc) { ok = false; break; }
            }
        }
        if (ok) bases.push_back(b);
    }
    
    // 결과 채우기: unknown인 식만, 순서대로
    vector<string> answer;
    for (auto &e : exprs) {
        if (!e.unknown) continue;
        set<string> results;
        for (int b : bases) {
            int va = parseInBase(e.A, b);
            int vb = parseInBase(e.B, b);
            int vr = (e.op == "+" ? va + vb : va - vb);
            results.insert(toBase(vr, b));
        }
        string fill = (results.size() == 1 ? *results.begin() : "?");
        // 원래 식에서 'X' 대신 fill로 치환
        // "A op B = C"
        answer.push_back(e.A + " " + e.op + " " + e.B + " = " + fill);
    }
    return answer;
}
