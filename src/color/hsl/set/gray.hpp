#ifndef color_hsl_set_gray
#define color_hsl_set_gray

// ::color::set::gray( c, val )

#include "../../gray/akin/hsl.hpp"
#include "../../gray/trait/component.hpp"
#include "../../gray/constant.hpp"

#include "../category.hpp"

#include "../../_internal/normalize.hpp"

#include "../../generic/trait/scalar.hpp"

 namespace color
  {
   namespace set
    {

     template< typename tag_name >
      inline
      void
      gray
       (
         ::color::_internal::model< ::color::category::hsl<tag_name> >                               & color_parameter
        ,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsl<tag_name> >::akin_type  >::input_const_type         component_parameter
       )
       {
        typedef ::color::category::hsl<tag_name> category_type;
        typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
        typedef typename ::color::akin::gray< category_type >::akin_type     akin_type;

        typedef ::color::_internal::normalize< category_type > normalize_hsl_type;
        typedef ::color::_internal::normalize< akin_type >     normalize_akin_type;

        typedef  ::color::constant::gray< akin_type > gray_const_type;

        scalar_type value = // TODO
             gray_const_type::Rc() * normalize_hsl_type::template process<0>( color_parameter.template get<0>() )
           + gray_const_type::Gc() * normalize_hsl_type::template process<1>( color_parameter.template get<1>() )
           + gray_const_type::Bc() * normalize_hsl_type::template process<2>( color_parameter.template get<2>() );

        value = normalize_akin_type::template process<0>( component_parameter ) / value;

        ::color::operation::scale( color_parameter, value );
       }


    }
  }

#endif
