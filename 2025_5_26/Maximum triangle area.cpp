double d(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double s(double d1, double d2, double d3)
{
    double p = (d1 + d2 + d3) / 2;
    return sqrt(p * (p - d1) * (p - d2) * (p - d3));
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    double d1 = 0.0;
    double d2 = 0.0;
    double d3 = 0.0;
    double ret = 0.0;
    double temp = 0.0;
    for(i = 0; i < pointsSize; i++)
    {
        for(j = i + 1; j < pointsSize; j++)
        {
            for(k = j + 1; k < pointsSize; k++)
            {
                d1 = d(points[i][0], points[i][1], points[j][0], points[j][1]);
                d2 = d(points[i][0], points[i][1], points[k][0], points[k][1]);
                d3 = d(points[k][0], points[k][1], points[j][0], points[j][1]);
                temp = s(d1, d2, d3);
                if(temp > ret)
                {
                    ret = temp;
                }
            }
        }
    }
    return ret;
}