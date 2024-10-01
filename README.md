# SIRS model

> Primary code is on SIRS.cpp \
> 'Plotting and analysis.ipynb' has the plots

## Parameters
- tau_l : The point on the grid is infected when the value of $\tau$ is between 1 and tau_l.
- tau_max : The point is recovering when the value is between tau_l and tau_max.
- N : No of grid points in one dimension.

![alt text](pics/image.png)

0 : susceptible
1-4 : Infected
5-7 : recovering

## variables
curr

#### Von Neumann neighbourhood is used 
![alt text](pics/image-2.png)

## Functions used:-

### Initialization(Point* points)
assigns random values for the tau in the data. 

### nonneuman(Point* points)
updates the left, top, right and bottom 

### update(Point* points)


### main function
Initialize pointer vector points using new keyword
