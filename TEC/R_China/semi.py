def auxsemi(mat,i,j,rf,result):
    if i==len(mat):
        return True
    else:
        if j==len(mat[0]):
            if i==0:
                return auxsemi(mat,i+1,0,0,rf)
            else:
                if rf==result:
                    return auxsemi(mat,i+1,0,0,rf)
                else:
                    return False
        else:
            return auxsemi(mat,i,j+1,rf+mat[i][j],result)
        


def semi(mat):
    if isinstance(mat,list) and isinstance(mat[0],list):
        return auxsemi(mat,0,0,0,0)

print(semi([[6,2,1],[5,4,0],[4,4,1]]))