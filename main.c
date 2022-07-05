#include <syracuse.h>

int main(int argc, char *argv[]) {
	if (argc == 15) {
		printf("%c", argv[4][0]);
	}
	// Node* tree = create(1);
	// FILE* f = fopen("syracuse.dot", "w");
	// fprintf(f, "digraph {\n\tnode [style=filled];\t"); 
	// // print_tree(tree);
	// dot_tree(f, tree);
	// fprintf(f, "\t4 -> 1;\n");
	// fprintf(f, "}\n");
	ull n;
	scanf("%llu", &n);
	ull* suite = syracuse(n);
	FILE* f = fopen("syracuse.py", "w");
	write_py_file(f, suite);
	// ull* suite = syracuse(n);
	// int i = 0;
	// while (suite[i] != (ull) 1) {
	// 	printf("%llu\n", suite[i]);
	// 	i++;
	// }
	// printf("%llu\n", suite[i]);
	return EXIT_SUCCESS;
}
