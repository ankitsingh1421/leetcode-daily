class Solution {
public:
    vector<TreeNode*> build(int s,int e) {
	    vector<TreeNode*> ans;
      if(s>e) {
	    	ans.push_back(NULL);
        return ans;
      }
	    for(int i=s;i<=e;i++) {
	    	vector<TreeNode*> left=build(s,i-1),right=build(i+1,e);   
	    	for(int j=0;j<left.size();j++){
	    		for(int k=0;k<right.size();k++) {
	    			TreeNode* root = new TreeNode(i);
	    			root->left = left[j];
            root->right = right[k];  
	    			ans.push_back(root);    
	    		}
	    	}
      }
			return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
    	return build(1, n);
    }
};