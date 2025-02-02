#ifndef color_cmy_convert_yiq
#define color_cmy_convert_yiq

#include "../category.hpp"

#include "../../_internal/convert.hpp"

#include "../../yiq/constant.hpp"
#include "../../yiq/category.hpp"
#include "../../yiq/trait/container.hpp"

#include "../place/place.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"


namespace color
 {
  namespace _internal
   {

    template< typename cmy_tag_name, typename yiq_tag_name >
     struct convert
      <
        ::color::category::cmy< cmy_tag_name >
       ,::color::category::yiq<yiq_tag_name>
      >
      {
       public:
         typedef ::color::category::cmy< cmy_tag_name > category_left_type;
         typedef ::color::category::yiq<yiq_tag_name> category_right_type;
         typedef typename ::color::trait::scalar<category_left_type>::instance_type  scalar_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         typedef ::color::constant::yiq< category_right_type > yiq_const_type;

         typedef ::color::_internal::diverse< category_left_type >    diverse_type;
         typedef ::color::_internal::normalize< category_right_type > normalize_type;

         enum
          {
               cyan_p  = ::color::place::_internal::cyan<category_left_type>::position_enum
           ,magenta_p  = ::color::place::_internal::magenta<category_left_type>::position_enum
           , yellow_p  = ::color::place::_internal::yellow<category_left_type>::position_enum
          };

         enum
          {
                  luma_p  = ::color::place::_internal::luma<category_right_type>::position_enum
           ,   inphase_p  = ::color::place::_internal::inphase<category_right_type>::position_enum
           ,quadrature_p  = ::color::place::_internal::quadrature<category_right_type>::position_enum
          };

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
           static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
           static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();

           scalar_type y = normalize_type::template process<      luma_p>( container_right_trait_type::template get<      luma_p>( right ) );
           scalar_type i = normalize_type::template process<   inphase_p>( container_right_trait_type::template get<   inphase_p>( right ) );
           scalar_type q = normalize_type::template process<quadrature_p>( container_right_trait_type::template get<quadrature_p>( right ) );

           i = yiq_const_type::i_diverse( i );
           q = yiq_const_type::q_diverse( q );

           scalar_type r = a11 * y + a12 * i + a13 * q;
           scalar_type g = a21 * y + a22 * i + a23 * q;
           scalar_type b = a31 * y + a32 * i + a33 * q;

           container_left_trait_type::template set<    cyan_p>( left, diverse_type::template process<   cyan_p>( scalar_type(1) - r ) );
           container_left_trait_type::template set< magenta_p>( left, diverse_type::template process<magenta_p>( scalar_type(1) - g ) );
           container_left_trait_type::template set<  yellow_p>( left, diverse_type::template process< yellow_p>( scalar_type(1) - b ) );
          }
      };

   }
 }

#endif
