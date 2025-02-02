#ifndef color_cmy_convert_hwb
#define color_cmy_convert_hwb

#include "../../_internal/convert.hpp"

#include "../category.hpp"


#include "../../hwb/hwb.hpp"
#include "../../rgb/rgb.hpp"
#include "../../hsv/hsv.hpp"




namespace color
 {
  namespace _internal
   {

    template
     <
       typename cmy_tag_name
      ,typename hwb_tag_name
     >
     struct convert
      <
        ::color::category::cmy<  cmy_tag_name >
       ,::color::category::hwb< hwb_tag_name >
      >
      {
       public:
         typedef ::color::category::cmy< cmy_tag_name >    cmy_category_type,  category_left_type;
         typedef ::color::category::hwb< hwb_tag_name >    hwb_category_type, category_right_type;

         typedef typename ::color::trait::scalar< cmy_category_type >::instance_type scalar_type;

         typedef ::color::model<   cmy_category_type >      cmy_model_type;
         typedef ::color::model<   hwb_category_type >      hwb_model_type;

         typedef ::color::rgb< scalar_type >  rgb_model_type;
         typedef ::color::hsv< scalar_type >  hsv_model_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           left = cmy_model_type( rgb_model_type ( hsv_model_type( hwb_model_type( right ) ) ) ).container();
          }
      };

   }
 }

#endif
