#include "..\src\functie.h"
#include "gtest/gtest.h"
#include <vector>


using namespace std;

class SortTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		v.push_back(3);
		v.push_back(2);
		v.push_back(1);
	}
	vector<int> v;
};

TEST_F(SortTest, Sort1)
{
	Sort(v);
	int i = 1;
	for(auto it : v)
	{
		EXPECT_EQ(i, it);
		i++;
	}
}
