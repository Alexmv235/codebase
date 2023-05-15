def convertir_binario(num):
    result=0
    i=0
    j=1
    k=1
    if isinstance(num,int):
        while num!=0:
            if num%10 ==1 or num%10 ==0:
                result+=num%10*(2**i)
                num//=10
                i+=1
            else:
                return "error, no es binario"
        return result
    elif isinstance(num,float):
        entero=num//1
        decimales=num-entero/1
        while entero!=0:
            if entero%10 ==1 or entero%10 ==0:
                result+=entero%10*(2**i)
                entero//=10
                i+=1
            else:
                return "error, no es binario"
        while decimales!=0 and k<4:
            decimales*=10
            dig=(decimales%10)//1
            if dig ==1 or dig ==0:
                result+=(dig/(2**j))
                decimales-dig
                j+=1
                k+=1
            else:
                return "error, hay un decimal no binario"
        return result
        
    else:
        return "error"
    
print(
    convertir_binario(1010.10101)
)