#include <iostream>
#include <set>
#include <utility>
#include <math.h>
#include <stdint.h>

using namespace std;

#define ROW 9
#define COL 10
#define FLT_MAX          3.402823466e+38F        // max value

typedef pair<int, int> coordinates;
typedef pair<double, coordinates> p_pair;

struct BlocksDetails
{
    double f_score;
    coordinates parent;
};

class AStarSearch
{
public:
    AStarSearch() :
        mMatrix(NULL),
        mGoal(),
        mSource(),
        mOpenList(),
        mClosedList(),
        mBlocksDetails()
    {
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                mBlocksDetails[i][j].f_score = FLT_MAX;
                mBlocksDetails[i][j].parent.first = i;
                mBlocksDetails[i][j].parent.second = j;
                mClosedList[i][j] = false;
            }
        }
    }

    bool search(int matrix[][COL], coordinates source, coordinates goal);
    bool printPath();
    bool refresh();

private:

    inline bool isValidBlock(coordinates block)
    {
        if(block.first >= 0 && block.first < ROW && block.second >= 0 && block.second < COL)
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
    BlocksDetails mBlocksDetails[ROW][COL];
};

bool AStarSearch::search(int matrix[][COL], coordinates source, coordinates goal)
{
    if(!isValidBlock(source) || !isValidBlock(goal))
    {
        cout<<"Invlaid source or goal\n";
        return false;
    }

    mOpenList.insert(make_pair(heuristic(source, goal), make_pair(source.first, source.second)));
    mBlocksDetails[source.first][source.second] = {heuristic(source, goal), source};

    while(!mOpenList.empty())
    {
        p_pair p = *mOpenList.begin();
        mOpenList.erase(mOpenList.begin());
        mClosedList[p.second.first][p.second.second] = true;

        //Calculate all the neighbours of p

        //For each neighbor:
            //If neighbor valid:
                //if is goal state then return and print path
                //else
                    //if in closed list then continue
                    //else
                        //calculate f(n) for new neighbor
                        //Add it to open list
                        //if f(n) is less than current, update mBlockDetails

        

    }
}

int main()
{
    return 0;
}


