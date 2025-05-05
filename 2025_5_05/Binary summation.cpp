char* addBinary(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int cf = 0;
    int af = lena - 1;
    int bf = lenb - 1;
    char *ret = (char *)calloc(10002, sizeof(char));
    int lenret = 0;
    if(lena > lenb)
    {
        while(bf >= 0)
        {
            ret[lena - lenret] = ((a[af] - '0') + (b[bf] - '0') + cf) % 2 + '0';
            if((a[af] - '0') + (b[bf] - '0') + cf >= 2)
            {
                cf = 1;
            }
            else
            {
                cf = 0;
            }
            bf--;
            af--;
            lenret++;
        }
        while(af >= 0)
        {
            ret[lena - lenret] = (a[af] - '0' + cf) % 2 + '0';
            if(a[af] - '0' + cf >= 2)
            {
                cf = 1;
            }
            else
            {
                cf = 0;
            }
            af--;
            lenret++;
        }
    }
    else
    {
        while(af >= 0)
        {
            ret[lenb - lenret] = ((a[af] - '0') + (b[bf] - '0') + cf) % 2 + '0';
            if((a[af] - '0') + (b[bf] - '0') + cf >= 2)
            {
                cf = 1;
            }
            else
            {
                cf = 0;
            }
            bf--;
            af--;
            lenret++;
        }
        while(bf >= 0)
        {
            ret[lenb - lenret] = (b[bf] - '0' + cf) % 2 + '0';
            if(b[bf] - '0' + cf >= 2)
            {
                cf = 1;
            }
            else
            {
                cf = 0;
            }
            bf--;
            lenret++;
        }
    }
    if(cf == 1)
    {
        ret[0] = '1';
        return ret;
    }
    else
    {
        return ret + 1;
    }
}