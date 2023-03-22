def clasificar(lista):
    if isinstance(lista,list):
        return c_aux()
    else:
        "error"

def c_aux(lista):
    if lista==[]:
        return []
    elif lista[0][0].lower()=="M":
        print("yey")
        return c_aux(lista[1:])
    else:
        return c_aux(lista[1:])

print(clasificar(["M-43","F-23","F-48","F-31","M-65","M-18","M-48"]))