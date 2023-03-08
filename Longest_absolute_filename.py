input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"

text = input.split('\n')
dmap = {0:0}
maxlength = 0
for words in text:
    word = words.split('\t')[-1]
    depth = len(words) - len(word)
    if('.' in word):
        maxlength = max(maxlength,dmap[depth]+len(word))
    else:
        dmap[depth+1] = dmap[depth]+len(word) + 1

print(maxlength)

