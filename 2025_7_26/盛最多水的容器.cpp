int maxArea(int* height, int heightSize) {
    int *p1 = height;
    int *p2 = height + heightSize - 1;
    int ret = 0;
    int temp = 0;
    while(p1 < p2)
    {
        temp = (p2 - p1) * fmin(*p1, *p2); 
        if(temp > ret)
        {
            ret = temp;
        }
        *p1 > *p2 ? p2-- : p1++;
    }
    return ret;
}