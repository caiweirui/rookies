// bool validPalindrome(char* s) {
//     int len = strlen(s);
//     int left = 0;
//     int right = len - 1;
//     int flag = 1;
//     while(left < right)
//     {
//         if(s[left] != s[right] && !flag)
//         {
//             return 0;
//         }
//         if(s[left] != s[right] && flag)
//         {
//             if(s[left + 1] == s[right])
//             {
//                 right++;
//             }
//             else if(s[left] == s[right - 1])
//             {
//                 left--;
//             }
//             else
//             {
//                 return 0;
//             }
//             flag = 0;
//         }
//         left++;
//         right--;
//     }
//     return 1;
// }

bool isPalindrome(char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            // 尝试删除左字符或右字符，任一成立即可
            return isPalindrome(s, left + 1, right) || 
                   isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}