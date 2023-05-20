def power(base,exp):
    i=1
    result=1
    while i<=exp:
        result*=base
        i+=1
    return result

print(power(2,4))
