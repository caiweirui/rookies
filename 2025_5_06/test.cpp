// int maxProfit(int* prices, int pricesSize) {
//     int min = prices[0];
//     int max = 0;
//     int i = 0;
//     int j = 0;
//     for(i = 0; i < pricesSize; i++)
//     {
//         if(min > prices[i])
//         {
//             min = prices[i];
//             j = i;
//         }
//     }
//     if(j != pricesSize - 1)
//     {
//         while(j < pricesSize)
//         {
//             if(max < prices[j])
//             {
//                 max = prices[j];
//             }
//             j++;
//         }
//     }
//     else
//     {
//         min = prices[0];
//         j = 0;
//         for(i = 0; i < pricesSize - 1; i++)
//         {
//             if(min > prices[i])
//             {
//                 min = prices[i];
//                 j = i;
//             }
//         }
//         while(j < pricesSize)
//         {
//             if(max < prices[j])
//             {
//                 max = prices[j];
//             }
//             j++;
//         }
//     }
//     return ((max - min) > 0 ? max - min : 0);
// }

int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < pricesSize - 1; i++)
    {
        for(j = i + 1; j < pricesSize; j++)
        {
            if(prices[j] - prices[i] > max)
            {
                max = prices[j] - prices[i];
            }
        }
    }
    return max;
}