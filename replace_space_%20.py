#replace all spaces with %20

s = 'Mr John Smith    '
# s = 'a b c    '
norg = len(s)
i = len(s)-1
nsp = 0
while(s[i] == ' '):
    nsp += 1
    i -= 1
nact = norg - nsp

ls = list(s)

for i in range(nact-1,-1,-1):
    if(s[i] == ' '):
        ls[norg-1] = '0'
        ls[norg-2] = '2'
        ls[norg-3] = '%'
        norg = norg-3
    else:
        ls[norg-1] = s[i]
        norg = norg -1

res = ''
for i in ls:
    res += i
print(res)



