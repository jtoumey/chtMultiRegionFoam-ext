# chtMultiRegionFoam-ext
Modifications to the stock `chtMultiRegionFoam` heat transfer solver to suit CTF lab purposes. 

## Modifications
1. **Multi-time-stepping:** To address the time-scale disparities between solid- and fluid-phase heat transfer, calculate a scaling factor based on the ratio of Courant number to Diffusion number and use this to scale the fluid time-step. Use this scale time-step as the solid time-step; solve the solid-phase heat transfer only after this time-step has elapsed since the previous solve.

2. Reacting flows. 
