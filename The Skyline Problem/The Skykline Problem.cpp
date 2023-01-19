class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;
        multiset<int> tempStack{0};

        for(auto b: buildings)
        {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());
        
        int ongoing = 0;

        for(int i = 0; i < points.size(); i++)
        {
            int curPoint = points[i].first;
            int curHeight = points[i].second;

            if(curHeight < 0)
            {
                tempStack.insert(-curHeight);
            }
            else
            {
                tempStack.erase(tempStack.find(curHeight));
            }

            int top = *tempStack.rbegin();

            if(ongoing != top)
            {
                ongoing = top;
                ans.push_back({curPoint, ongoing});
            }
        }

        return ans;
    }
};