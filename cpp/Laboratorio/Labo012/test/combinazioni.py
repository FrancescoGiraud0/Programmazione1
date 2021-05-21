# CREAZIONE DI FILE DI TEST CON COMBINAZIONI NUMERI ROMANI
import itertools
import random
import re

MAX = 50
cnt_r, cnt_nr = 0, 0

items = 'MMMMMCCCCCXXXXXIIIIIDDLLVV'
pattern = '^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$' # fonte: StackOverflow
romani = []
nonromani = []

while cnt_r<MAX or cnt_nr<MAX:
    i=1
    while i<=15:
        comb = random.sample( set(itertools.combinations(items, i)), 7)

        for c in comb:
            cs = ''.join(c)
            if re.search(pattern, cs) and cnt_r<MAX and (cs not in romani):
                romani.append(cs)
                cnt_r+=1
            elif cnt_nr<MAX and (cs not in nonromani):
                nonromani.append(cs)
                cnt_nr+=1
        
        i+=1

print(len(romani), len(nonromani))

for c in romani:
    print(c)

for c in nonromani:
    print(c)
