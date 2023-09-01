#include <cmath>

using namespace std;

struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_right;
};

bool isSubTree(BinaryTreeNode *main, BinaryTreeNode *sub)
{
    if(sub == nullptr)
    {
        return true;
    }

    if(main == nullptr)
    {
        return false;
    }

    if(abs(main->m_dbValue - sub->m_dbValue) < 10e-9)
    {
        return isSubTree(main->m_pLeft, sub->m_pLeft) &&
                isSubTree(main->m_right, sub->m_right);
    }

    return false;
}

bool hasSubTree(BinaryTreeNode *main, BinaryTreeNode *sub)
{
    if(main == nullptr || sub == nullptr)
    {
        return false;
    }

    if(isSubTree(main, sub))
    {
        return true;
    }
    else if(hasSubTree(main->m_pLeft, sub))
    {
        return true;
    }
    else if(hasSubTree(main->m_right, sub))
    {
        return true;
    }

    return false;
}
