int romanToInt(char* s) {
    int i = 0;
    int len = strlen(s);
    int sum = 0;
    for(i = 0; i < len; i++)
    {
        switch(s[i])
        {
            case 'I': 
                if((s[i + 1] == 'V' || s[i + 1] == 'X') && i + 1 < len)
                {
                    sum += -1;
                }
                else
                {
                    sum += 1;
                }
            break;
            
            case 'X':
                if((s[i + 1] == 'L' || s[i + 1] == 'C') && i + 1 < len)
                {
                    sum += -10;
                }
                else
                {
                    sum += 10;
                }
            break;

            case 'C':
                if((s[i + 1] == 'D' || s[i + 1] == 'M') && i + 1 < len)
                {
                    sum += -100;
                }
                else
                {
                    sum += 100;
                }
            break;

            case 'V':
                sum += 5;
            break;

            case 'L':
                sum += 50;
            break;

            case 'D':
                sum += 500;
            break;

            case 'M':
                sum += 1000;
            break;

            default:break;
        }
    }
    return sum;
}