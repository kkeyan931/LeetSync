class Solution {
public:
    
    struct trieNode{
      
        trieNode *child[26]={nullptr};
        int wordEnd=0;
        string word="";
        
        trieNode(){}
    };
    
    trieNode* root = new trieNode();
    
    void insert(string &str){
        
        auto ptr = root;
        
        for(auto &ch : str){
            
            if(ptr->child[ch-'a']==nullptr){
                ptr->child[ch-'a'] = new trieNode();
            }
            ptr=ptr->child[ch-'a'];
        }
        
        ptr->wordEnd+=1;
        ptr->word = str;
    }
    

    void dfs(vector<vector<char>> &board,vector<string> &result,
             trieNode *curr,int row,int col,int n,int m){
        
        
        int index = board[row][col]-'a';
        
        if(board[row][col]=='$' || curr->child[index]==nullptr ) return;
        
        curr=curr->child[index];
        
        if(curr->wordEnd>0){
            result.push_back(curr->word);
            curr->wordEnd--;
        }
        
        char ch = board[row][col];
        
        board[row][col]='$';
        
        //up -1 , 0
        if(row>0) dfs(board,result,curr,row-1,col,n,m);
        
        //down 1,0
        if(row<n-1) dfs(board,result,curr,row+1,col,n,m);
        
        //right 0,-1
        if(col<m-1) dfs(board,result,curr,row,col+1,n,m);
        
        //left 0 +1
        if(col>0) dfs(board,result,curr,row,col-1,n,m);
        
        board[row][col]=ch;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     
        vector<string> result;
        int n = board.size();
        int m = board[0].size();
        
        for(auto &word : words){
            insert(word);
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dfs(board,result,root,i,j,n,m);
            }
        }
        
        return result;
        
    }
};