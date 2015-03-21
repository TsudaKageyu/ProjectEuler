#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() 
{
int64_t answer = 0;

for (int32_t n = 2; n < 10000000; ++n)
{
   int32_t tmp = n;

   while (true)
   {
   int32_t sum = 0;

   while (tmp != 0)
   {
        sum += (tmp % 10) * (tmp % 10);
        tmp /= 10;
   }

   if (sum == 89 || sum == 1)
   {
      if (sum == 89)
          answer++;

      break;
   }

       tmp = sum;
   }
}

cout << answer << endl;
return 0;
}
