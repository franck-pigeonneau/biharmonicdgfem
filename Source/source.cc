struct f: field_functor<f,point> {
  Float operator() (const point& x) const {
    Float ax=1.-6.*x[0]+6.*pow(x[0],2);
    Float ay=1.-6.*x[1]+6.*pow(x[1],2);
    Float bx=3.*pow(x[0],2)*pow((1.-x[0]),2);
    Float by=3.*pow(x[1],2)*pow((1.-x[1]),2);

    return -8.*beta*(ax*ay+bx+by);
  }
  f(Float beta1) : beta(beta1) {}
  Float beta;
};

struct f2: field_functor<f2,point> {
  Float operator() (const point& x) const {
    Float ax=1.-6.*x[0]+6.*pow(x[0],2);
    Float ay=1.-6.*x[1]+6.*pow(x[1],2);
    Float bx=3.*pow(x[0],2)*pow((1.-x[0]),2);
    Float by=3.*pow(x[1],2)*pow((1.-x[1]),2);

    return -8.*pow(M_PI,4)*(cos(2.*M_PI*x[0])*cos(2.*M_PI*x[1])-
			    cos(2.*M_PI*x[0])*pow(sin(M_PI*x[1]),2)-
			    cos(2.*M_PI*x[1])*pow(sin(M_PI*x[0]),2));
  }
};
