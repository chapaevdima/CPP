#include "PmergeMe.hpp"

void vectorSort(std::vector<int>& inv)
{
    if(inv.size() == 1)
        return;
    if (inv.size() > 10)
    {
        std::vector<int>::iterator midIter = inv.begin() + ((inv.size())/2);

        std::vector<int> v1(inv.begin(), midIter);
        std::vector<int> v2(midIter, inv.end());

        vectorSort(v1);
        vectorSort(v2);
                
        std::vector<int>::iterator it1 = v1.begin();
        std::vector<int>::iterator it2 = v2.begin();

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
				i = j;
				flag = true;
			} 
	    }
    }
}

void listSort(std::list<int>& inl)
{
    (void) inl;
}