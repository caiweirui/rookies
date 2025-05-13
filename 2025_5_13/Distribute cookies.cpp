#include<string.h>

int cmp(const void *e1, const void *e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int ret = 0;
    int *pg = g;
    int *ps = s;
    while(pg - g < gSize && ps - s < sSize)
    {
        if(*pg <= *ps)
        {
            ret++;
            pg++;
            ps++;
        }
        else
        {
            ps++;
        }
    }
    return ret;
}