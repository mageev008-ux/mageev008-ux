#include <stdio.h>

int calculator(float a, float b, char r) {
  int res;
  switch (r) {
  case '+':
    res = a + b;
    break;
  case '-':
    res = a - b;
    break;
  case '*':
    res = a * b;
    break;
  case '/':
    res = a / b;
    break;
  };
  return res;
}

void vstav_sort(int a, int arr[]) {
  int s = 0;
  for (int x = 1; x < a; x++) {
    for (int i = x; i > 0; i--) {
      while (arr[i] < arr[i - 1]) {
        s = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = s;
      }
    }
  }
}

void swap(int arr[], int a, int b) {
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

int partition(int arr[], int x, int y) {
  if (x < y) {
    int randic = x + rand() % (y - x + 1);
    swap(arr, randic, y);
    int g = x - 1;
    int s = arr[y];
    for (int j = x; j < y; j++) {
      if (arr[j] < s) {
        g++;
        swap(arr, g, j);
      }
    }
    swap(arr, g + 1, y);
    return g + 1;
  }
  return x;
}

void quick_sort(int arr[], int x, int y) {
  if (x < y) {
    int pivo = partition(arr, x, y);
    quick_sort(arr, x, pivo - 1);
    quick_sort(arr, pivo + 1, y);
  }
}

void merge(int arr[], int l, int s, int r) {
  int n1 = s - l + 1;
  int n2 = r - s;
  int L[n1];
  int R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[i + l];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[s + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2)
    if (L[i] < R[j]) {
      arr[k] = L[i];
      k++;
      i++;
    } else {
      arr[k] = R[j];
      k++;
      j++;
    }
  while (i < n1) {
    arr[k] = L[i];
    k++;
    i++;
  }
  while (j < n2) {
    arr[k] = R[j];
    k++;
    j++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r)
    return;
  int s = (l + r) / 2;
  mergeSort(arr, l, s);
  mergeSort(arr, s + 1, r);
  merge(arr, l, s, r);
}

void merge2(int arr[][3], int l, int s, int r) {
  int n1 = s - l + 1;
  int n2 = r - s;
  int L[n1][3];
  int R[n2][3];
  for (int i = 0; i < n1; i++) {
    L[i][0] = arr[i + l][0];
    L[i][1] = arr[i + l][1];
    L[i][2] = arr[i + l][2];
  }
  for (int j = 0; j < n2; j++) {
    R[j][0] = arr[s + 1 + j][0];
    R[j][1] = arr[s + 1 + j][1];
    R[j][2] = arr[s + 1 + j][2];
  }
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2)
    if (L[i][0] < R[j][0] || (L[i][0] == R[j][0] && L[i][1] <= R[j][1])) {
      arr[k][0] = L[i][0];
      arr[k][1] = L[i][1];
      arr[k][2] = L[i][2];
      k++;
      i++;
    } else {
      arr[k][0] = R[j][0];
      arr[k][1] = R[j][1];
      arr[k][2] = R[j][2];
      k++;
      j++;
    }
  while (i < n1) {
    arr[k][0] = L[i][0];
    arr[k][1] = L[i][1];
    arr[k][2] = L[i][2];
    k++;
    i++;
  }
  while (j < n2) {
    arr[k][0] = R[j][0];
    arr[k][1] = R[j][1];
    arr[k][2] = R[j][2];
    k++;
    j++;
  }
}

void mergeSort2(int arr[][3], int l, int r) {
  if (l >= r)
    return;
  int s = (l + r) / 2;
  mergeSort2(arr, l, s);
  mergeSort2(arr, s + 1, r);
  merge2(arr, l, s, r);
}

// int main() {
//   int a;
//   scanf("%d", &a);
//   int arr[a][3];
//   for (int x = 0; x < a; x++) {
//     scanf("%d %d", &arr[x][0], &arr[x][1]);
//     arr[x][2] = x + 1;
//   }
//   mergeSort(arr, 0, a - 1);

//   for (int x = 0; x < a; x++) {
//     printf("%d ", arr[x][2]);
//   }
//   return 0;
// }

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000000
uint32_t arr[MAXN];
uint32_t cur = 0;
uint32_t nextRand24(uint32_t a, uint32_t b) {
  cur = cur * a + b;
  return cur >> 8; // берём старшие 24 бита (сдвиг вправо на 8)
}

long long merge(uint32_t arr[], int l, int s, int r) {
  int n1 = s - l + 1;
  int n2 = r - s;
  long long c = 0;
  uint32_t L[n1];
  uint32_t R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[i + l];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[s + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
      c = c + n1 - i;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    k++;
    i++;
  }
  while (j < n2) {
    arr[k] = R[j];
    k++;
    j++;
  }
  return c;
}

long long mergeSort(uint32_t arr[], int l, int r) {
  long long c = 0;
  if (l >= r) {
    return 0;
  }
  if (l < r) {
    int s = (l + r) / 2;
    c += mergeSort(arr, l, s);
    c += mergeSort(arr, s + 1, r);
    c += merge(arr, l, s, r);
  }
  return c;
}

int main1(void) {
  uint32_t n, m, a, b;
  if (scanf("%u %u %u %u", &n, &m, &a, &b) != 4) {
    return 1;
  }
  for (uint32_t i = 0; i < n; i++) {
    uint32_t x = nextRand24(a, b) % m;
    arr[i] = x;
  }
  long long t = mergeSort(arr, 0, n - 1);
  printf("%lld", t);
  return 0;
}

// пятое где ктый эл
#define MAXN 10000005
uint32_t arr[MAXN];
uint32_t cur = 0;
uint32_t nextRand24(uint32_t a, uint32_t b) {
  cur = cur * a + b;
  return cur >> 8; // берём старшие 24 бита (сдвиг вправо на 8)
}
uint32_t nextRand32(uint32_t a, uint32_t b) {
  uint32_t x = nextRand24(a, b);
  uint32_t y = nextRand24(a, b);
  return (x << 8) ^ y;
}

void swap(uint32_t arr[], int a, int b) {
  uint32_t t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}
uint32_t seed = 123456789;
uint32_t get_rand() {
  seed = seed * 1664525 + 1013904223;
  return seed;
}

long long partition(uint32_t arr[], int x, int y) {
  uint32_t randic = x + get_rand() % (y - x + 1);
  swap(arr, randic, y);
  int g = x - 1;
  int s = arr[y];
  for (int j = x; j < y; j++) {
    if (arr[j] < s) {
      g++;
      swap(arr, g, j);
    }
  }
  swap(arr, g + 1, y);
  return g + 1;
}
long long raspred(uint32_t arr[], int l, int r, int k) {
  if (l <= r) {
    int p = partition(arr, l, r);
    if (p == k) {
      return arr[p];
    } else if (p > k) {
      return raspred(arr, l, p - 1, k);
    } else {
      return raspred(arr, p + 1, r, k);
    }
  }
  return 0;
}

void quick_sort(int arr[], int x, int y) {
  if (x < y) {
    int pivo = partition(arr, x, y);
    quick_sort(arr, x, pivo - 1);
    quick_sort(arr, pivo + 1, y);
  }
}

int main(void) {
  srand(time(0));
  uint32_t n, k, a, b;
  if (scanf("%u %u %u %u", &n, &k, &a, &b) != 4) {
    return 1;
  }
  for (uint32_t i = 0; i < n; i++) {
    uint32_t x = nextRand32(a, b);
    arr[i] = x;
  }
  long long t = raspred(arr, 0, n - 1, k - 1);

  printf("%lld", t);
  return 0;
}

int vkmax(int arr[], int a) {
  int mx = 0;
  for (int i = 0; i < a; i++) {
    if (arr[i] >= mx) {
      mx = arr[i];
    }
  }
  return mx;
}
void countsort(int arr[], int a) {
  int mx = vkmax(arr, a);

  int art[mx + 1];
  for (int i = 0; i <= mx; i++) {
    art[i] = 0;
  }
  for (int i = 0; i <= a - 1; i++) {
    art[arr[i]]++;
  }
  int c = 0;
  for (int i = 0; i <= mx; i++) {
    int t = art[i];
    for (int j = 0; j < t; j++) {
      arr[c] = i;
      c++;
    }
  }
}