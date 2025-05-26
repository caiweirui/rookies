typedef struct
{
    char ch[20];
    int count;
}Hash; 

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    int i = 0;
    int j = 0;
    int flag = 0;
    int tempLen = 0;
    int hashLen = 0;
    Hash hash[1000] = {0};
    int paragraphLen = strlen(paragraph);
    char* temp = (char*)calloc(20, sizeof(char));
    char* ret = (char*)calloc(20, sizeof(char));
    int max = 0;

    // 哈希表
    for(i = 0; i < paragraphLen; i++) 
    {
        tempLen = 0;
        flag = 0;
        while(i < paragraphLen && isalpha(paragraph[i]))
        {
            temp[tempLen++] = tolower(paragraph[i++]);
        }
        // temp有内容
        if(temp[0])
        {
            for(j = 0; j < hashLen; j++)
            {
                // 存在重复的现象
                if(strcmp(hash[j].ch, temp) == 0)
                {
                    hash[j].count++;
                    flag = 1;
                }
            }

            // 不存在重复的现象
            if(!flag)
            {
                strcpy(hash[hashLen].ch, temp);
                hashLen++;
            }

            // 清空temp的内容
            memset(temp, 0, 20);
        }
    }


    for(i = 0; i < hashLen; i++)
    {
        flag = 0;

        // 找最大出现的数量
        if(max <= hash[i].count)
        {
            for(j = 0; j < bannedSize; j++)
            {
                // 被ban的情况
                if(strcmp(banned[j], hash[i].ch) == 0)
                {
                    flag = 1;
                    break;
                }
            }

            // 没有被ban的情况
            if(!flag)
            {
                max = hash[i].count;
                strcpy(ret, hash[i].ch);
            }
        }
    }
    return ret;
}