def ispermutation(s1,s2):
    if(len(s1) != len(s2)):
        return False
    d1 = {}
    for i in s1:
        d1[i] = d1.get(i,0) + 1

    for i in s2:
        d1[i] = d1.get(i,0) - 1
        if(d1[i]<0):
            return False
    return True



s1 = 'aabcd'
s2 = 'cdbaa'
print(ispermutation(s1,s2))
