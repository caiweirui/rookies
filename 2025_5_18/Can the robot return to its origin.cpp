bool judgeCircle(char* moves) {
    int count[4] = {0};
    int len = strlen(moves);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        switch(moves[i])
        {
            case 'R' : count[0]++;break;
            case 'L' : count[1]++;break;
            case 'U' : count[2]++;break;
            case 'D' : count[3]++;break;
        }
    }
    return ((count[0] == count[1]) && (count[2] == count[3]));
}