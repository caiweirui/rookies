int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int i = 0;
    int j = 0;
    int begin = 0;
    int end = 0;
    int ret = 0;
    for(i = 0; i < timeSeriesSize - 1; i++)
    {
        ret += (timeSeries[i + 1] - timeSeries[i] >= duration) ? duration : (timeSeries[i + 1] - timeSeries[i]);
    }
    ret += duration;
    return ret;
}