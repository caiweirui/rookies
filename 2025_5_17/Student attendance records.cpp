bool checkRecord(char* s) {
    int i = 0;
    int len = strlen(s);
    // 缺勤天数严格少于两天
    int countA = 0;
    for(i = 0; i < len; i++)
    {
        if(s[i] == 'A')
        {
            countA++;
        }
        if(countA >= 2)
        {
            return false;
        }
    }

    // 不存在连续三天以上的迟到记录
    int j = 0;
    int countL = 0;
    for(i = 0; i < len; i++)
    {
        if(s[i] == 'L')
        {
            for(j = i; j < len; j++)
            {
                if(s[j] == 'L')
                {
                    countL++;
                }
                if(countL >= 3 || s[j] != 'L')
                {
                    break;
                }
            }
            if(countL >= 3)
            {
                return false;
            }
            countL = 0;
        }
    }
    
    return true;
}