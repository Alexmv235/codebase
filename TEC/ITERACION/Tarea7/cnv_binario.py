def convertir_binario(num):
    if isinstance(num,(int,float)):
        result=0
        i=0
        while num!=0:
            result+=num%10*(2**i)
            num//=10
            i+=1
        return result
    else:
        return "error"
    
print(
    convertir_binario(0)
)