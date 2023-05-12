def mag(A):
    result=True
    suma=0
    temp=0
    for i in range(len(A)):
        for j in range(len(A[i])):
            suma+=A[i][j]
        if temp==0:
            temp=suma
        elif temp!= suma:
            result=False
            break
        suma=0
    return result

print(
    mag([[1, 2, 3],
         [3, 2, 1],
         [2, 3, 1]]))