#include <bits/stdc++.h>
using namespace std;
pair<double, double> minXY;

// Test Case 1
// 0 0  1 1  2 2  1 0  2 0
// Convex hull
// (0; 0), (2; 0), (2; 2), (0; 0)
// Test Case 2
// 0 0  1 1  2 2  3 3  4 4  5 5  6 6  7 7
// Convex hull
// (0; 0), (7; 7), (0; 0)
// Test Case 3
// 0 0  1 2  2 4  4 3  5 1  7 0  -1 -1  3 -2  2 -4  0 -3
// Convex hull
// (2; -4), (7; 0), (4; 3), (2; 4), (-1; -1), (0; -3), (2; -4)

double distance(pair<double, double> first, pair<double, double> second)
{
    return (second.first - first.first) * (second.first - first.first) + (second.second - first.second) * (second.second - first.second);
}
double outlier(pair<double, double> first, pair<double, double> second, pair<double, double> third)
{
    double area = (second.second - first.second) * (third.first - first.first) - (third.second - first.second) * (second.first - first.first);
    return area >= 0;
}
bool compare(pair<double, double> first, pair<double, double> second)
{
    double area = (first.second - minXY.second) * (second.first - minXY.first) - (second.second - minXY.second) * (first.first - minXY.first);
    if (area != 0)
        return area < 0;
    return distance(minXY, first) < distance(minXY, second);
}
vector<pair<double, double>> convexHull(vector<pair<double, double>> &coordinates)
{
    minXY = coordinates[0];
    int minIndex = 0;
    for (int i = 1; i < coordinates.size(); i++)
        if (coordinates[i].second < minXY.second or (minXY.second == coordinates[i].second and coordinates[i].first < minXY.first))
            minXY = coordinates[i], minIndex = i;
    swap(coordinates[0], coordinates[minIndex]);
    sort(coordinates.begin() + 1, coordinates.end(), compare);
    vector<pair<double, double>> hull;
    hull.push_back(coordinates[0]);
    hull.push_back(coordinates[1]);
    for (int i = 2; i < coordinates.size(); i++)
    {
        while (hull.size() > 1 and outlier(hull[hull.size() - 2], hull[hull.size() - 1], coordinates[i]))
            hull.pop_back();
        hull.push_back(coordinates[i]);
    }
    hull.push_back(hull.front());
    return hull;
}
int main()
{
    vector<pair<double, double>> coordinates;
    int inputSize;
    cout << "No of coordinates : ";
    cin >> inputSize;
    unordered_map<string, int> mp;
    for (int i = 0; i < inputSize; i++)
    {
        pair<double, double> input;
        cin >> input.first >> input.second;
        if (mp[to_string(input.first) + to_string(input.second)] == 0)
            coordinates.push_back(input), mp[to_string(input.first) + to_string(input.second)] = 1;
    }
    if (coordinates.size() == 1)
    {
        cout << "Convex Hull:" << endl;
        cout << coordinates[0].first << " " << coordinates[0].second << endl;
        cout << coordinates[0].first << " " << coordinates[0].second << endl;
        cout << "Total Points on ConvexHull: " << coordinates.size();
    }
    else
    {
        cout << "Convex Hull:" << endl;
        vector<pair<double, double>> output = convexHull(coordinates);
        for (auto &&coordinate : output)
            cout << coordinate.first << " " << coordinate.second << endl;
        cout << "Total Points on ConvexHull: " << output.size() - 1;
    }
    cout << endl;
    return 0;
}