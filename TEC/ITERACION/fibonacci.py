def fib(num):
    if isinstance(num,int):
        num=abs(num)
        i=0
        result=0
        a=0
        b=1
        while i<=num:
            if i>=2:
                result=a+b
                a=b
                b=result
            i+=1
        return result
        
print(fib(12))

