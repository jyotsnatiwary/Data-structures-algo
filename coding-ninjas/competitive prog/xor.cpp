#include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
     
    #define null NULL
    #define new(type) ((type *)malloc(sizeof(type)))
     
    typedef struct Node {
    	int cnt;
    	struct Node *next[2];
    } Node;
     
    Node *get_node() {
    	Node *v = new(Node);
    	v->cnt = 0;
    	v->next[0] = v->next[1] = null;
    	return v;
    }
     
    void add(Node *v, int key, int lev) {
    	if(lev == -1) return;
    	int at = (key & (1<<lev)) ? 1 : 0;
    	if(v->next[at] == null) v->next[at] = get_node();
    	add(v->next[at], key, lev - 1);
    	v->next[at]->cnt++;
    }
     
    long long int cnt;
     
    void query(Node *v, int a, int k, int lev) {
    	if(lev == -1) return;
    	int ik = (k & (1<<lev)) ? 1 : 0;
    	int ib = ((a & (1<<lev)) ? 1 : 0) ^ ik;
    	if(ik == 1) cnt += (v->next[!ib] == null) ? 0 : v->next[!ib]->cnt;
    	if(v->next[ib] != null) query(v->next[ib], a, k, lev - 1);
    }
     
    void free_tree(Node *v) {
    	if(v == null) return;
    	free_tree(v->next[0]);
    	free_tree(v->next[1]);
    	free(v);
    }
     
    int main() {
    	int cc, tc;
    	scanf("%d", &tc);
    	for(cc=0; cc<tc; cc++) {
    		Node *root = get_node();
    		int i, n, k, val, xr = 0;
    		cnt = 0;
    		scanf("%d %d", &n, &k);
    		for(i=0; i<n; i++) {
    			scanf("%d", &val);
    			xr ^= val;
    			query(root, xr, k, 20);
    			add(root, xr, 20);
    		}
    		query(root, 0, k, 20);
    		printf("%lld\n", cnt);
    		free_tree(root);
    	}
    	
    	return 0;
    }
     
