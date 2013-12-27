#include "LinearAirplane.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

template<int N>
std::ostream & operator<<(std::ostream & out, LinearAirplane<N> &obj)
{
  out << "Num members\t" << obj.size() << std::endl;
  for(int i = 0; i<obj.size(); i++)
    {
      out << "(" << i << ", " << obj[i] << ")\t";
      if(i%5 == 4)
        {
          out << std::endl;
        }
    }
  out << std::endl;
}

/**
   \brief Adds a family to our linear airplane.

   Seats a family named "name" with numMembers people at the end of our plane.

   \param name The family name (singleton is reserved and special)
   \param numMembers How many people are in this family.

   \retval 0 Proper execution.
   \retval 1 Attempted to insert a family named "singleton"
   \retval 2 Attempted to insert a family whose size was too large.
 */
template<int N>
int LinearAirplane<N>::addFamily(const std::string &name, unsigned int numMembers)
{
  if(name == "singleton")
    {
      return 1;
    }
  unsigned int numToInsert = (numMembers <= N ? numMembers : N);
  insert(end(), numToInsert, name);
  if(numToInsert == numMembers)
    {
      return 0;
    }
  else
    {
      return 2;
    }
}

/**
   \brief Adds a number of singletons to our linear airplane.

   Seats numSingletons unpairable passengers at the end of our plane.

   \param numSingletons How many singletons to insert.
   \retval 0 Proper execution.
 */
template<int N>
int LinearAirplane<N>::addSingleton(unsigned int numSingletons)
{
  insert(end(), numSingletons, "singleton");
  return 0;
}

template<>
int LinearAirplane<2>::scanToFindExchanges()
{



}


int main()
{
  LinearAirplane<2> test;
  test.addFamily("a",2);
  test.addFamily("b",2);
  test.addFamily("c",2);
  test.addFamily("d",2);
  test.addFamily("singleton",10);
  test.addSingleton(10);
  std::cout << test << std::endl;
}

