//----------------------------- Method - 1 ----------------------------
class Solution {
public:
    int maxDepth = 0;
    unordered_map<int,int> mp; //{node val,depth}
    void depth(TreeNode* root,int d){
        if(!root) return;
        mp[root->val] = d;
        maxDepth = max(maxDepth,d);
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
    TreeNode* LCA(TreeNode* root,int d,int tarDepth){
        if(!root || d==tarDepth) return root;
        TreeNode* LST = LCA(root->left,d+1,tarDepth);
        TreeNode* RST = LCA(root->right,d+1,tarDepth);

        if(!LST) return RST;
        else if(!RST) return LST;

        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return LCA(root,0,maxDepth);
    }
};

//------------------------- method-2 --------------------------------
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first == right.first) {
            return {left.first + 1, root};
        } else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
