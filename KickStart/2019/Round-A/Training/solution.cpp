/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*{{{ First try: Time Limit Exceeded. (Brute Force) */
// int main()
// {
//   int T; cin >> T;
//   for (int i = 1; i <= T; ++i) {
//     int N, P;
//     cin >> N >> P;
//     vector<int> stds (N);
//     for (int j = 0; j < N; ++j) {
//       cin >> stds[j];
//     }
//     sort(stds.begin(), stds.end());
//     int ans = 0x3f3f3f3f;
//     for (int m = 0; m <= N - P; ++m) {
//       int tmp = 0, hi = stds[m + P - 1];
//       for (int k = m; k < m + P; ++k) {
//         tmp += (hi - stds[k]);
//       }
//       ans = min(tmp, ans);
//     }
//     cout << "Case #" << i << ": " << ans << "\n";
//   }
//   return 0;
// }
/*}}}*/

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, P;
    cin >> N >> P;

    vector<int> stds (N);
    for (int j = 0; j < N; ++j) {
      cin >> stds[j];
    }

    // NOTE: O(Nlog(N))
    sort(stds.begin(), stds.end());

    int pre = 0;
    for (int kk = 0; kk < P - 1; ++kk) {
      pre += (stds[P - 1] - stds[kk]);
    }

    int diff = stds[P - 1] - stds[0];
    int ans  = pre;

    // NOTE: O(N - P)
    for (int m = 1; m <= N - P; ++m) {
      int tmp = pre - diff, hi = stds[m + P - 1];
      diff = hi - stds[m];
      tmp += ((stds[m + P - 1] - stds[m + P - 2]) * (P - 1));
      ans  = min(tmp, ans);
      pre  = tmp;
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }

  return 0;
}
