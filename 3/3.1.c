int binsearch (int x, int v[], int n);

int binsearch (int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] < n) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return n == v[low] ? low : -1;
}