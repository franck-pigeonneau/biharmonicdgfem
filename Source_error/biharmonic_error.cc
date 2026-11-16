#include "rheolef.h"
using namespace rheolef;
using namespace std;

#include "exactsolution.cc"

int main (int argc, char **argv) {
  environment rheolef (argc,argv);

  Float beta=100.;

  /* Pick up of the numerical solution */
  field uh,vh;
  din >> catchmark("u") >> uh
      >> catchmark("v") >> vh;

  /* Space and polynomial order */
  space Xh=uh.get_space();
  size_t k=Xh.degree();

  /* Determination of the interpolation of the exact solution */
  field piuh=interpolate(Xh,uexact(beta));
  field pivh=interpolate(Xh,vexact(beta));

  /* Error fields */
  field eh_u=uh-piuh;
  field eh_v=vh-pivh;

  /* Bilinear forms */
  trial u(Xh);
  test v(Xh);
  form norml2=integrate(u*v);
  form normh1dG=integrate(dot(grad_h(u),grad_h(v)))+integrate("sides",(h_local()/pow(k,2))*average(dot(grad_h(u),normal()))*
							      average(dot(grad_h(v),normal())))+
                integrate("internal_sides",(k*k/h_local())*jump(u)*jump(v));

  /* Determination of errors */
  dout << sqrt(norml2(eh_u,eh_u)) << "  " << sqrt(normh1dG(eh_u,eh_u)) << "  "
       << sqrt(norml2(eh_v,eh_v)) << "  " << sqrt(normh1dG(eh_v,eh_v)) << endl;

}
