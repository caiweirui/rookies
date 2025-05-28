// int cmp(const void* e1, const void* e2)
// {
//     return (*(int*)e1 - *(int*)e2);
// }

// bool lemonadeChange(int* bills, int billsSize) {
//     int i = 0;
//     int j = 0;
//     int give = 0;
//     int changeLen = 0;
//     int* change = (int*)calloc(billsSize, sizeof(int));

//     for(i = 0; i < billsSize; i++)
//     {
//         if(bills[i] != 5)
//         {
//             give = bills[i] - 5;
//             qsort(change, changeLen, sizeof(int), cmp);
//             j = changeLen - 1;
//             while(give >= 0 && j >= 0)
//             {
//                 if(give >= change[j])
//                 {
//                     give -= change[j];
//                     memmove(change + j, change + j + 1, changeLen - j - 1);
//                     changeLen--;
//                 }
//                 j--;
//             }
//             if(give != 0)
//             {
//                 return 0;
//             }
//         }
//         change[changeLen++] = bills[i];
//     }
//     return 1;
// }

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0; // 只跟踪5元和10元数量
    
    for (int i = 0; i < billsSize; i++) {
        switch (bills[i]) {
            case 5:
                five++; // 收5元无需找零
                break;
                
            case 10:
                if (five < 1) return false; // 需找5元
                five--;
                ten++;
                break;
                
            case 20:
                // 优先用10+5找零，次之用5*3
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false; // 无法找零
                }
                break;
        }
    }
    return true;
}