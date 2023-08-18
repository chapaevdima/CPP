#include "PmergeMe.hpp"

void vectorSort(std::vector<int>& inv)
{
    if(inv.size() <= 1)
        return;
    if (inv.size() > 50)
    {
        std::vector<int>::iterator midIter = inv.begin() + ((inv.size())/2);

        std::vector<int> v1(inv.begin(), midIter), v2(midIter, inv.end());

        vectorSort(v1);
        vectorSort(v2);
                
        std::vector<int>::iterator it1 = v1.begin(), it2 = v2.begin();

        unsigned int i = 0;
        while((it1 != v1.end() && it2 != v2.end()))
        {
            if(*it1 < *it2)
                inv[i] = *(it1++);
            else
                inv[i] = *(it2++);
            i++;
        }

		while (it1 != v1.end())
			inv[i++] = *(it1++);

		while (it2 != v2.end())
			inv[i++] = *(it2++);		
		
    } else
    {
        unsigned int i = 0, j = 0;
		bool flag = true;
        while(i < inv.size() - 1)
        {
            if(inv[i] > inv[i+1])
            {
				if(flag)
					j = i;
				flag = false;
                int tmp = inv[i];
                inv[i] = inv[i + 1];
	            inv[i + 1] = tmp;
	            if(i != 0)
	                i--;
	        } else
	        {
                if (!flag)
				    i = j;
				flag = true;
                i++;
			} 
	    }
    }
}

void listSort(std::list<int>& inl)
{
    if(inl.size() <= 1)
		return;
	if(inl.size() > 60)
	{
		std::list<int>::iterator midIter = inl.begin(), fastIter = inl.begin();

		while(fastIter != inl.end() && ++fastIter != inl.end())
		{
			++midIter;
			++fastIter;
		}

		std::list<int> l1;
		std::list<int> l2;
		l1.insert(l1.end(), inl.begin(), midIter);
		l2.insert(l2.end(), midIter, inl.end());

		listSort(l1);
		listSort(l2);

		std::list<int>::iterator it = inl.begin(), it1 = l1.begin(), it2 = l2.begin();
		while(it1 != l1.end() && it2 != l2.end())
		{
			if(*it1 < *it2)
				*(it++) = *(it1++);
			else
				*(it++) = *(it2++);
		}

		while(it1 != l1.end())
			*(it++) = *(it1++);
		while(it2 != l2.end())
			*(it++) = *(it2++);
	}
	else
	{
		std::list<int>::iterator it2 = inl.begin(), it1 = it2++, sorted = inl.begin();
		while (it2 != inl.end())
		{
			if(*it2 < *it1)
			{
				while(*it1 > *it2 && it1 != inl.begin())
					it1--;
				sorted = --it2;
				it2++;
				if(*it1 < *it2)
					it1++;
				inl.insert(it1, *it2);
				inl.erase(it2);
				it2 = sorted;
				it1 = it2++;
			} else
			{
				++it1;
				++it2;
			}
		}
		
	}
}