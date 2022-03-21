#include "TriPath.h"
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*x = 0 is the topmost path, while x=3^N -1 is the bottommost 
 2 = up
 1 = same
 0 = down
*/
void TriPath::PathByNumber(int x, int *path){
    if(x < 0 || x > pow(3,N)-1){
        cout << "Error - x out of range" << endl;
    } 
}

void TriPath::PricesByPath(int *path, double *prices){
    int e = 2;
}

double TriPath::ProbabilityByPath(int *path){
    double prob;
    return prob;
}

int TriPath::getNode(int x, int n){
    if(n <0){ return 99; } //Failure case
    //Base case
    if(n==0){
        if(x==0){
            return 1;
        }else if (x==1)
        {
            return 2;
        } else{
            return 3;
        }
    }else{
        //Edge cases
        if(x == 0){
            return 1;
        }else if (x == pow(3,n)-1)
        {
            return (2*n)+1;
        }else if (x==1 || x==2)
        {
            return 2;
        }else if (x==pow(3,n)-2 || x==pow(3,n)-3)
        {
            return 2*n;
        }
        //General case 
        else{
            /*  From this point on, each node has three incoming paths. 
                So by taking the floor of x/3, we know how many nodes down the tree we need to go 
                before arriving at the node which x is on.
                i.e if x=5. the floor(5/3)=1, so we stay on node 3, which is 2+1
                Conversely, if x=8, floor(8/3)=2, so we go to node 2+2=4. The reason for the 
                2+f is because the first two nodes are covered in the base case.
            */
            int f = floor(x/3);
            return 2 + f;
        }
    }
}

int TriPath::getPos(int x, int node){
 
}

void TriPath::AllPaths(){
    /*
    We use Heap's Algorithm for generating all permutations of the 
    */

    int moves[3] = {2,1,0};
    const int NumPaths = pow(3,N);
    int paths[NumPaths][N];

}