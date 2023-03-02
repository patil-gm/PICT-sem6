#include <bits/stdc++.h>
using namespace std;
 
int ROW,COL;
 
typedef pair<int, int> Pair;
 
typedef pair<double, pair<int, int> > pPair;
 
struct cell {
    int parent_i, parent_j;
    double f, g, h;
};
 
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL);
}
 
bool isUnBlocked(vector<vector<int>> grid, int row, int col)
{
    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}
 
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
 
double calculateHValue(int row, int col, Pair dest)
{
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first)
        + (col - dest.second) * (col - dest.second)));
}
 
void tracePath(vector<vector<cell>> cellDetails, Pair dest)
{
    printf("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;
 
    stack<Pair> Path;
 
    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
 
    Path.push(make_pair(row, col));
    vector<vector<char>> ans(ROW ,(vector<char> (COL,'.')));

    int gp,an;
    int cnt=1;
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        gp=p.first;
        an=p.second;
        ans[gp][an]='#';
        if(cnt==1)ans[gp][an]='S';
        cnt++;
        cout<<"-> ("<<gp<<","<<an<<")";
    }
    ans[gp][an]='D';
    cout<<endl;
    for(auto it:ans){
        for(auto i:it)cout<<i<<" ";
        cout<<"\n";
    }
 
    return;
}
 
void aStarSearch(vector<vector<int>> grid, Pair src, Pair dest)
{
    if (!isValid(src.first, src.second)) {
        printf("Source is invalid\n");
        return;
    }
 
    if (!isValid(dest.first, dest.second)) {
        printf("Destination is invalid\n");
        return;
    }
 
    if (!isUnBlocked(grid, src.first, src.second)
        || !isUnBlocked(grid, dest.first, dest.second)) {

        printf("Source or the destination is blocked \n");
        return;
    }
 
    if (isDestination(src.first, src.second, dest)) {
        printf("We are already at the destination\n");
        return;
    }
    int row=ROW,col=COL;
    vector<vector<bool>> closedList(ROW,vector<bool>(COL,false));
    vector<vector<cell>> cellDetails(ROW,vector<cell>(col));

    int i, j;
 
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
 
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
 
    set<pPair> openList;
 
    openList.insert(make_pair(0.0, make_pair(i, j)));
 
    bool foundDest = false;
 
    while (!openList.empty()) {
        pPair p = *openList.begin();
 
        openList.erase(openList.begin());
 
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
 
 
        double gNew, hNew, fNew;
 
        //********** up move **********-
 
        if (isValid(i - 1, j) == true) {
          
            if (isDestination(i - 1, j, dest) == true) {
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            else if (closedList[i - 1][j] == false
                     && isUnBlocked(grid, i - 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i - 1][j].f == FLT_MAX
                    || cellDetails[i - 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i - 1, j)));
 
                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }
 
        //**********  down move **********-
 
        if (isValid(i + 1, j) == true) {

            if (isDestination(i + 1, j, dest) == true) {
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            else if (closedList[i + 1][j] == false
                     && isUnBlocked(grid, i + 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i + 1][j].f == FLT_MAX
                    || cellDetails[i + 1][j].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }
 
        //**********   right move **********-
 
        if (isValid(i, j + 1) == true) {
            
            if (isDestination(i, j + 1, dest) == true) {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i][j + 1] == false
                     && isUnBlocked(grid, i, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i][j + 1].f == FLT_MAX
                    || cellDetails[i][j + 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j + 1)));
 
                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }
 
        //********** left move **********-
 
        if (isValid(i, j - 1) == true) {
           
            if (isDestination(i, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i][j - 1] == false
                     && isUnBlocked(grid, i, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i][j - 1].f == FLT_MAX
                    || cellDetails[i][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j - 1)));
 
                    // Update the details of this cell
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
 


    }
 
  
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");
 
    return;
}

int main()
{   ROW=9;
    COL=10;
    vector<vector<int>> grid
        = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };
 
    Pair src = make_pair(8, 0);
 
    Pair dest = make_pair(0,5);
 
    aStarSearch(grid, src, dest);
 
    return (0);
}