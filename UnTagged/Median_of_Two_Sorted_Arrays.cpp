class Solution {
public:
    double findKthNumberSortedArrays(int a[], int m, int b[], int n, int k) {
        if (m > n) {
            return this->findKthNumberSortedArrays(b, n, a, m, k);
        }
        if (m == 0) {
            return b[k - 1];
        }
        if (n == 0) {
            return a[k - 1];
        }
        if (k == 1) {
            return min (a[0], b[0]);
        }
        int lena = min (k / 2, m), lenb = k - lena;
        if (a[lena - 1] < b[lenb - 1]) {
            return this->findKthNumberSortedArrays(a + lena, m - lena, b, n, k - lena);
        }
        if (a[lena - 1] > b[lenb - 1]) {
            return this->findKthNumberSortedArrays(a, m, b + lenb, n - lenb, k - lenb);
        }
        return a[lena - 1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
        if ((m + n) % 2 == 1) {
            return this->findKthNumberSortedArrays(A, m, B, n, k + 1);
        }
        return (this->findKthNumberSortedArrays(A, m, B, n, k) + this->findKthNumberSortedArrays(A, m, B, n, k + 1)) / 2;
    }
};