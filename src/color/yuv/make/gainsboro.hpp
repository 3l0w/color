#ifndef color_yuv_make_gainsboro
#define color_yuv_make_gainsboro

// ::color::make::gainsboro( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.858824, 0.858824, 0.858824 } ) - rgb(219,219,219) - #DBDBDB

     template< typename tag_name >
      inline
      void gainsboro( ::color::model< ::color::category::yuv< tag_name > > & color_parameter )
       {
        typedef ::color::category::yuv< tag_name >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::yuv< double >      right_type;

        static left_type local( right_type( { 0.858823529, -5.55111512E-17, -1.11022302E-16 } ) );

        color_parameter = local;
       }

    }
  }

#endif
