/*
Runtime: 4 ms, faster than 91.16% of C++ online submissions 
Memory Usage: 5.9 MB, less than 91.92% of C++ online submissions
*/
int countVowelPermutation(int n) {
      array<int,5> count = {1,1,1,1,1}; // a,e,i,o,u
      array<int,5> pre_count = {0};
      int modulo_base = (int)(pow(10,9)+7);
      for(int step=2; step<=n; step++){
          /*cout << step << " ";
          for(int i=0; i<5; i++){
              count[i] = count[i];
              cout<< count[i] << " ";
          }
          cout << endl;*/
          pre_count.swap(count);
          count[0] = (pre_count[1] + pre_count[2])%modulo_base;
          count[0] = (count[0] + pre_count[4])%modulo_base;
          count[1] = (pre_count[0] + pre_count[2])%modulo_base;
          count[2] = (pre_count[1] + pre_count[3])%modulo_base;
          count[3] = pre_count[2]%modulo_base;
          count[4] = (pre_count[2] + pre_count[3])%modulo_base;
      }

      int total = 0;
      for(size_t i=0; i<5; i++)
          total = (total + count[i])%modulo_base;

      return total;
 }
