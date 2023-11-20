// https://school.programmers.co.kr/learn/courses/30/lessons/42892

#include <string>
#include <vector>

#include <algorithm>

using namespace std;

struct TreeNode {
    int id;
    int x, y;
    int left;
    int right;
};

struct Comp {
    bool
    operator()(TreeNode const& a, TreeNode const& b) const noexcept {
        return a.y > b.y;
    }
};

void
makeTree(int rootId, int childId, vector<TreeNode>& nodes) {
    auto& rootNode = nodes[rootId];
    auto& childNode = nodes[childId];

    if (rootNode.x > childNode.x) {
        if (rootNode.left == -1) {
            rootNode.left = childId;
        } else {
            makeTree(rootNode.left, childId, nodes);
        }
    } else {
        if (rootNode.right == -1) {
            rootNode.right = childId;
        } else {
            makeTree(rootNode.right, childId, nodes);
        }
    }
}

void
preOrder(int id, vector<TreeNode> const& nodes, vector<int>& log) {
    TreeNode const& root = nodes[id];

    log.push_back(root.id + 1);

    if (root.left != -1) {
        preOrder(root.left, nodes, log);
    }
    if (root.right != -1) {
        preOrder(root.right, nodes, log);
    }
}

void
postOrder(int id, vector<TreeNode> const& nodes, vector<int>& log) {
    TreeNode const& root = nodes[id];

    if (root.left != -1) {
        postOrder(root.left, nodes, log);
    }
    if (root.right != -1) {
        postOrder(root.right, nodes, log);
    }
    log.push_back(root.id + 1);
}

vector<vector<int>>
solution(vector<vector<int>> nodeinfo) {
    vector<TreeNode> nodes;
    const int size = nodeinfo.size();

    for (int index = 0; index < size; ++index) {
        nodes.push_back(
            {.id = index,
             .x = nodeinfo[index][0],
             .y = nodeinfo[index][1],
             .left = -1,
             .right = -1}
        );
    }

    sort(nodes.begin(), nodes.end(), Comp());

    for (int index = 1; index < nodes.size(); ++index) {
        makeTree(0, index, nodes);
    }

    vector<vector<int>> answer(2);

    preOrder(0, nodes, answer[0]);
    postOrder(0, nodes, answer[1]);
    return answer;
}
