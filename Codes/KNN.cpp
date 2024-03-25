#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    cout<<"Points in the set :"<<nl;
    for (auto x : p)
    {
        cout<<x<<" ";
    }
    cout<<nl;

    int k;//number of clusters
    cin >> k;
    int currentcentroid[k],previouscentroid[k];
    for (int i = 0; i < k; i++)
    {
        cin>>currentcentroid[i];
    }

    cout<<"The "<<k<<" Centroids are :"<<nl;
    for (auto x : currentcentroid)
    {
        cout<<x<<" ";
    }
    cout<<nl;

    // k-means algorithm
    bool flag = true;
    int cluster[n],step=1;
    while (flag)
    {
        cout<<"Step : "<<step<<nl;step++;
        for (int i = 0; i < k; i++){previouscentroid[i] = currentcentroid[i];}//copy the centroid

        double distance[k][n];//k array of size n to store the distance of each point from each centroid
        for (int i = 0; i < k; i++)
        {
            cout<<"Distance from centroid "<<i+1<<nl;
            for (int j = 0; j < n; j++)
            {
                distance[i][j] = abs(currentcentroid[i] - p[j]);
                cout << distance[i][j] << " ";// print the distances
            }
            cout<<nl<<nl;
        }

        // devide the points into k clusters
        for (int i = 0; i < n; i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                if (distance[j][i] < min)
                {
                    min = distance[j][i];
                    cluster[i] = j;
                }
            }
        }

        // print the clusters
        cout<<"Clusters : ";
        for (auto x : cluster)
        {
            cout<<x<<" ";
        }
        cout<<nl;
        
        // update the centroids
        for (int i = 0; i < k; i++)
        {
            int sum = 0, count = 0;
            for (int j = 0; j < n; j++)
            {
                if (cluster[j] == i)
                {
                    sum += p[j];
                    count++;
                }
            }
            currentcentroid[i] = sum / count;
        }
        // print the centroids
        cout<<nl<<"Updated Centroids :"<<nl;
        for (auto x : currentcentroid)
        {
            cout<<x<<" ";
        }

        // if the two cenroids are same then stop the loop
        for (int i = 0; i < k; i++)
        {
            if (previouscentroid[i] != currentcentroid[i])
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
            }
        }
    }

    return 0;
}
/*
Input:
9
2 3 4 10 11 12 20 25 30
2
4 12
*/