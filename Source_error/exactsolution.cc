struct uexact: field_functor<uexact,point> {
  Float operator() (const point& x) const {
    return beta*pow(x[0],2)*pow((1.-x[0]),2)*pow(x[1],2)*pow((1.-x[1]),2);
  }
  uexact(Float beta1) : beta(beta1) {}
  Float beta;
};

struct vexact: field_functor<vexact,point> {
  Float operator() (const point& x) const {
    return 2.*beta*(pow(x[0],2)*pow((1.-x[0]),2)*(1.-6.*x[1]+6.*pow(x[1],2))+
		    pow(x[1],2)*pow((1.-x[1]),2)*(1.-6.*x[0]+6.*pow(x[0],2)));
  }
  vexact(Float beta1) : beta(beta1) {}
  Float beta;
};
