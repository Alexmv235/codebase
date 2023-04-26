def mat1(A,B):
    if isinstance(A,list) and isinstance(B,list) and isinstance(A[0],list) and isinstance(B[0],list) and len(A)==len(B) and len(A[0])==len(B[0]):
        return auxmat(A,B,0,0,[],[])

def auxmat(v,w,i,j,rfila,result):
    if i==len(v):
        return result
    else:
        if j==len(v[i]):
            return auxmat(v,w,i+1,0,[],result+[rfila])
        else:
            return auxmat(v,w,i,j+1,rfila+[v[i][j]+w[i][j]],result)


print(mat1([[3,2,11],[5,6,3]],[[2,9,10],[8,11,15]]))

