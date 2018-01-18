#include <iostream>
#include <set>
#include <stack>
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
    double g_score;
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
                mBlocksDetails[i][j].g_score = 0;
                mBlocksDetails[i][j].parent.first = -1;
                mBlocksDetails[i][j].parent.second = -1;
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

bool AStarSearch::printPath()
{
    coordinates c = mGoal;
    stack<coordinates> st;

    while(mBlocksDetails[c.first][c.second].parent != c)
    {
        st.push(c);
        c = mBlocksDetails[c.first][c.second].parent;
    }

    cout<<"Path: \n";

    while(!st.empty())
    {
        cout<<"--->("<<st.top().first<<", "<<st.top().second<<")";
        st.pop();
    }

    cout<<"\n";
}

bool AStarSearch::search(int matrix[][COL], coordinates source, coordinates goal)
{
    if(!isValidBlock(source) || !isValidBlock(goal))
    {
        cout<<"Invlaid source or goal\n";
        return false;
    }

    mMatrix = (int **)matrix;
    mSource = source;
    mGoal = goal;

    mOpenList.insert(make_pair(heuristic(mSource, mGoal), make_pair(mSource.first, mSource.second)));
    mBlocksDetails[mSource.first][mSource.second] = {heuristic(mSource, mGoal), 0, mSource};

    while(!mOpenList.empty())
    {
        p_pair p = *mOpenList.begin();
        mOpenList.erase(mOpenList.begin());

        if(p.second == mGoal)
        {
            return printPath();
        }

        mClosedList[p.second.first][p.second.second] = true;

        //Calculate all the neighbours of p
        coordinates neighbors[8] = {};
        neighbors[0] = make_pair(p.second.first, p.second.second + 1);
        neighbors[1] = make_pair(p.second.first + 1, p.second.second + 1);
        neighbors[2] = make_pair(p.second.first + 1, p.second.second);
        neighbors[3] = make_pair(p.second.first + 1, p.second.second - 1);
        neighbors[4] = make_pair(p.second.first - 1, p.second.second);
        neighbors[5] = make_pair(p.second.first - 1, p.second.second - 1);
        neighbors[6] = make_pair(p.second.first, p.second.second - 1);
        neighbors[7] = make_pair(p.second.first - 1, p.second.second + 1);

        //For each neighbor:
            //If neighbor valid:
                //if in closed list or is blocked then continue
                //else
                    //calculate f(n) for new neighbor
                    //Add it to open list
                    //if f(n) is less than current, update mBlockDetails

        for(int i = 0; i < 8; i++)
        {
            if(!isValidBlock(neighbors[i]))
                continue;

            //If block is in closed list, continue
            if(mClosedList[neighbors[i].first][neighbors[i].second] || isBlocked(neighbors[i]))
                continue;

            double tentativeGScore = mBlocksDetails[p.second.first][p.second.second].g_score + 1.0;
            double tentativeFScore = heuristic(neighbors[i], mGoal) + tentativeGScore;

            mOpenList.insert(make_pair(tentativeFScore, make_pair(neighbors[i].first, neighbors[i].second)));

            if(tentativeFScore <= mBlocksDetails[neighbors[i].first][neighbors[i].second].f_score)
            {
                mBlocksDetails[neighbors[i].first][neighbors[i].second].f_score = tentativeFScore;
                mBlocksDetails[neighbors[i].first][neighbors[i].second].g_score = tentativeGScore;
                mBlocksDetails[neighbors[i].first][neighbors[i].second].parent = p.second;
            }
        }
    }

    return false;
}

int main()
{
        /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    int grid[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };
 
    // Source is the left-most bottom-most corner
    coordinates src = make_pair(8, 0);
 
    // Destination is the left-most top-most corner
    coordinates dest = make_pair(0, 0);
 
    AStarSearch *s = new AStarSearch();
    s->search(grid, src, dest);

    return 0;
}


