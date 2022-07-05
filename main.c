#include <syracuse.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s <tree|graph> <start_number>\n", argv[0]);
		return EXIT_FAILURE;
	} else {
		ull n = atoll(argv[2]);
		if (strcmp(argv[1], "tree") == 0) {
			Node* tree = create(n);
			FILE* f = fopen("tree.dot", "w");
			fprintf(f, "digraph {\n\tnode [style=filled];\t"); 
			dot_tree(f, tree);
			if (n == 1) {
				fprintf(f, "\t4 -> 1;\n");
			}
			fprintf(f, "}\n");
			fclose(f);
			// free_tree(tree);
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "graph") == 0) {
			ull* suite = syracuse(n);
			FILE* f = fopen("syracuse.py", "w");
			write_py_file(f, suite);
			fclose(f);
			free(suite);
			return EXIT_SUCCESS;
		} else {
			printf("Usage: %s <tree|graph> <start_number>\n", argv[0]);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
