#ifndef color_hcg_make_red
#define color_hcg_make_red

// ::color::make::red( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 1, 0, 0 } ) - rgb(255,0,0) - #FF0000

     template< typename tag_name >
      inline
      void red( ::color::model< ::color::category::hcg< tag_name > > & color_parameter )
       {
        typedef ::color::category::hcg< tag_name >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::hcg< double >      right_type;

        static left_type local( right_type( { 0.298839, 0.634344563039438, -1.88026376146789 } ) );

        color_parameter = local;
       }

    }
  }

#endif
