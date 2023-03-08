def makehappen(x,y):
    ls = []
    cond = True
    all_found = True
    while(len(y) != 0):
        if(cond == False):
            break
        word = y.pop()
        for i in range(len(x)):
            if(x[i] == word[0]):
                if(word == x[i:i+len(word)]):
                    ls.append(word)
                    break
                else:
                    continue
            if(i==len(x)-1):
                cond = False
                all_found = False
                break

    if(all_found == False): return None
    #if all_found == False end here
    ex = dict()
    fin = dict()
    for i in range(len(ls)):
        for j in range(len(x)):
            if(ls[i] == x[j:j+len(ls[i])]):
                ex[ls[i]] = j

    ex2 = {k:v  for k,v in sorted(ex.items(), key = lambda item:item[1])}

    ans = []
    for i in ex2.keys():
        ans.append(i)
    return ans




s1 = "thequickbrownfox"
set_s1 = {'quick','brown','the','fox'}

s2 = 'bedbathandbeyond'
set_s2 = {'bed','bath','and','beyond'}

s3 = 'doginthehouse'
set_s3 = {'in','the','dog','kennel'}

ls = makehappen(s3,set_s3)

print(ls)










