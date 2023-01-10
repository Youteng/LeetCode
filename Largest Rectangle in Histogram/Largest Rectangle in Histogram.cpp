class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        int maxHist = 0;

        left[0] = -1;
        right[right.size() - 1] = heights.size();
        
        //Scan from left
        for(int i = 1; i < heights.size(); i++)
        {
            int temp = i - 1;
            while(temp >= 0 && heights[temp] >= heights[i])
            {
                temp = left[temp];
            }

            left[i] = temp;
        }
        
        //Scan from right
        for(int i = heights.size() - 2; i >= 0; i--)
        {
            int temp = i + 1;
            while(temp < heights.size() && heights[temp] >= heights[i])
            {
                temp = right[temp];
            }

            right[i] = temp;
        }

        //Calcuate the maxmiun area
        for(int i = 0; i < heights.size(); i++)
        {
            maxHist = max(maxHist, heights[i] * (right[i] - left[i] - 1));
        }

        return maxHist;
    }