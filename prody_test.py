from prody import *
1cka = parsePDB('1cka')
1gbq = parsePDB('1gbq')

1cka.select('resname TRP name CA CB NE1 CZ3')
