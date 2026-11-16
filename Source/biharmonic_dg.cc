#include "rheolef.h"

/* Utilisation des classes cpp */
#include <iostream> // flux entrée/sortie
#include <fstream> // flux d'entrée/sortie dans des fichiers
#include <string> // Manipulation des chaines de caractères

/* Introduction des identificateurs des bibliotheques standard et rheolef */
using namespace std;
using namespace rheolef;

/* Introduction des fonctions */
#include "source.cc"
#include "boundarycond.cc"

/* Debut du programme principal */
int main(int argc, char** argv) {
  environment rheolef(argc,argv);

  /* Rappel de la forme d'appel du programme */
  if (argc < 3) {
    cout << "Appel de la fonction incorrecte" << endl;
    exit(0);
  }

  geo omega(argv[1]);
  space Xh(omega,argv[2]);

  size_t k=Xh.degree();
  size_t d=omega.dimension();
  Float alpha=(k+1.)*(k+d)/d;
  Float beta=100.;

  trial u(Xh),v(Xh);
  test p(Xh),q(Xh);

  /* Premiere ligne */
  form apv=integrate(v*p);
  form apu=integrate(dot(grad_h(u),grad_h(p)))-
           integrate("internal_sides",average(dot(grad_h(u),normal()))*jump(p))-
           integrate("sides",average(dot(grad_h(p),normal()))*jump(u));

  /* Deuxieme ligne */
  form aqu=integrate("sides",alpha*penalty()*jump(u)*jump(q));

  /* Second membre */
  field l1h=integrate("boundary",g2()*p-g1()*dot(grad_h(p),normal()));
  field l2h=integrate(f(beta)*q)+integrate("boundary",alpha*penalty()*g1()*q);

  // method with elimination of vh
  form_option_type fopt;
  fopt.invert = true;
  form inv_apv=integrate(v*p, fopt);
  form a = aqu+trans(apu)*(inv_apv*apu);
  field lh = -l2h+ apu.trans_mult(inv_apv*l1h);
  solver sa (a.uu());
  field uh(Xh,0.);
  uh.set_u() = sa.solve (lh.u());
  field vh(Xh,0.);
  vh = inv_apv*(l1h-apu*uh);

  /* Sortie des champs dans le fichier field */
  dout << catchmark("u") << uh
       << catchmark("v") << vh;
}
