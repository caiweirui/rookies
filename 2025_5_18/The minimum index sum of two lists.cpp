// hash表
typedef struct Hash
{
    char* str;
    int index;
}hash;


char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    hash map[1001] = {0};
    int i = 0;
    int j = 0;
    for(i = 0; i < list1Size; i++)
    {
        map[i].str = list1[i];
        map[i].index = i;
    }

    int min = list1Size + list2Size;
    char** ret = (char**)calloc(1001, sizeof(char*));
    *returnSize = 0;
    for(j = 0; j < list2Size; j++)
    {
        for(i = 0; i < list1Size; i++)
        {
            if(strcmp(list2[j], map[i].str) == 0)
            {
                if(i + j < min)
                {
                    min = i + j;
                    ret[0] = list2[j];
                    *returnSize = 1;
                }else if(i + j == min)
                {
                    ret[*returnSize] = list2[j];
                    *returnSize = *returnSize + 1;
                }
                break;
            }
        }
    }
    return ret;
}