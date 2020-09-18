
// Compare the fluid and solid time-scales
scalar maxCoByMaxDi = CoNum/(DiNum + SMALL);

// Compute a solid time-step as a multiple of the fluid time-step
scalar deltaTSolid = maxCoByMaxDi*runTime.deltaT().value();

Info << "Co_max/Di_max: " << maxCoByMaxDi << nl
     << "deltaTSolid:   " << deltaTSolid << nl << endl;
