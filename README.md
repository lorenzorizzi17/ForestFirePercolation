A simple model of a spreading fire in a forest using percolation theory. The trees can occupy a fixed portion of land in a 2D grid with probability $p$: if two or more trees are neighbouring,
the fire can spread throught the forest. The parameter $p$ behaves as a _control parameter_: for a certain critical probability $p_{c} \approx 0.6$, the percolation theory predicts the formation of a 
percolating cluster that expands through the whole lattice

For $p = 0.7$, the fire spreads easily and rapidly and the giant cluster covers pretty much all of the forest:


![p = 0 7](https://github.com/lorenzorizzi17/ForestFirePercolation/assets/102590961/5d463f1a-82ca-400b-9233-26fe420971e4)


For $p = 0.6 \approx p_{c}$, the percolating cluster shows up. The fire spreads, but takes more time due to the percolating cluster being quite ramified:



![p=0 6](https://github.com/lorenzorizzi17/ForestFirePercolation/assets/102590961/e3e754ac-7c31-48b2-80be-c505b44f00e3)


For $p = 0.5$, every cluster is finite in size and the fire cannot reach the bottom of the simulation:


![p = 0 5](https://github.com/lorenzorizzi17/ForestFirePercolation/assets/102590961/1f171202-7244-45ea-b564-fe60d12b1c17)

One can plot the time it takes for the fire to spread versus the control parameter $p$, obtaining something like:


![FirePercolation](https://github.com/lorenzorizzi17/ForestFirePercolation/assets/102590961/6562e850-093f-49c6-a08c-aa2e47e24e64)

The lifetime of the fire increases rapidly when the system approaches the critical point (for $p>p_{c}$, the percolating path is very big and the fire spreads rapidly burning all of the trees
whereas for $p \leq p_{c}$ the fire stops the cluster are not connected enough)
