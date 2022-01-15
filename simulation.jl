using Molly

temp = 298u"K"
atoms, atoms_data, specific_inter_lists, general_inters, neighbor_finder, coords, box_size = readinputs(
            joinpath(dirname(pathof(Molly)), "..", "data", "5XER", "gmx_top_ff.top"),
            joinpath(dirname(pathof(Molly)), "..", "data", "5XER", "gmx_coords.gro"))
simulator = VelocityVerlet(dt=0.0002u"ps", coupling=AndersenThermostat(temp, 1.0u"ps"))

sys = System(
    atoms=atoms,
    atoms_data=atoms_data,
    general_inters=general_inters,
    specific_inter_lists=specific_inter_lists,
    coords=coords,
    velocities=[velocity(a.mass, temp) for a in atoms],
    box_size=box_size,
    neighbor_finder=neighbor_finder,
    loggers=Dict("temp" => TemperatureLogger(10),
                    "writer" => StructureWriter(10, "traj_5XER_1ps.pdb")),
)

simulate!(sys, simulator, 5_000)
