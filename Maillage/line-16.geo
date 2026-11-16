#!geo

mesh
4
header
 dimension 1
 nodes	17
 edges	16
end header

0
0.0625
0.125
0.1875
0.25
0.3125
0.375
0.4375
0.5
0.5625
0.625
0.6875
0.75
0.8125
0.875
0.9375
1

e	p1 0 1
e	p1 1 2
e	p1 2 3
e	p1 3 4
e	p1 4 5
e	p1 5 6
e	p1 6 7
e	p1 7 8
e	p1 8 9
e	p1 9 10
e	p1 10 11
e	p1 11 12
e	p1 12 13
e	p1 13 14
e	p1 14 15
e	p1 15 16


domain
boundary
2 0 2
0
16

domain
left
2 0 1
0

domain
right
2 0 1
16
