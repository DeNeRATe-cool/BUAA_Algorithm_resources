struct node * select_sort(struct node * head, int n) {
	// 【单向循环链表】选择排序 
    struct node * temphead, * tail;
    struct node * res, * preres, * temp = (struct node *)malloc(sizeof(struct node));
    temp -> id = 0x7fffffff;
    temp -> link = NULL;
    
    // 将单向循环链表先转化为单向链表 
    struct node * q = head;
	while(q -> link != head)
		q = q -> link;
	q -> link = NULL;
    
    rep(i, 1, n) {
        res = temp;
        preres = NULL;
        struct node * p = head, * prep = NULL;
        while(p != NULL) {
            if(p -> id < res -> id) {
                res = p;
                preres = prep;
            }
            prep = p;
            p = p -> link;
        }
        if(res == head) head = head -> link;
        else preres -> link = res -> link;
        if(i == 1) {
            tail = temphead = res;
            res -> link = NULL;
        } else {
            tail -> link = res;
            tail = res;
            res -> link = NULL;
        }
    }
    
    q = temphead;
    while(q -> link != NULL)
		q = q -> link;
	 q -> link = temphead;
    
    return temphead;
} 

void swap(int * ARR, int i, int j) {
	int tmp = ARR[i];
	ARR[i] = ARR[j];
	ARR[j] = tmp;
}

void select_sort(int * ARR, int n) {
	rep(i, 0, n - 2) {
		int loc = i;
		rep(j, i + 1, n - 1) {
			if(ARR[j] < ARR[loc]) 
				loc = j;
		}
		swap(ARR, loc, i);
	}
}

void bubble_sort(int * ARR, int n) {
	int flag = 1;
	for(int i = n - 1; i >= 1 && flag; i--) {
		flag = 0;
		rep(j, 0, i - 1) {
			if(ARR[j] > ARR[j + 1])
				swap(ARR, j, j + 1),
				flag = 1;
		}
	}
} 

void heap_adjust(int * ARR, int x, int n) {
	#define lson (x << 1 | 1)
	#define rson ((x + 1) << 1)
	#define fa ((x - 1) >> 1)
	
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
	#undef lson rson fa
}

void heap_sort(int * ARR, int n) {
	per(i, n / 2 - 1, 0) 
		heap_adjust(ARR, i, n);
		
	per(i, n - 1, 1) {
		swap(ARR, 0, i);
		heap_adjust(ARR, 0, i);
	}
}

void merge_arr(int * ARR, int * tmp, int n, int l, int r) {
	if(l >= r) return;
	int mid = (l + r) >> 1;
	
	merge_arr(ARR, tmp, n, l, mid);
	merge_arr(ARR, tmp, n, mid + 1, r);
	
	int posl = l, posr = mid + 1, loc = l;
	while(posl <= mid && posr <= r) {
		if(ARR[posl] <= ARR[posr])
			tmp[loc++] = ARR[posl++];
		else tmp[loc++] = ARR[posr++];
	}	
	while(posl <= mid) tmp[loc++] = ARR[posl++];
	while(posr <= r) tmp[loc++] = ARR[posr++];
	rep(i, l, r) ARR[i] = tmp[i];
}

void merge_sort(int * ARR, int n) {
	int * tmp = (int *)malloc(sizeof(int) * n);
	merge_arr(ARR, tmp, n, 0, n - 1);
	free(tmp);
}

void quick(int * ARR, int n, int l, int r) {
	if(l >= r) return;
	
	int loc = l;
	rep(i, l + 1, r) {
		if(ARR[i] < ARR[l])
			swap(ARR, ++loc, i);
	}
	swap(ARR, l, loc);
	quick(ARR, n, l, loc - 1);
	quick(ARR, n, loc + 1, r);
}

void quick_sort(int * ARR, int n) {
	quick(ARR, n, 0, n - 1);
}