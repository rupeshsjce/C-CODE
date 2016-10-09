#include <stdio.h>
#include <stdlib.h>



void * aligned_malloc(size_t required_bytes, size_t alignment) 
{
	void* p1 = NULL; // original block
	void** p2 = NULL; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) { 
		return NULL;
	}
	printf("\nOffset is : %d Malloc'ed one : %d",offset,p1);
	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1)); 
	p2[-1] = p1;
        return p2;
}

void aligned_free(void *p) {
	free(((void**)p)[-1]); 
}

int main() 
{
	int bytes_required , alignment ;
	printf("\nEnter the bytes_required and alignment :");
	
	scanf("%d %d",&bytes_required , &alignment);
	
	int *ptr = aligned_malloc(bytes_required,alignment);
	printf("\nAddress: %d\n",ptr);


	return 0;
}
