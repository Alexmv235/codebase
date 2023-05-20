def geo(num):
    result=0
    i=1
    while i<=num:
        result+=1/i
        i+=1
    return result

print(geo(3))