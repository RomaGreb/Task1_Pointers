#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ui;


int StringListIndexOf(const char* const* list, const char* str);
void StringListDestroy(char*** list);
void StringListAdd(char*** list,const char* str);
void Swap (char** a, char**b);
void PrintList(const char* const* list);
void StringListInit(char*** list, const ui init_size);
void RemoveString (char*** list,const char* str);
void RemoveDuplicatesString (char*** list);
void ListSort(char** const list);
inline int StringListSize(const char* const* list) { return (int)(*(list-1));}
inline int StringListCapacity(const char* const* list) {return (int)(*(list-2));}

