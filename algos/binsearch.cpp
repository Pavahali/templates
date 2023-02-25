// https://en.wikipedia.org/wiki/Binary_search_algorithm

#define ARRAY_SIZE 1000000
int array[ARRAY_SIZE];

int binary_search(int l, int r, int x) {
    int m;
    while (l < r) {
        m = (l+r)/2;
        if (array[m] == x) return m;
        else if (array[m] < x) l = m+1;
        else r = m-1;
    }
    return -1;
}

int lower_bound(int l, int r, int x) {
    int m;
    while (l != r) {
        m = (l+r)/2;
        if (array[m] < x) l = m+1;
        else r = m;
    }
    return r;
}

int upper_bound(int l, int r, int x) {
    int m;
    while (l != r) {
        m = (l+r)/2;
        if (array[m] <= x) l = m+1;
        else r = m;
    }
    return r;
}