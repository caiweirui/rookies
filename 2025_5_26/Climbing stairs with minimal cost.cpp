int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize <= 1) return 0;
    int current = 0;
    int i = 0;
    int prev1 = cost[0];
    int prev2 = cost[1];
    
    for (i = 2; i < costSize; i++) {
        current = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev1 = prev2;
        prev2 = current;
    }
    
    return prev1 < prev2 ? prev1 : prev2;
}