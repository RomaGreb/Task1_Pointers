#include "Test.h"

void StringListInit(char*** list, const ui init_size)
{
    if(list)
    {
        int memory_volume = init_size * sizeof(char*) + 2 * sizeof(ui);
        void* allocate_memory = malloc(memory_volume);
        if(allocate_memory == 0)
        {
            std::cout << "Cannon allocate memory";
            system("pause");
            exit(-1);
        }
        memset(allocate_memory,0,memory_volume);
        ui* capacity = (ui*) allocate_memory;
        ui* act_size = (ui*) allocate_memory + 1;
        *capacity = init_size;
        *act_size = 0;
        *list = (char**) (capacity + 2);
    }
    else
    {
        std::cout << "List has been initialized" << '\n';
        return;
    }
}

void StringListDestroy(char*** list)
{
    if(list != 0 && *list != 0)
    {
        int list_size = StringListSize(*list);
        void* mem_volume = ((ui*)(*list)) - 2;
        for(int i = 0; i < list_size; ++i)
        {
            char* mem_free = (*list)[i];
            free(mem_free);
            (*list)[i] = 0;
        }
        free(mem_volume);
        *list = 0;
    }
    else std::cout << "List has been destroyed" << '\n';
}

int StringListIndexOf(const char* const* list, const char* str)
{
    for(int i = 0; i < StringListSize(list); ++i)
    {
        if(strcmp(*list,str) == 0)
        return i;
    }
     return -1;
}

void StringListAdd(char*** list, const char* str)
{
    if(StringListSize(*list) == StringListCapacity(*list))
    {
        ui old_capacity = StringListCapacity(*list);
        ui new_capacity = old_capacity * 2;
        void* new_memory = (*list) - 2;
        new_memory = realloc(new_memory,new_capacity * sizeof(char*) + 2 * sizeof(ui));
        if(new_memory == 0)
        {
            std::cout << "Cannon allocate memory";
            system("pause");
            exit(-1);
        }
        else
        {
            *list = reinterpret_cast<char**>((ui*)new_memory+2);
            memset((*list)+old_capacity,0,(new_capacity-old_capacity)*sizeof(char*));
            *((*list) - 2) += new_capacity - old_capacity;
        }
    }
    int position = StringListSize(*list);
    (*list)[position] = static_cast<char*>(malloc(strlen(str)+1));
    strcpy((*list)[position],str);
    ui* act_size = (ui*) ((*list)-1);
    ++(*act_size);
}

void RemoveString (char*** list,const char* str)
{
    int list_size = StringListSize(*list);
    if(list_size == 0)
        std::cout << "List is empty" << '\n';
    else
    {
        for(int i = 0; i < list_size; ++i)
        {
            if(!strcmp((*list)[i],str))
            {
               for(int j = i; j < list_size-1; ++j)
                    strcpy(((*list)[j]),((*list)[j+1]));
                free((*list)[list_size]);
                (*list)[list_size] = 0;
                ui* act_size = (ui*) ((*list)-1);
                --(*act_size);
                 return;
            }
        }
        std::cout << "String not found" << '/n';
    }
}

void RemoveDuplicatesString(char*** list)
{
    for(int i = 0; i < StringListSize(*list) - 1; ++i)
    {
       for(int j = i+1; j < StringListSize(*list); ++j)
       {
           if(!strcmp((*list)[i],(*list)[j]))
            RemoveString(list,(*list)[j]);
       }
    }
 }

void PrintList(const char* const* list)
{
    if(list == 0)
    {
        std::cout << "List doesn'n exist" << '/n';
        return;
    }
    int list_size = StringListSize(list);
    if(list_size == 0)
    {
        std::cout << "List is empty" << '\n';
        return;
    }
    for(int i = 0; i < list_size; ++i)
    {
        int len = strlen(*list);
        for(int j = 0; j < len; ++j)
            std::cout << (*list)[j];

        std::cout << ' ';
        list++;
    }
}

void ListSort(char** const list)
{
    if(StringListSize(list) == 0)
        std::cout << "List is empty" << '\n';
    for(int i = 0; i < StringListSize(list); ++i)
    {
        for(int j = i+1; j < StringListSize(list)-1;++j)
        {
            if(strcmp(list[j],list[j+1]) > 0)
                Swap(&list[j],&list[j+1]);
        }
    }
}

void Swap (char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
