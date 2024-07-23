//O(nlogn)
//O(N)
class KthLargest {
public:
    int K = 0;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        v = nums;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(rbegin(v), rend(v));

        return v[K-1];

    }
};
//Complexity
// Time complexity: O(n.log(k))
// Space complexity: O(n)
// doubt:if let say i have nums array 4,5,8,2,10,11,12  and it is asking 3rd largest which is 10 but according to the code answer is 4
//  ans: The observed discrepancy arises because the current implementation is designed to maintain the Kth largest element after each insertion. However, if the initial set of numbers is not sufficient to establish a proper baseline for the Kth largest element, the code might produce an unexpected result.
class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto i : nums) {
            pq.push(i);

            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > K)
            pq.pop();

        return pq.top();
    }
};
