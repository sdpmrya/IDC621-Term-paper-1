# SIRS model

> Primary code is on SIRS.cpp \
> 'Plotting and analysis.ipynb' has the plots

## Parameters
- tau_l : The point on the grid is infected when the value of $\tau$ is between 1 and tau_l.
- tau_max : The point is recovering when the value is between tau_l and tau_max.
- N : No of grid points in one dimension.



## Variation in tau_l:
Varying the value of tau_l while keeping the initial condiitons and tau_max same. tau_l quantifies the time it takes for an infected person to recover.

- Initial conditions \
Susceptible cells : 9900 \
Infected cells : 69 \
Recovering cells : 31

> tau_l = 1 

![Alt text](pics/time_evol_tau_l=1.png)

> tau_l = 2 

![Alt text](pics/time_evol_tau_l=2.png)

> tau_l = 3 

![Alt text](pics/time_evol_tau_l=3.png)

> tau_l = 4

![Alt text](pics/time_evol_tau_l=4.png)

> tau_l = 5

![Alt text](pics/time_evol_tau_l=5.png)

> tau_l = 6

![Alt text](pics/time_evol_tau_l=6.png)

> tau_l = 7

![Alt text](pics/time_evol_tau_l=7.png)

> tau_l = 8

![Alt text](pics/time_evol_tau_l=8.png)

> tau_l = 9

![Alt text](pics/time_evol_tau_l=9.png)

### tau_l vs infected cells at equilibrium

The general trend is that at equilibrium, the number of infected cells is increasing. This can be shown from the following plot.