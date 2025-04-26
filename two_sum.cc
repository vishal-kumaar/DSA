#include <iostream>
#include <vector>

using namespace std;

vector <int> twoSum(vector <int> nums, int target){
    int li = 0, ri = nums.size() - 1;
    
    while (li < ri){
        if (nums[li] + nums[ri] == target){
            return {li, ri};
        }

        if (nums[ri] >= 0){
            if (nums[ri] >= target){
                ri--;
            }
            else{
                li++;
            }
        }
        else{
            if (nums[ri] <= target){
                ri--;
            }
            else{
                li++;
            }
        }
    }

    return {-1, -1};
}

int main(){
    vector <int> nums = {2, 7, 11, 15};
    // vector <int> nums = {3, 2, 4};
    // vector <int> nums = {3, 3};
    // vector <int> nums = {-1, -2, -3, -4, -5};
    // vector <int> nums = {-10, -1, -18, -19};
    
    vector <int> result = twoSum(nums, 9);

    cout << result.front() << ", " << result.back() << endl;

    return 0;
}