#define maxn 100005

#define lson (x << 1 | 1)
#define rson ((x + 1) << 1)
#define fa ((x - 1) >> 1)

int n;

void swap(int *ARR, int x, int y) {
	int temp = ARR[x];
	ARR[x] = ARR[y];
	ARR[y] = temp;
}

void heap_adjust(int * ARR, int x) {
	
	int temp = ARR[x];
	while(lson < n) {
		if(rson < n && ARR[rson] > ARR[lson] && ARR[rson] > temp) {
			ARR[x] = ARR[rson];
			x = rson;
		} else if(ARR[lson] > temp) {
			ARR[x] = ARR[lson];
			x = lson;
		} else break;
	}
	ARR[x] = temp;
}

void heap_sort(int * ARR) {
	per(i, n / 2 - 1, 0) 
		heap_adjust(ARR, i, n);
	
	// for sorting
		
//	per(i, n - 1, 1) {
//		swap(ARR, 0, i);
//		heap_adjust(ARR, 0, i);
//	}
}

int top(int *ARR) {
	return ARR[0];
}

void pop(int *ARR) {
	ARR[0] = ARR[n - 1];
	n--;
	heap_adjust(ARR, 0);
}

void del(int *ARR, int x) {
	swap(ARR, x, n - 1);
	n--;
	heap_adjust(ARR, x);
}

void increase(int *ARR, int x, int val) {
	ARR[x] = val;
	while(x > 0 && ARR[fa] < ARR[x]) {
		swap(ARR, fa, x);
		x = fa;
	}	
}

void push(int *ARR, int val) {
	ARR[n++] = int(-1e9);
	increase(ARR, n - 1, val);	
}

void delete_by_val(int *ARR, int x) {
	rep(i, 0, n - 1) {
		if(ARR[i] == x) {
			ARR[i] = ARR[n - 1];
			n--;
			heap_adjust(ARR, i);
			while(i > 0 && ARR[(i - 1) >> 1] < ARR[i]) {
				swap(ARR, (i - 1) >> 1, i);
				i = ((i - 1) >> 1);
			}
			break;
		}
	}
}