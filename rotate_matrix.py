import numpy as np
def rotate(mat):
    n = len(mat)
    for layer in range(n//2):
        first = layer
        last = n-1-layer
        for i in range(first,last):
            offset = i - first
            top = mat[first][i]
            mat[first][i] = mat[last-offset][first]
            mat[last-offset][first] = mat[last][last-offset]
            mat[last][last-offset] = mat[i][last]
            mat[i][last] = top
    return mat




mat = [[1,2,3,4],
       [5,6,7,8],
       [9,10,11,12],
       [13,14,15,16]]


for i in mat:
    print(i)
print('\n')
rotate(mat)
for i in mat:
    print(i)