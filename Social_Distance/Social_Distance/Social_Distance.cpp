#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct seg {
    int left, right;
    seg( int a, int b)
        :left(a),right(b){}
};

struct cmp {//sort the best segment
    bool operator() (const seg &lhs, const seg &rhs) const{
        int l_len = (lhs.right - lhs.left) / 2;
        int r_len = (rhs.right - rhs.left) / 2;

        if (l_len != r_len)
            return l_len > r_len;
        else
            return lhs.left < rhs.left;
    }
};

int main()
{
    // [TODO 2] Initialization
    set<int> pos;//the position has person or not
    set<seg, cmp> segmt;//record every segment
    vector<int> id_pos;//who is in where

    int n, m, s;//num_of_seat, num_of_sdt, safe_dist
    cin >> n >> m >> s;
    //dist to record the shortest social distance
    int dist = n + 1;//the default social distance
    pos.insert(0);//wall
    pos.insert(n + 1);//wall
    id_pos.resize(m + 1, -1);//need m+1 new and value is all -1, -1 is no one sit
    segmt.insert(seg(0, n + 1));//oringinal situation

    char act;
    int idx;
    int ncases = 2 * m;
    // [TODO 3] Process student events
    while (ncases--)
    {
        cin >> act >> idx;
        if (act == 'i' ) {
            //the best segment is the front
            auto it = segmt.begin();
            //take the index of the boundary
            int left = it->left, right = it->right;
            //and the new position of the insert one
            int mid = (left + right) / 2;

            //renew the shortest social distance, left
           // cout << "first " << dist << endl;
            //cout << "min " << min(mid - left, dist) << endl;
            if (left != 0)
                dist = min(mid - left, dist);
            //cout << "try left " << dist << endl;
            if (right != n + 1)
                dist = min(right - mid, dist);
            //cout << "try right " << dist << endl;

            //update the segment
           // cout << left << "++" << mid << "++" << right << endl;

            segmt.erase(it);
            segmt.insert(seg(left, mid));
            segmt.insert(seg(mid, right));

            //update the other vector and set
            id_pos[idx] = mid;
            pos.insert(mid);

            
        }
        else if(act == 'o' ){

            

            //the position of the seat
            int mid = id_pos[idx]; //cout << "------" << mid << endl;
            //use it points to 
            auto it_l = pos.find(mid);
            //copy one for the right
            auto it_r = it_l;
            //the person sit aside
            int left = *(--it_l);
            int right = *(++it_r);

            //dist = min(dist,)
            // << "----" << mid << endl;
            
            segmt.erase(seg(left, mid));
            segmt.erase(seg(mid, right));
            segmt.insert(seg(left, right));

            id_pos[idx] = -1;
            pos.erase(mid);
            //cout << "dist " << dist << endl;
        }
    }
    
    // [TODO 4] Print the answer
    if (dist >= s)
        cout << "YES\n";
    else
        cout << "NO\n";
    if (dist == n + 1)
        cout << "INF\n";
    else
        cout << dist << "\n";

    return 0;
}
/*
9 3 5
i 1
i 2
o 1
i 3
o 2
o 3
*/
