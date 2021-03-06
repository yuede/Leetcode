class Solution {
public:
    bool Next_Permutation(vector<int> &nums) {
        if (nums.empty() || nums.size() <= 1) return false;
        int pa = nums.size() - 1, pb = pa - 1, pc = pa;
        while (pb >= 0 && nums[pb] >= nums[pa]) {
            pb --;
            pa --;
        }
        if (pb < 0) return false;
        while (pc >= 0 && nums[pc] <= nums[pb]) {
            pc --;
        }
        swap(nums[pb], nums[pc]);
        int left = pa, right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left ++;
            right --;
        }
        return true;
    }
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        res.push_back(nums);
        while (Next_Permutation(nums)) {
            res.push_back(nums);
        }
        return res;
    }
};