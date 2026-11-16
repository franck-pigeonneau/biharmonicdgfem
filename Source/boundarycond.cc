struct g1: field_functor<g1,point> {
  Float operator() (const point& x) const {
    // if (x[0]<1.e-7) {
    //   return 1.;
    // }
    // else {
    //   return 0.;
    // }
    return 0.;
  }
};

struct g2: field_functor<g2,point> {
  Float operator() (const point& x) const { 
    return 0.;
  }
};
