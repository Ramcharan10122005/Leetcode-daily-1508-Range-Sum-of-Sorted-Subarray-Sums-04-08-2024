int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int mod = 1000000007;
    int* temp = (int*)malloc(n * (n + 1) / 2 * sizeof(int)); 
    int index = 0;
    for (int i = 0; i < n; i++) {
        int cur_sum = 0;
        for (int j = i; j < n; j++) {
            cur_sum += nums[j];
            temp[index++] = cur_sum;
        }
    }
    qsort(temp, index, sizeof(int), compare);

    long long ans = 0;
    for (int i = left - 1; i <= right - 1; i++) {
        ans = (ans + temp[i]) % mod;
    }

    free(temp); 
    return (int)ans;
}
