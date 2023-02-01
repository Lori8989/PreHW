#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct seg {
    int left, right;
    seg( int a, int b)
        :left(a),right(b){}
};

struct cmp {
  bool operator()(const seg &lhs, const seg &rhs) const {
    int l_len = (lhs.right - lhs.left) / 2;
    int r_len = (rhs.right - rhs.left) / 2;
    if (l_len != r_len)
            return l_len < r_len;
        else
            return lhs.left < rhs.left;
  }
};

int main() {
  char act;
  int n, m, s, idx, dist;
  set<int> pos;
  set<seg, cmp> segmt;
  vector<int> id_pos;

  cin >> n >> m >> s;
  dist = n + 1;
  id_pos.resize(m + 1, -1);
  pos.insert(0);
  pos.insert(n + 1);
  segmt.insert(seg(0, n + 1));

  for (int t = 0; t < 2 * m; t++) {
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

            auto iit = segmt.begin();
            int lleft = iit->left, rright = iit->right;
            int midd = (lleft + rright) / 2;
            //cout << lleft << "**" << midd << "**" << rright << endl;
        }
     else if (act == 'o') {
       //the position of the seat
            int mid = id_pos[idx]; //cout << "------" << mid << endl;
            //use it points to
            auto it_l = pos.find(mid);
            //copy one for the right
            auto it_r = it_l;
            //the person sit aside
            int left = *(--it_l);
            int right = *(++it_r);

//cout<<left<<"*"<<mid<<"*"<<right<<endl;
      segmt.erase(seg(left, mid));
            segmt.erase(seg(mid, right));
            segmt.insert(seg(left, right));

            id_pos[idx] = -1;
            pos.erase(mid);
            //cout << "dist " << dist << endl;

            auto itt = segmt.begin();
            auto leftt = itt->left, rightt = itt->right;
            mid = (leftt + rightt) / 2;

//cout << "D* " << D << endl;
    }
  }

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
