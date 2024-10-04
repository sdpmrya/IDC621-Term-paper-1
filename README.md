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

<img src="pics/time_evol_tau_l=1.png" alt="drawing" width="400"/>

> tau_l = 2 

<img src="pics/time_evol_tau_l=2.png" alt="drawing" width="400"/>

> tau_l = 3 

<img src="pics/time_evol_tau_l=3.png" alt="drawing" width="400"/>

> tau_l = 4

<img src="pics/time_evol_tau_l=4.png" alt="drawing" width="400"/>

> tau_l = 5

<img src="pics/time_evol_tau_l=5.png" alt="drawing" width="400"/>

> tau_l = 6

<img src="pics/time_evol_tau_l=6.png" alt="drawing" width="400"/>

> tau_l = 7

<img src="pics/time_evol_tau_l=7.png" alt="drawing" width="400"/>

> tau_l = 8

<img src="pics/time_evol_tau_l=8.png" alt="drawing" width="400"/>

> tau_l = 9

<img src="pics/time_evol_tau_l=9.png" alt="drawing" width="400"/>

### tau_l vs no of cells at equilibrium

The general trend is that at equilibrium, the number of infected cells is increasing. This can be shown from the following plot.

<img src="pics/tau_l_vs_no_of_cells.png" alt="drawing" width="400"/>