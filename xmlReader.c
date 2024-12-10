#include <stdio.h> 
#include <stdlib.h> 

char* read_file_ascii(const char* path) { 
	FILE* fp = fopen(path, "r"); 
	if (!fp) { 
		printf("Error loading file '%s'\n", path); 
		return NULL; 
	} 

	fseek(fp, 0, SEEK_END); 
	int size = ftell(fp); 
	fseek(fp, 0, SEEK_SET); 

	char* buf = (char*) malloc(sizeof(char) * (size + 1)); 
	fread(buf, sizeof(char), size, fp); 
	fclose(fp); 

	buf[size] = '\0'; 
	return buf; 
} 

int main(int argc, char** argv) { 
	char* source = read_file_ascii("catalog.xml"); 
	printf("%s\n", source); 
	free(source); 
	return 0; 
}
