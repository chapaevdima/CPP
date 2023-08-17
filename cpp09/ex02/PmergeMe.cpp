#include "PmergeMe.hpp"

void vectorSort(std::vector<int>& inv)
{
    if(inv.size() == 1)
        return;
    if (inv.size() > 10)
    {
        std::vector<int>::iterator midIter = inv.begin() + ((inv.size())/2);
        //std::cout << *midIter << std::endl;

        std::vector<int> v1(inv.begin(), midIter);
        std::vector<int> v2(midIter, inv.end());

        

        vectorSort(v1);
        vectorSort(v2);
        
        for (unsigned int i = 0; i < v1.size(); i++)
            std::cout << v1[i] << " ";
        std::cout << std::endl;

        for (unsigned int i = 0; i < v2.size(); i++)
            std::cout << v2[i] << " ";
        std::cout << std::endl;

        
        /*std::vector<int>::iterator it1 = v1.begin();
        std::vector<int>::iterator it2 = v2.begin();

        unsigned int i = 0;
        while(it1 != v1.end() || it2 != v2.end())
        {
            if(it1 != v1.end() && *it1 < *it2)
                inv[i] = *(it1++);
            else
                inv[i] = *(it2++);
            i++;
        }*/
    }

    unsigned int i = 0;
    while(i < inv.size() - 1)
    {
        if(inv[i] > inv[i+1])
        {
            int tmp = inv[i];
            inv[i] = inv[i + 1];
            inv[i + 1] = tmp;
            if(i != 0)
                i--;
        } else
            i++;
    }

}

void listSort(std::list<int>& inl)
{
    (void) inl;
}