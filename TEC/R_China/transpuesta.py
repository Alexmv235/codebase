


def auxt(mat,i,j,rfila,result):
    if j==len(mat[0]):
        return result
    else:
        if i==len(mat):
            return auxt(mat,0,j+1,[],result+[rfila])
        else:
             return auxt(mat,i+1,j,rfila+[mat[i][j]],result) 

A=[[3,2,11],[5,6,3]]
print(auxt(A,0,0,[],[]))