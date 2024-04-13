/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {


        // Approrach 1 - level order traversal

        if( p == nullptr && q == nullptr)
            return true;

        if( p == nullptr || q == nullptr)
            return false;

        queue <TreeNode*> q1;        
        queue <TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while( !q1.empty() && !q2.empty())
        {
            TreeNode* front1 = q1.front();
            q1.pop();

            TreeNode* front2 = q2.front();
            q2.pop();

            if(front1->val != front2->val )
                return false;

            if (
               ( front1->left == nullptr && front2->left != nullptr ) ||
            ( front1->left != nullptr && front2->left == nullptr ))
                return false;

             if (
               ( front1->right == nullptr && front2->right != nullptr ) ||
            ( front1->right != nullptr && front2->right == nullptr ))
                return false;


            if( front1->left != nullptr) 
                q1.push(front1->left);
            if( front1->right != nullptr) 
                q1.push(front1->right);

            if( front2->left != nullptr) 
                q2.push(front2->left);
             if( front2->right != nullptr) 
                q2.push(front2->right);

        }

        return true;

        // Approcch - 2

        // if both nodes nullptr return true
        if(p == nullptr && q == nullptr)
            return true;
        
        // check if any of the node is null
        if(p == nullptr || q == nullptr)
            return false;
        
        return (
            p->val == q->val 
            &&
            isSameTree(p->left, q->left)
            &&
            isSameTree(p->right, q->right)
        );
    }
};
