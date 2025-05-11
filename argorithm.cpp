#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Union-Find  구현
struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void unionn(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            parent[b] = a;
        }
    }
};

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    int N = nodes.size();
    
    // 노드 번호 -> index mapping (nodes 배열은 중복없음)
    unordered_map<int, int> nodeToIdx;
    for (int i = 0; i < N; i++){
        nodeToIdx[nodes[i]] = i;
    }
    
    // 각 노드의 degree (무방향 그래프상의 인접 개수)
    vector<int> degree(N, 0);
    
    // Union-Find 초기화 및 간선 처리
    UnionFind uf(N);
    for (auto &e : edges) {
        int a = e[0], b = e[1];
        int idxA = nodeToIdx[a], idxB = nodeToIdx[b];
        degree[idxA]++;
        degree[idxB]++;
        uf.unionn(idxA, idxB);
    }
    
    // 각 컴포넌트별로 (대표자 기준) 노드들의 정보를를 모읍니다.
    // 각 노드의 "후보" 여부는 입력 노드번호와 degree에 따라 결정됩니다.

    vector<vector<int>> compNodes(N); 
    for (int i = 0; i < N; i++){
        int rep = uf.find(i);
        compNodes[rep].push_back(i);
    }
    
    int normalCount = 0;
    int reverseCount = 0;
    // 각 컴포넌트(트리)를 검사
    for (int rep = 0; rep < N; rep++){
        if (compNodes[rep].empty()) continue;
        int compSize = compNodes[rep].size();
        int cntNormCandidate = 0;   
        int cntRevCandidate  = 0;   
        for (int idx : compNodes[rep]){
            int dMod = degree[idx] & 1;  
            int labelMod = (nodes[idx] & 1);  
            if(dMod == labelMod)
                cntNormCandidate++;
            else  
                cntRevCandidate++;
        }
        // 각 트리에서 루트를 어떻게 정해도 non-root들은 강제 조건을 가지므로,
        // 트리가 정상(홀짝 트리)이 될 수 있으려면 후보(root) 조건을 만족하는 노드가 딱 하나 있어야 함.
        if(compSize == 1){
            // 단일 노드: normal 트리는 degree==node mod 2, 역홀짝 트리는 degree == 1 - (node mod 2)
            if(cntNormCandidate == 1) normalCount++; 
            if(cntRevCandidate == 1)  reverseCount++;
        }
        else {
            if(cntNormCandidate == 1) normalCount++;
            if(cntRevCandidate == 1)  reverseCount++;
        }
    }
    
    return {normalCount, reverseCount};
}
