{
    volScalarField& he = thermo.he();

    fvScalarMatrix EEqn
    (
        fvm::ddt(rho, he) + fvm::div(phi, he)
      + fvc::ddt(rho, K) + fvc::div(phi, K)
      + (
            he.name() == "e"
          ? fvc::div
            (
                fvc::absolute(phi/fvc::interpolate(rho), U),
                p,
                "div(phiv,p)"
            )
          : -dpdt
        )
      - fvm::laplacian(turb.alphaEff(), he)
     ==
        rho*(U&g)
      + rad.Sh(thermo, he)
      + fvOptions(rho, he)
    );

    EEqn.relax();

    fvOptions.constrain(EEqn);

    solvPerfE = EEqn.solve(mesh.solver(he.select(finalIter)));

    fvOptions.correct(he);

    thermo.correct();
    rad.correct();

    Info<< "Min/max T:" << min(thermo.T()).value() << ' '
        << max(thermo.T()).value() << endl;
    Info<< "Min/max alphaEff:" << min(turb.alphaEff()).value() << ' '
        << max(turb.alphaEff()).value() << endl;
    Info<< "Min/max kappa:" << min(thermo.kappa()).value() << ' '
        << max(thermo.kappa()).value() << endl;
}
