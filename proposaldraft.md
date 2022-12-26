---
title: Project Proposal
author: Kian Abeywick
---

_Question:_ can a Monte Carlo Renormalization Group (MCRG) model with 
position-based constraint handling demonstrate a continuous crumpling transition 
in a 2D polymerized (crystalline) membrane?

In this proposed project I would be addressing the crumpling transition of a 
polymerized membrane (a set of vertices linked together in a lattice mesh 
forming a 2D surface in 3D space). The simplest example of this system is the 
"phantom" model which ignores self-avoidance effects. The phantom model is 
reasonably well understood, and mean field approaches predict a continuous 
transition between a low temperature "flat phase" and a high temperature 
"crumpled phase" [^1] [^3]

The problem is less well understood when self-avoidance effects are included. 
Although self-avoidance is negligible in the low temperature flat phase, for 
high temperatures the analytic and numerical approaches give opposing results in 
their predictions of the transition. Both Landau theory and the renormalization 
group ε-expansion allow a crumpled phase with ν ≃ 1 [^5]. But most numerical 
simulations do not show the emergence of a crumpled phase at all, with the 
membrane instead remaining in the flat phase. [^2][^3][^6]

My goal here is to attempt to reconcile the analytic and numerical predictions, 
and devise a numerical model of the polymerized membrane that allows for emergence 
of the crumpled phase. It is suggested that the reason numerical simulations 
remain flat is the use of hard-core repulsive potentials to model 
self-avoidance, which end up inducing extra rigidity to the membrane even 
when the external rigidity κ is zero [^6]. Bowick [^3] and Gompper [^6] both 
suggest using atrractive potentials instead of hard core repulsive potentials as 
this shows the most promise in overcoming the induced rigidity.

My approach will be to use the MCRG framework and combine an attractive 
potential with an iterative constraint projection method inspired by Muller 
[^7]. This scheme involves treating the membrane as a set of particles and a 
corresponding set of constraint functions -- in this case fixed distance 
constraints with an optional stiffness parameter -- that enforce the geometry of 
the mesh. At each time step fluctuations cause particles move to new 
configurations that may violate the constraint functions; these violations are 
detected and a small correction factor to the particle's position is computed 
and iteratively applied via the Gauss-Seidel method until the system reaches a 
new configuration that satisfies the constraints [^7]. Although this method is 
used mainly in modeling elastic deformations, it's useful in this context as 
it's stable and it conserves energy and momentum. This method should make the 
mesh more elastic, which should allow the long range forces to prevail near the 
transition.  Computing the phase diagram, critical exponents, and radius of 
gyration should give an indication of the suitability of such a model. 

---

[^1] Paczuski, Kardar, Nelson, "Landau Theory of the Crumpling Transition", 
Physical Review Letters 2638-2640 (1988)

[^2] Abraham, Nelson, "Fluctuations in the flat and collapsed phase of 
polymerized surfaces", J. Phys. (France), 51:2653, 1990.

[^3] M. Bowick, A. Travessat, "The Statistical Mechanics of Membranes", Phys. 
161 (2000).

[^4] P.G. de Gennes, Scaling Concepts in Polymers Physics, Cornell University 
Press, Ithaca, NY, 1979. 

[^5] K.J. Wiese, F. David, "New Renormalization Group Results for Scaling of 
Self-Avoiding Membranes", Nucl. Phys. B, 487:529, 1997

[^6] G. Gompper, D. M. Kroll, "Fluctuations of polymerized, fluid and hexatic 
membranes: continuum models and simulations", Current Opinion in Colloid & 
Interface Science, 1997.

[^8] Muller, Heidelberger, Hennix, Ratcliff, "Position Based Dynamics", Journal 
of Visual Communication and Image Representation, Volume 18, Issue 2, 109:118 
(2007).
