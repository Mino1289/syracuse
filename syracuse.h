#ifndef __SYRACUSE_H__
#define __SYRACUSE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double

#define ABS(a)      ((a) < 0 ? -(a) : (a))
#define MAX(a, b)   ((a + b + ABS(a-b)) / 2)
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define SWAP(a, b, T)  {T tmp = a; a = b; b = tmp;}


#define F_OR(i, a, b, s)            for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e)                    F_OR(i, 0, e, 1)
#define F_OR2(i, e)                 F_OR(i, 0, e, 1)
#define F_OR3(i, b, e)              F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s)           F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...)    e
#define F_ORC(...)                  GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
/**
 * @brief max 4 arguments
 * First : the name of the variable the i in 'for (int i = 0; i < n; i++)' (if ommited 'i') (the last to be ommited)
 * Second : the start of the loop   (if ommited 0)      (the second to be ommited)
 * Third : the end of the loop      (can't be ommited)   
 * Fourth : the step of the loop    (if ommited 1)      (the first to be ommited)
 */
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define MAX_VALUE 1<<12
#define MAX_RANK 64


typedef struct Node Node;

struct Node {
    ull value;
    ull rank;
    bool end;

    Node *left;
    Node *right;
};

ull next(ull n);

ull* syracuse(ull n);

ull* prev(ull n);

bool Nbchild(ull n);

Node* create(ull parentvalue, ull rank);

void print_tree(Node *t);

void dot_tree(FILE* stream, Node *t);

void free_tree(Node *t);

void write_py_file(FILE* stream, ull* suite);


#endif
