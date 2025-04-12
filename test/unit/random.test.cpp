/**
 * author:  _Berlin_
 * Description: Unit tests for utils/random.h
 */

 #include "../../include/utils/random.h"
 #include "../core/BerlinTestBase.h"
 #include "../core/BerlinTestRegister.h"
 #include <unordered_set>
 
 class TestRandomUtils : public BerlinTestBase {
 public:
   TestRandomUtils() : BerlinTestBase("TestRandomUtils") {}
 
   void run(int id) override {
     using namespace berlin_rand;
 
     switch (id) {
       case 0: {
         int64_t val = randint(1, 100);
         check(val >= 1 && val <= 100, true, "randint out of bounds");
         break;
       }
       case 1: {
         int64_t val = randrange(10, 20);
         check(val >= 10 && val < 20, true, "randrange out of bounds");
         break;
       }
       case 2: {
         double r = randreal(1.5, 3.5);
         check(r >= 1.5 && r < 3.5, true, "randreal out of bounds");
         break;
       }
       case 3: {
         auto vec = randset(10, 100, 20);
         check((int)vec.size(), 20, "randset size incorrect");
         std::unordered_set<int64_t> s(vec.begin(), vec.end());
         check((int)s.size(), 20, "randset contains duplicates");
         break;
       }
       case 4: {
         std::vector<int> a = {1, 2, 3, 4, 5};
         randshuffle(a);
         std::sort(a.begin(), a.end());
         check(a, std::vector<int>({1, 2, 3, 4, 5}), "randshuffle altered elements");
         break;
       }
     }
   }
 
   int getCaseCount() const override { return 5; }
 };
 
 BERLIN_REGISTER_TEST(TestRandomUtils);