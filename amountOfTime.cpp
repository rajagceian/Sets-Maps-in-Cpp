class Solution {
public:
    void preorder(TreeNode* root, TreeNode*& newRoot, int start,
                  unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!root)
            return;
        if (root->val == start)
            newRoot = root;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;
        preorder(root->left, newRoot, start, mp);
        preorder(root->right, newRoot, start, mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        int maxLevel = 0;
        unordered_map<TreeNode*, TreeNode*> mp; // {node,parent node}
        TreeNode* newRoot;
        preorder(root, newRoot, start, mp);

        unordered_set<TreeNode*> isInfected;
        isInfected.insert(newRoot);
        queue<pair<TreeNode*, int>> q;
        q.push({newRoot, 0});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                maxLevel = max(maxLevel, p.second);
                if (mp.find(p.first) != mp.end() &&
                    isInfected.find(mp[p.first]) == isInfected.end()) {
                    isInfected.insert(mp[p.first]);
                    q.push({mp[p.first], p.second + 1});
                }
                if (p.first->left &&
                    isInfected.find(p.first->left) == isInfected.end()) {
                    isInfected.insert(p.first->left);
                    q.push({p.first->left, p.second + 1});
                }
                if (p.first->right &&
                    isInfected.find(p.first->right) == isInfected.end()) {
                    isInfected.insert(p.first->right);
                    q.push({p.first->right, p.second + 1});
                }
            }
        }
        return maxLevel;
    }
};
