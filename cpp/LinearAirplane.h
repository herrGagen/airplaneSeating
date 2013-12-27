#ifndef LINEAR_AIRPLANE
#define LINEAR_AIRPLANE

#include <iostream>
#include <vector>

template<int N> class LinearAirplane;

template<int N>
std::ostream &operator<<(std::ostream&, LinearAirplane<N>&);

template<int N>
class LinearAirplane: public std::vector<std::string>
{

 private:

 public:
  int addFamily(const std::string &name, unsigned int numMembers);
  int addSingleton(unsigned int numSingletons);
  friend std::ostream & operator<< <>(std::ostream &, LinearAirplane<N> &);
  int scanToFindExchanges();
 private:

};

#endif
