#ifndef GTEST_SAMPLES_MYFIRSTPROJECT_INL_H_
#define GTEST_SAMPLES_MYFIRSTPROJECT_INL_H_

#include <stddef.h>

#include <initializer_list>
#include <vector>

using namespace std;

template <typename T>
void Sort(vector<T>& List)
{
	for (int i = 0; i < List.size() - 1 ; i++)
		for (int j = i + 1; j < List.size(); j++)
			if (List[i] > List[j])
			{
				T aux = List[i];
				List[i] = List[j];
				List[j] = aux;
			}
}

#endif  // GTEST_SAMPLES_SAMPLE3_INL_H_
