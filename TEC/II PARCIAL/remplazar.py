def remplazar(string):
    if isinstance(string,str):
        return rempaux(string,0,"")
    else:
        return "erorr"

def rempaux(string,i,result):
    if i==len(string):
        return result
    else:
        if i==0:
            return rempaux(string,i+1,result+string[i])
        elif string[i-1]==string[i]:
            return rempaux(string,i+1,result)
        else:
            return rempaux(string,i+1,result+string[i])
