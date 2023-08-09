#include <vector>
#include <algorithm>

using namespace std;

struct BinaryTreeNode
{
    int key;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode *construct_core(vector<int>::iterator start_pre, vector<int>::iterator end_pre,
                               vector<int>::iterator start_in, vector<int>::iterator end_in)
{
    int root = *start_pre;

    BinaryTreeNode *node = new BinaryTreeNode;
    node->key = root;
    node->left = nullptr;
    node->right = nullptr;

    if(start_pre == end_pre)
    {
        return node;
    }
    
    /* 中序遍历中的根，注意查找区间 */
    auto root_in = find(start_in, end_in+1, root);
    /* 存在右子树 */
    if(root_in != end_in)
    {
        node->right = construct_core(start_pre+1, end_pre, root_in+1, end_in);
    }

    /* 存在左子树 */
    if(root_in != start_in)
    {
        node->left = construct_core(start_in+1, end_in, start_in, root_in-1);
    }

    return node;
}

// 根据前序遍历列表和中序遍历列表构建二叉树
BinaryTreeNode *construct(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.size() == 0 || inorder.size() == 0)
    {
        return nullptr;
    }

    return construct_core(preorder.begin(), preorder.end()--, inorder.begin(), inorder.end()--);
}