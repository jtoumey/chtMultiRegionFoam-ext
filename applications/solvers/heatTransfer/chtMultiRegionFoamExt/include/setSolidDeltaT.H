
scalar maxCoByMaxDi = CoNum/(DiNum + SMALL);

scalar deltaTSolid = maxCoByMaxDi*runTime.deltaT().value();

solidSolutionTime = runTime.value();

Info << "Co_max/Di_max: " << maxCoByMaxDi << nl
     << "deltaTSolid:   " << deltaTSolid << nl << endl;
