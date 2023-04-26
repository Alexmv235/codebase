def maTreanspuesta(mat):
    if isinstance(mat,list) and isinstance(mat[0],list):
        return auxt(mat,0,0,[],[])


def auxt(mat,i,j,rfila,result):
    if j==len(mat[0]):
        return result
    else:
        if i==len(mat):
            return auxt(mat,0,j+1,[],result+[rfila])
        else:
             return auxt(mat,i+1,j,rfila+[mat[i][j]],result) 

print(mTr)