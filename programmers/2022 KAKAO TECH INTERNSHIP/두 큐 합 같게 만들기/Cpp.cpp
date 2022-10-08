#include <string>
#include <vector>

using namespace std;

long long sum(vector<int> &v) {
    long long sumOfElems = 0;

    for (auto i : v) {
        sumOfElems += i;
    }

    return sumOfElems;
}

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> q;
    q.reserve(queue1.size() + queue2.size());
    q.insert(q.end(), queue1.begin(), queue1.end());
    q.insert(q.end(), queue2.begin(), queue2.end());

    const size_t length    = q.size();
    const long long target = sum(q) / 2;

    long long currSum = sum(queue1);
    size_t left = 0, right = queue1.size();

    int count = 0;
    for (; left < length ; ++count) {
        if (currSum == target) {
            return count;
        }

        if (currSum < target) {
            currSum += q[right++];
        } else {
            currSum -= q[left++];
        }

        if (right >= length) {
            right = 0;
        }
    }

    return -1;
}
