def factos(num):
    if isinstance(num,int):
        result=1
        while num!=0:
            result=result*num
            num-=1
        return result
    else:
        return "error"
    
print(factos(5))