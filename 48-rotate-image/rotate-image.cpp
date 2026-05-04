class Solution {
public:
    
    void reversemat(vector<vector<int>>& matrix,int n)   {
        for(int i = 0;i<n;i++){
            for(int j = 0; j < n / 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    } 
    void transpose (vector<vector<int>>& matrix,int n){
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
        
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        //logic - transpose and reveerse
        transpose(matrix,n);
        reversemat(matrix,n);
        
        

    }
};