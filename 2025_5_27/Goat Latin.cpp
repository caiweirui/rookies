#include <malloc.h>
#include <ctype.h>
#include <string.h>

char* toGoatLatin(char* sentence) {
    char* ret = (char*)calloc(10000, sizeof(char));
    char* temp = (char*)calloc(1000, sizeof(char));
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    char ch = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    int index = 0;
    int tempLen = 0;
    int vowelLen = sizeof(vowel) / sizeof(vowel[0]);
    int sentenceLen = strlen(sentence);

    for(i = 0; i < sentenceLen; i++)
    {
        flag = 0;
        index++;
        tempLen = 0;
        memset(temp, 0, 100);
        if(isspace(sentence[i]))
        {
            continue;
        }
        while(i < sentenceLen && isalpha(sentence[i]))
        {
            temp[tempLen++] = sentence[i++];
        }

        // 如果单词以元音开头（'a', 'e', 'i', 'o', 'u'），在单词后添加"ma"
        // 如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"
        for(j = 0; j < vowelLen; j++)
        {
            if(temp[0] == vowel[j] || temp[0] == vowel[j] - 32)
            {
                flag = 1;
            }
        }

        if(flag == 0)
        {
            ch = temp[0];
            memmove(temp, temp + 1, tempLen);
            temp[tempLen - 1] = ch;
        }

        strcat(temp, "ma");
        tempLen += 2;

        // 根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从 1 开始
        for(j = 0; j < index; j++)
        {
            temp[tempLen++] = 'a';
        }

        strcat(ret, temp);
        ret[strlen(ret)] = ' ';
    }
    ret[strlen(ret) - 1] = 0;
    return ret;
}