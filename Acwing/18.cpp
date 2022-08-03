//https://www.acwing.com/problem/content/23/
//输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> myPreorder;vector<int> myInorder;
    int n;
//递归实现
//通过前序找到根.在通过中序找到左右子树,核心在于无论是那种遍历,左右子树个数是相等的
    TreeNode* rebuildTree(int p1,int p2,int i1,int i2){
        if(p1>p2)return NULL;
        auto root=new TreeNode(myPreorder[p1]);//传入前序节点 确定根节点
        //找到中序遍历里面根节点的位置pos
        int pos=-1;
        for(int i=i1;i<=i2;i++)
            if(myPreorder[p1]==myInorder[i])pos=i;
        //坐标判定 x-(p1+1)+1=pos-1-i1+1 --> x=p1+pos-i1
        root->left=rebuildTree(p1+1,p1+pos-i1,i1,pos-1);
        root->right=rebuildTree(p1+pos-i1+1,p2,pos+1,i2);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        myPreorder=preorder;myInorder=inorder;//类似全局变量 方便递归
        n=preorder.size();
        return rebuildTree(0,n-1,0,n-1);
    }
};