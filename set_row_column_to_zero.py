#if any element is 0, set the corresp row and column to 0

mat = [[1,2,3,4],
       [5,0,7,8],
       [9,10,0,12],
       [13,14,15,16]]

n = len(mat)
m = len(mat[0])
s1 = set()

for i in range(n):
       for j in range(m):
              if(mat[i][j] == 0):
                     s1.add((i,j))

while(s1):
       i1,i2 = s1.pop()
       for i in range(n):
              mat[i][i2] = 0
       for i in range(m):
              mat[i1][i] = 0

for i in mat:
       print(i)



