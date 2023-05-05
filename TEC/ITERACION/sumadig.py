def sumadig(num):
    if isinstance (num,int):
        num=abs(num)
        result=0
        while num!=0:
            result += num%10
            num //=10
        return result
    else:
        return "error"
    
print(sumadig(123))