# Numerical solution of a biharmonic equation by a discontinuous Galerkin method

## Constitution du répertoire

The current directory contains the following directories:

Doc: LaTeX document that generates the validation document.
Mesh: .geo mesh files.
Source: source files for solving the problem.
Source_error: source files for calculating errors.

## Running of a case

biharmonic_dg nomgeo.geo degreepoly > nomfichier.field

Example: biharmonic_dg square-16x16.geo P2d > 16x16/square-16x16-P2d.field

## Error computation


biharmonic_error < nomfichier.field

Example: biharmonic_error < 16x16/square-16x16-P2d.field
