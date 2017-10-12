#include "Utility.h"
#include <unordered_map>

namespace utility
{
	bool containsDuplicates(std::vector<int> v)
	{
		std::unordered_map<int, bool> m;

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			int i = *it;
			if (m.find(i) != m.end())
				return true;
			else
				m[i] = true;
		}

		return false;
	}

	int countUniqueValues(std::vector<int> v)
	{
		std::unordered_map<int, bool> m;

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			int i = *it;
			m[i] = true;
		}

		return m.size();
	}
}