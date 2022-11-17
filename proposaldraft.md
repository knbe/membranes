---
title: Project Proposal
author: Kian Abeywick
---

Question: can a Monte Carlo Renormalization Group model with position-based constraint handling demonstrate a continuous crumpling transition in a 2D polymerized (crystalline) membrane?

In this proposed project I would be addressing the crumpling transition of a polymerized membrane (a set of vertices linked together in a lattice mesh forming a 2D surface in 3D space). The simplest example of this system is the "phantom" model which ignores self-avoidance effects. The phantom model is reasonably well understood, and mean field approaches predict a continuous transition between a low temperature "flat phase" and a high temperature "crumpled phase" [1] [3], with various numerical methods agreeing with these predictions. []

The problem is less well understood when self-avoidance effects are included. Although self-avoidance is negligible in the low temperature flat phase, for high temperatures the analytic and numerical approaches give opposing results in their predictions of the transition. Landau theory allows a crumpled phase via the Flory approximation, which gives a size exponent nu = 4/5 [1] [4]. A renormalization group ε-expansion to lowest order also predicts a crumpled phase with nu close to 1 [5]. Numerical simulations however do not show the emergence of a crumpled phase, with the membrane remaining in the flat phase, many concluding that self-avoidance eliminates the crumpled phase.

My goal here is to attempt to reconcile the analytic and numerical predictions, and devise a numerical model of the polymerized membrane that allows emergence of the crumpled phase. It is suggested that the reason numerical simulations remain flat is the use of hard-core repulsive potentials to model self-avoidance, which end up inducing a bending rigidity to the membrane even when the external rigidity κ is zero [6]. 

My approach is to use a Monte Carlo molecular simulation. [3] and [6] both suggest the use of attractive potentials shows the most promise in overcoming the induced bending rigidity. My basic approach is to combine an attractive potential with an iterative constraint projection method inspired by [8]. This scheme involves treating the membrane as a set of particles and a corresponding set of constraint functions, which in this case are distance constraints that enforce the geometry of the mesh. At each time step particles move to new configurations that may violate the constraint functions; these violations are detected and a small correction factor to the particle's position is computed and iteratively applied via the Gauss-Seidel method (with an optional stiffness parameter) until the system reaches a new configuration that satisfies the constraints. [8] Although this method is primarily intended for resolving elastic deformations, it's useful in this context as it's stable and it conserves energy and momentum. This method should make the mesh more elastic, which should allow the short range forces to prevail near the transition. Computing the phase diagram, critical exponents, and radius of gyration should give an indication of the suitability of such a model. 

---

[1] Paczuski, Kardar, Nelson, "Landau Theory of the Crumpling Transition", Physical Review Letters 2638-2640 (1988)

[3] the statistical mechanics of membranes

[4] P.G. de Gennes, Scaling Concepts in Polymers Physics, Cornell University Press, Thaca, NY, 1979. 

[5] K.J. Wiese, F. David, "New Renormalization Group Results for Scaling of Self-Avoiding Membranes", Nucl. Phys. B, 487:529, 1997

[6] G. Gompper, D. M. Kroll, "Fluctuations of polymerized, fluid and hexatic membranes: continuum models and simulations", Current Opinion in Colloid & Interface Science, 1997.

[71] abraham, nelson, fluctuations in the flat and collapsed phase of polymerized surfaces

[8] Muller

