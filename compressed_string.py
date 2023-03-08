#compressed string 

def compressed(s):
    comps = ''
    i = 0
    counter = 1
    while(i<len(s)):
        j = i
        counter = 1
        while(j+1<len(s) and s[j]==s[j+1]):
            counter += 1
            j += 1
        i = j+1
        comps += s[j]+str(counter)
    if(len(comps)>len(s)):
        return s
    return comps

s = 'aabcccccaaa'
print(compressed(s))
