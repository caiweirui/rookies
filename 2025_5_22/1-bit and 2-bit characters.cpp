bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    int count = 0;
    for(i = 0; i < bitsSize; i++)
    {
        count = 0;
        if(bits[i] == 1)
        {
            i++;
            count++;
        }
        count++;
    }
    return (count == 1);
}