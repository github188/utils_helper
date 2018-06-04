#ifndef C_MAP_H
#define C_MAP_H

#define null 0 

#include "lock_utils.h"

typedef int status;
typedef void* elem;

typedef struct cmapnode_s{
	char key[64];
	elem data;
	struct cmapnode_s *next;
}cmapnode;
typedef struct
{
	cmapnode *front;
	cmapnode *rear;
	int size;
	CMtx lock;
}cmap;

#ifdef __cplusplus
extern "C"{
#endif
void cmap_init(cmap *p);
//���ͷŽڵ������ڴ�
void cmap_clear(cmap *q);
//���ͷŽڵ������ڴ�
status cmap_destory(cmap *q);
status cmap_is_empty(cmap *q);
status cmap_insert(cmap *q, char* key, elem e);
//���ͷŽڵ������ڴ�
status cmap_erase(cmap *q, char* key);
elem cmap_find(cmap *q, char* key);
cmapnode* cmap_index_get(cmap *q, int index);
int cmap_size(cmap *q);
#ifdef __cplusplus
}
#endif

#endif