# run click for each segment/pdb with all dataset pdb files
def click4all(input_pdb1, input_pdb2):
    cmd= './click '+input_pdb1+' '+input_pdb2+''
    os.system(cmd)


# Files generated after carving and renaming
renamed_pdb = glob.glob('*_rnmd.pdb')
dataset_renamed_file = glob.glob('*_rnmd_ds.pdb')


# After look up is done, run click
for re_file in renamed_pdb:
    #if re_file[0:4] == str(input_pdb_given):
    for dataset_file in dataset_renamed_file:
        click4all(re_file, dataset_file)
