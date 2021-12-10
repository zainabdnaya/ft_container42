#include "vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        private :
            Container c; 
        public :
            //value_type 
            typedef typename T value_type;
            // container_type 
            typedef typename Container container_type;
            // size_type
            typedef typename Container::size_type size_type;
            

            // Constructors
            explicit stack (const container_type& ctnr = container_type())
            : c(ctnr)
            {
            }
    }
}