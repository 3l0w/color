#ifndef color_hwb_convert_xyz
#define color_hwb_convert_xyz

#include "../../_internal/convert.hpp"

#include "../category.hpp"
#include "../place/place.hpp"


#include "../../xyz/xyz.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"


namespace color
 {
  namespace _internal
   {

    template
     <
       typename hwb_tag_name
      ,typename xyz_tag_name
     >
     struct convert
      <
        ::color::category::hwb<  hwb_tag_name >
       ,::color::category::xyz<  xyz_tag_name >
      >
      {
       public:

         typedef ::color::category::hwb< hwb_tag_name >    hwb_category_type, category_left_type;
         typedef ::color::category::xyz< xyz_tag_name >    xyz_category_type, category_right_type;

         typedef typename ::color::trait::scalar< hwb_category_type >::instance_type scalar_type;

         typedef ::color::model< hwb_category_type > hwb_model_type;
         typedef ::color::model< xyz_category_type >  xyz_model_type;

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
           left = hwb_model_type( hsv_model_type( rgb_model_type( xyz_model_type( right ) ) ) ).container();
          }


        };

   }
 }

#endif
