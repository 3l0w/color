#ifndef color_YPbPr_make_sienna
#define color_YPbPr_make_sienna

// ::color::make::sienna( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.627451, 0.321569, 0.176471 } ) - rgb(160,82,45) - #A0522D

     template< typename tag_name >
      inline
      void sienna( ::color::model< ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_601_entity > > & color_parameter )
       {
        typedef ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_601_entity >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::YPbPr< double, ::color::constant::YPbPr::BT_601_entity >      right_type;

        static left_type local( right_type( { 0.396386243, 0.375836988, 0.664739388 } ) );

        color_parameter = local;
       }

     template< typename tag_name >
      inline
      void sienna( ::color::model< ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_709_entity > > & color_parameter )
       {
        typedef ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_709_entity >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::YPbPr< double, ::color::constant::YPbPr::BT_709_entity >      right_type;

        static left_type local( right_type( { 0.396386243, 0.375836988, 0.664739388 } ) );

        color_parameter = local;
       }

     template< typename tag_name >
      inline
      void sienna( ::color::model< ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_2020_entity > > & color_parameter )
       {
        typedef ::color::category::YPbPr< tag_name, ::color::constant::YPbPr::BT_2020_entity >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::YPbPr< double, ::color::constant::YPbPr::BT_2020_entity >      right_type;

        static left_type local( right_type( { 0.396386243, 0.375836988, 0.664739388 } ) );

        color_parameter = local;
       }

    }
  }

#endif
