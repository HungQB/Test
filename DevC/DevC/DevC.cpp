// DevC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Problem 1
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

//Problem 2
int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        bool halvesAreEven = (right - mid) % 2 == 0;
        if (nums[mid] == nums[mid + 1]) {
            if (halvesAreEven) {
                left = mid + 2;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid] == nums[mid - 1]) {
            if (halvesAreEven) {
                right = mid - 2;
            } else {
                left = mid + 1;
            }
        } else {
            return nums[mid];
        }
    }
    return nums[left];
}
//Problem 3
int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }
    else if (divisor == 1) {
        return dividend;
    }
    else if (divisor == -1) {
        return -dividend;
    }

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = dividend;
    long long dvs = divisor;
    if(dvd < 0)
        dvd *= -1;
    if(dvs < 0)
        dvs *= -1;
    long res = 0;

    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        res += multiple;
    }
    res *= sign;

    if (res > INT_MAX) {
        return INT_MAX;
    }
    if (res < INT_MIN) {
        return INT_MIN;
    }
    return res;
}

int main()
{
    vector<int> my_vector = { 1,1,2,2,3,4,4,5,5 };
    cout << reverse(INT_MAX)<<endl;
    cout << singleNonDuplicate(my_vector)<<endl;
    cout << divide(INT_MIN, INT_MIN);
    return 0;
}
