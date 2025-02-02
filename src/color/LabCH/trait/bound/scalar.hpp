#ifndef color__internal_LabCH_bound_scalar
#define color__internal_LabCH_bound_scalar

// ::color::_internal::LabCH::bound::scalar< index_type, scalar_name >


#include "../../../_internal/utility/type/traitc.hpp"
#include "../../../_internal/utility/type/index.hpp"



namespace color
 {
  namespace _internal
   {
    namespace LabCH
     {
      namespace bound
       {

        template< typename index_name, typename scalar_name >
         struct scalar
          {
           public:
             typedef scalar_name  scalar_type;
             typedef index_name  index_type;

             typedef ::color::_internal::lab::bound::scalar< index_type, scalar_name > lab_bound_type;

             typedef ::color::_internal::utility::type::traitC< scalar_type >   scalar_trait_type;
             typedef ::color::_internal::utility::type::index< index_type >    index_trait_type;

             typedef typename scalar_trait_type::instance_type          scalar_instance_type;
             typedef typename scalar_trait_type::return_image_type      return_image_type;

             typedef typename index_trait_type::instance_type    index_instance_type;
             typedef typename index_trait_type::input_const_type index_input_const_type;

             typedef ::color::_internal::LabCH::bound::scalar< index_type, scalar_name > this_type;

             static scalar_instance_type c_max()
              {
               scalar_instance_type a = std::max<scalar_instance_type>( fabs( lab_bound_type::template minimum<1>() ), lab_bound_type::template maximum<1>() );
               scalar_instance_type b = std::max<scalar_instance_type>( fabs( lab_bound_type::template minimum<2>() ), lab_bound_type::template maximum<2>() );
               return sqrt( a*a+b*b );
              }

             template< index_instance_type index >
              static /*constexpr*/ return_image_type   maximum( )
               {
                static scalar_instance_type max_list[] = { 100, this_type::c_max(), 360 };
                return max_list[index];
               }

             static /*constexpr*/ return_image_type   maximum( index_input_const_type  index )
              {
                static scalar_instance_type max_list[] = { 100, this_type::c_max(), 360 };
                return max_list[index];
              }

             template< index_instance_type index >
              static /*constexpr*/ return_image_type   minimum( )
               {
                static scalar_instance_type min_list[] = { 0, 0, 0 };
                return min_list[index];
               }

             static /*constexpr*/ return_image_type   minimum( index_input_const_type  index )
              {
                static scalar_instance_type min_list[] = { 0, 0, 0 };
                return min_list[index];
              }

             template< index_instance_type index >
              static /*constexpr*/ return_image_type   range()
               {
                static scalar_instance_type range_list[] = { 100, this_type::c_max(), 360 };
                return range_list[index];
               }

             static /*constexpr*/ return_image_type   range(   index_input_const_type  index )
              {
                static scalar_instance_type range_list[] = { 100, this_type::c_max(), 360 };
                return range_list[index];
              }
          };

       }
     }
   }
 }

#endif
