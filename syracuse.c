#include <syracuse.h>

ull next(ull n) {
    if (n%2==0) {
        return n>>1;
    } 
    return (1+n)+(n<<1);
}

ull* syracuse(ull n) {
    ull *result = malloc(sizeof(ull));
    result[0] = n;
    ull i = 1,k = n;
    while (k != (ull) 1) {
        k = next(k);
        result = realloc(result, (i+1)*sizeof(ull));
        result[i] = k;
        i++;
    }
    return result;
}

ull* prev(ull n) {
    ull* res = malloc(sizeof(ull) * 2);
    ull tmp;
    if (n % 2 == 0) {
        res[0] = n<<1;
        tmp = (n-1)/3;
        if ((1+tmp)+(tmp<<1) == n) {
            res[1] = tmp;
        } else {
            res[1] = res[0];
        }
    } else {
        res[0] = n<<1;
        res[1] = res[0];
    }
    return res;
}

bool Nbchild(ull n) {
    ull* res = prev(n);
    ull tmp1 = res[0], tmp2 = res[1];
    free(res);
    return (tmp1 != tmp2);
}

Node* create(ull parentvalue, ull rank) {
    Node *p = (Node*) malloc(sizeof(Node));
    p->value = parentvalue;
    p->end = false;
    p->rank = rank;
    if (parentvalue > MAX_VALUE || rank >= MAX_RANK) {
        p->end = true;
        return p;
    }
    ull* res = prev(parentvalue);
    if (res[0] == res[1]) {
        p->left = create(res[0], rank+1);
        p->right = NULL;
    } else {
        if (res[1] != 1) {
            p->left = create(res[0], rank+1);
            p->right = create(res[1], rank+1);
        } else {
            p->left = create(res[0], rank+1);
            p->right = NULL;
        }
    }
    free(res);
    return p;
}

void print_tree(Node *t) { //address of root node is passed in t
    if(t != NULL) {
        printf("\n%llu",t->value); //visit the root
        if (!t->end) {
            print_tree(t->left); //preorder traversal on left subtree
            print_tree(t->right); //preorder traversal om right subtree
        }
    }
}

void free_tree(Node *t) {
    if (t != NULL) {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}

void dot_tree(FILE* stream, Node *t) {
    if(t != NULL) {
        if (!t->end) {
            fprintf(stream, "\t%llu [label=\"%llu\n%llu\", color=%s];\n", t->value, t->value, t->rank, Nbchild(t->value) ? "orange" : "lightblue");
            dot_tree(stream, t->left);
            dot_tree(stream, t->right);
            if (t->left != NULL) {
                fprintf(stream, "\t%llu [label=\"%llu\n%llu\", color=%s];\n", t->left->value, t->left->value, t->left->rank, Nbchild(t->left->value) ? "orange" : "lightblue");
                fprintf(stream, "\t%llu -> %llu;\n", t->value, t->left->value);
            }
            if (t->right != NULL) {
                fprintf(stream, "\t%llu [label=\"%llu\n%llu\", color=%s];\n", t->right->value, t->right->value, t->right->rank, Nbchild(t->right->value) ? "orange" : "lightblue");
                fprintf(stream, "\t%llu -> %llu;\n", t->value, t->right->value);
            }
        }
    }
}

void write_py_file(FILE* stream, ull* suite) {
    fprintf(stream, "import matplotlib.pyplot as plt\n");
    fprintf(stream, "suite = [");
    int i = 0;
    while (suite[i] != (ull) 1) {
        fprintf(stream, "%llu, ", suite[i]);
        i++;
    }
    fprintf(stream, "%llu]\n", suite[i]);
    fprintf(stream, "plt.plot(suite)\n");
    fprintf(stream, "plt.show()\n");
}


/*
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
 
node *create() {
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
 
void preorder(node *t) { //address of root node is passed in t
    if(t!=NULL) {
        printf("\n%d",t->data); //visit the root
        preorder(t->left); //preorder traversal on left subtree
        preorder(t->right); //preorder traversal om right subtree
    }
}
 
int main() {
    node *root;
    root=create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    return 0;
}
*/