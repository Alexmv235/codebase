def hay_cero(num):
    if isinstance(num,int):
        num=abs(num)
        if num!=0:
            while num!=0:
                if num%10==0:
                    return True
                else:
                    num//=10
            return False
        else:
            return True
    else:
        return "erorr"
    

print(hay_cero(1))