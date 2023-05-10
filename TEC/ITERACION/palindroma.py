def pal(sting):
    if isinstance(sting,str):
        result=True
        while sting!='':
            if sting[0]==sting[-1]:
                sting=sting[1:-1]
            else:
                result=False
                break
        return result
    
def palindromo(sting):
    if isinstance(sting,str):
        i=1
        for e in sting:
            if e==sting[-i]:
                i+=1
            else:
                return False
        return True
    
print(pal("hooh"))
