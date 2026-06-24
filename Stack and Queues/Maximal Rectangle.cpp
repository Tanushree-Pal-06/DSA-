class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
                maxi=max(maxi,(heights[ele]*(nse-pse-1)));
            }
            st.push(i);
        }


        while(!st.empty()){
            int nse=heights.size();
            int ele=st.top();
            st.pop();
            int pse=(st.empty())?-1:st.top();
            maxi=max(maxi,(heights[ele]*(nse-pse-1)));
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;;
            }
            int area=largestRectangleArea(heights);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
