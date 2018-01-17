#include <iostream>
#include <set>
#include <utility>
#include <math.h>

using namespace std;

#define ROW 9
#define COL 10

typedef pair<int, int> coordinates;
typedef pair<int, coordinates> p_pair;

class AStartSearch
{
public:
    AStartSearch() :
        mMatrix(NULL),
        mGoal(),
        mSource(),
        mOpenList()
    {

    }

    bool search(int matrix[][COL], coordinates source, coordinates goal);
    bool printPath();
    bool refresh();

private:

    inline bool isValidBlock(coordinates block)
    {
        if(block.first >= 0 && block.first <= ROW && block.second >= 0 && block.second <= COL)
            return true;
        return false;
    }

    inline double heuristic(coordinates source, coordinates goal)
    {
        return (double) sqrt((goal.first - source.first) * (goal.first - source.first) + 
                            (goal.second - source.second) * (goal.second - source.second));
    }

    inline bool isBlocked(coordinates block)
    {
        return mMatrix ? mMatrix[block.first][block.second] : false;
    }

    inline bool isDestination(coordinates block)
    {
        if(block.first == mGoal.first && block.second == mGoal.second)
            return true;
        else
            return false;
    }

    int **mMatrix;
    coordinates mGoal;
    coordinates mSource;
    set<p_pair> mOpenList;
    bool mClosedList[ROW][COL];
};

int main()
{
    return 0;
}


