#ifndef color_hsi_convert_gray
#define color_hsi_convert_gray

#include "../category.hpp"
#include "../place/place.hpp"

#include "../../_internal/convert.hpp"
#include "../../gray/gray.hpp"

#include "../../_internal/reformat.hpp"





namespace color
 {
  namespace _internal
   {

    template< typename hsi_tag_name, typename gray_tag_name >
     struct convert
      <
        ::color::category::hsi< hsi_tag_name >
       ,::color::category::gray<   gray_tag_name >
      >
      {
       public:
         typedef ::color::category::hsi<   hsi_tag_name > category_left_type;
         typedef ::color::category::gray< gray_tag_name > category_right_type;
         typedef typename ::color::trait::scalar<category_left_type>::instance_type scalar_type;

         typedef ::color::trait::bound<category_left_type>         bound_left_trait_type;
         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type >    reformat_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         enum
          {
            gray_p       = ::color::place::_internal::gray<category_right_type>::position_enum
          };

         enum
          {
            hue_p        = ::color::place::_internal::hue<category_left_type>::position_enum
           ,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
           ,intensity_p  = ::color::place::_internal::intensity<category_left_type>::position_enum
          };

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           container_left_trait_type::template set<hue_p>(        left, bound_left_trait_type::template minimum<hue_p>() );
           container_left_trait_type::template set<saturation_p>( left, bound_left_trait_type::template minimum<saturation_p>() );
           container_left_trait_type::template set<intensity_p>(  left, reformat_type::template process<intensity_p,0>( container_right_trait_type::template get<0>( right ) ) );
          }
      };

   }
 }

#endif
