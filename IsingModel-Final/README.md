Main goal of this project are analyze code and lower computation time.
According to the analysis of the code, the most time consuming function is do_step()function.
This function called in three different for loop in code. In my implementation the for loops where do_step function called
defined parallel loop that does not  have shared resources.
That gives us more time consuming do_step() function because of unshared resources. But at the end of results,
we are seeing all computation lower 30 min to 18 min(computation error increase in parallel version due to some resources).
There is two output file in ./source with L=16 value runned at Intel® Core™ i7-4510U Processor for parallel and sequantial.
When look at the time results in files. In parallel implementation, do_step() function consumes avarage 64 sec while sequantial do_step() consumes avarage 27 sec.
But in paralel version four(num_threads(4)) do_step function runs same time and finish. So parallel implementation finish fast.



Original code ::https://github.com/VictorSeven/IsingModel
# IsingModel

A classic implementation of the famous 2D Ising Model, written in C++. This was done as a project for *Cooperative and Critical Phenomena*, a subject for the Master in Physics of Complex Systems offered by the Institute of Cross-Disciplinary Physics and Complex Systems. The code is mostly based in the implementation by Raul Toral in his book *Stochastic Numerical Methods: an Introduction for Students and Scientists.*

The Ising Model is a model for a ferromagnetic - paramagnetic transition in magnetic materials, which has been studied as a reference model for phase transitions. It is formed by spins up or down, which can interact. Spins tend to align, but temperature makes them flip. However, in the stationary distribution the statistical properties of the ensable are fixed. 
For example, this is how the material looks at the critical point in a space of size 512x512:

![Ising 512](https://github.com/VictorSeven/IsingModel/blob/master/images/config512.png "Ising 512")

The program computes the magnetization, susceptibility, energy and specific heat in the stationary state. Far away the critical point, the Metropolis algorithm was used to reach this state. Near the critical temperature, we change to Wolff collective to do it in a fast way. Once we are in the stationary state, we take several measures, updating enough steps between measurements in order to avoid statistical correlations. In the next graph you can see the observables, for several system sizes:

![Ising](https://github.com/VictorSeven/IsingModel/blob/master/images/observ.png "Ising Observables")

The next step is to compute critical temperature, as well as critical exponents. For the critical temperature, Binder cumulant is used. This quantity is constant exactly at the critical point, so we try to compute where all the graphs, for different sizes, converge. In practice, we take pairs and make an average:

![Binder](https://github.com/VictorSeven/IsingModel/blob/master/images/binder.png "Binder Cumulant")

Finally, once all the temperature and the critical exponents have been computed, we can check the scaling function. The result is pretty beautiful, and it possible to see the collapse of all the sizes near the critical points:

![Binder](https://github.com/VictorSeven/IsingModel/blob/master/images/scaling.png "Binder Cumulant")

The C++ code may be not very readable, and the program takes time to do all the measurements. However, I hope you find it a useful reference: it is pretty well optimized, and all the errors are carefully computed. 






