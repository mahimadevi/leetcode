class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> result;

        while (i < n1 || j < n2) {
            if (i < n1 && (j >= n2 || nums1[i][0] < nums2[j][0])) {
                result.push_back(nums1[i]); // Add from nums1
                i++;
            } 
            else if (j < n2 && (i >= n1 || nums1[i][0] > nums2[j][0])) {
                result.push_back(nums2[j]); // Add from nums2
                j++;
            } 
            else {
                // Merge common IDs
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        return result;
    }
};