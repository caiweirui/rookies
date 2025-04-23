int numberOfAlternatingGroups(int* colors, int colorsSize) {
    int i = 0;
    int count = 0;
    for(i = 0; i < colorsSize; i++)
    {
        if(i == 0)
        {
            if(colors[i + 1] != colors[i] && colors[colorsSize - 1] != colors[i])
            {
                count++;
            }
        }
        else if(i == colorsSize - 1)
        {
            if(colors[i - 1] != colors[i] && colors[0] != colors[i])
            {
                count++;
            }

        }
        else
        {
            if((colors[i + 1] != colors[i] && colors[i - 1] != colors[i]))
            {
                count++;
            }
        }

    }
    return count;
}